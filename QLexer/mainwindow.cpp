#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLexer.h"

//! MarkDown, For more info visit : https://github.com/pbek/qmarkdowntextedit
#include "markdown/markdownhighlighter.h"

//! Token analyser, for more info visit : https://gist.github.com/LovelyBuggies/6dafc6f3ad6d27c17d8c0dd81d23a1b8
#include "tokenizer/TokenIzer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //! Loading QLexer outside the MainWindow like :
    //! QLexer *lexer = new QLexer();
    //! ui->gridLayout->addWidget(lexer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_get_the_tokens_pressed()
{
    //! From our current source file including the pictured documenation we create a text file.
    std::string theSource=ui->textEditCpp->toPlainText().toStdString();
    std::ofstream outfile;

    outfile.open("theSource.cpp", std::ios_base::out);
    outfile << theSource;
    outfile.close();

    //! This is how the text is saved from our source file.
    std::cout<<"The text:"<<theSource<<std::endl;

    //! Create tokens from the text.
    TokenIzer *theTokenIzer = new TokenIzer();
    theTokenIzer->getTokens("theSource.cpp","theTokenOutput.txt");
}

#include <stdio.h>
//! More info at : https://www.codeproject.com/articles/15971/using-inline-assembly-in-c-c
void MainWindow::on_pushButton_assembly_tour_pressed()
{
    int no = 100, val ;
        asm ("movl %1, %%ebx;"
             "movl %%ebx, %0;"
             : "=r" ( val )        /* output */
             : "r" ( no )         /* input */
             : "%ebx"         /* clobbered register */
         );
    std::cout<<"result:"<<val<<std::endl;
}









