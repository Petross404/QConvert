#include "qconvert.h"
#include "ui_qconvert.h"

QConvert::QConvert(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QConvert)
{
    ui->setupUi(this);
}

QConvert::~QConvert()
{
    delete ui;
}
