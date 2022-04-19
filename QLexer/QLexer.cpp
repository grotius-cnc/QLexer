#include "QLexer.h"

QLexer::QLexer(QWidget *parent) : QTextEdit(parent)
{
    highlighter = new MarkdownHighlighter(document());
    this->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
}
