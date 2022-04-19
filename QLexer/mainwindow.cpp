#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLexer.h"

#include "markdownhighlighter.h"
//! For more info visit : https://github.com/pbek/qmarkdowntextedit

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

