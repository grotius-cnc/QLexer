#ifndef QLEXER_H
#define QLEXER_H

#include "QTextEdit"
#include "markdownhighlighter.h"

class QLexer : public QTextEdit
{
    Q_OBJECT
public:
    explicit QLexer(QWidget *parent = nullptr);

private:
     MarkdownHighlighter *highlighter;
};

#endif // QLEXER_H
