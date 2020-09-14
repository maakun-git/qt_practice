#include "Form_MainForm.h"
#include "ui_Form_MainForm.h"

Form_MainForm::Form_MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_MainForm)
{
    ui->setupUi(this);
}

Form_MainForm::~Form_MainForm()
{
    delete ui;
}

void Form_MainForm::on_Button_Sample_pressed()
{

}
