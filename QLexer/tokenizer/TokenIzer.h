#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

class TokenIzer
{
public:
    TokenIzer(){};

    void getTokens(std::string filename_in, std::string filename_out){
        ifile.open(filename_in.c_str(), std::ios::in);
        ofile.open(filename_out.c_str(), std::ios::out);
        getToken();
        ifile.close();
        ofile.close();
    }

    void printToken(std::vector<int> token) {
        for (int i = 0; i < token.size(); i++) {
            std::cout << (char) token[i];
        }
        std::cout << std::endl;
    }


    void putVector(std::vector<int> token) {
        for (int i = 0; i < token.size(); i++) {
            ofile.put((char) token[i]);
        }
        ofile.put('\n');
    }


    std::vector<int> parseNumber(int start) {
        int number;
        std::vector<int> token (1, start);
        while (isdigit(ifile.peek())) {
            number = ifile.get();
            token.push_back(number);
        }
        return token;
    }


    bool isword(int inch) {
        if (isalnum(inch)) 		return true;
        else if (inch == '_') 	return true;
        else 					return false;
    }


    std::vector<int> parseWord(int start) {
        int word;
        std::vector<int> token (1, start);
        while (isword(ifile.peek())) {
            word = ifile.get();
            token.push_back(word);
        }
        return token;
    }


    std::vector<int> parseComment(int start) {
        int comment;
        std::vector<int> token (1, start);
        if (ifile.peek() == '/') {
            comment = ifile.get();
            token.push_back(comment);
            while ((comment = ifile.get()) != '\n') {
                token.push_back(comment);
            }
        } else if (ifile.peek() == '*') {
            comment = ifile.get();
            token.push_back(comment);
            PARSING_COMMENT: while ((comment = ifile.get()) != '*') {
                token.push_back(comment);
            }
            if (ifile.peek() == '/') {
                token.push_back(comment);
                comment = ifile.get();
                token.push_back(comment);
            } else {
                token.push_back(comment);
                goto PARSING_COMMENT;
            }
        }
        return token;
    }


    std::vector<int> parseSentence(int start) {
        int sentence;
        std::vector<int> token (1, start);
        PARSING_SENTENCE: while ((sentence = ifile.get()) != start) {
            token.push_back(sentence);
        }
        if (token.back() == '\\' && token[token.size() - 2] != '\\') {
            token.push_back(sentence);
            goto PARSING_SENTENCE;
        }
        token.push_back(sentence);
        return token;
    }


    void parse_error(std::string message, char ch) {
        std::cerr << message << ": " << (int) ch;
    }


    void getToken() {
        std::vector<int> token;
        int inch = 0;
        while ((inch = ifile.get()) != EOF) {
            token.clear();
            switch (inch) {
                case '\t':
                case '\n':
                case '\r':
                case ' ':
                    break;
                case '#':
                case '<':
                case '>':
                case '.':
                case ',':
                case '*':
                case '=':
                case '!':
                case '(':
                case ')':
                case '[':
                case ']':
                case '{':
                case '}':
                case ';':
                case '\\':
                    token.push_back(inch);
                    printToken(token);
                    putVector(token);
                    break;
                case '+':
                case '-':
                case ':':
                case '|':
                case '&':
                ///! the ```cpp ``` character was illegal.
                case '`':
                    token.push_back(inch);
                    if (ifile.peek() == inch) {
                        inch = ifile.get();
                        token.push_back(inch);
                    }
                    printToken(token);
                    putVector(token);
                    break;
                case '/':
                    token = parseComment(inch);
                    if (token.size() == 1) { printToken(token); }
                    else { token.clear(); continue; }
                    break;
                case '\'':
                case '\"':
                    token = parseSentence(inch);
                    printToken(token);
                    putVector(token);
                    break;
                default:
                    if (isdigit(inch)) {
                        token = parseNumber(inch);
                        printToken(token);
                        putVector(token);
                    } else if (isword(inch)) {
                        token = parseWord(inch);
                        printToken(token);
                        putVector(token);
                    } else {
                        parse_error("Illegal character", inch);
                    }
                    break;
            }
        }
    }

private:
    std::ifstream ifile;
    std::ofstream ofile;
};

#endif // TOKENIZER_H
