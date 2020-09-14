#ifndef FORM_MAINFORM_H
#define FORM_MAINFORM_H

#include <QWidget>

namespace Ui {
class Form_MainForm;
}

class Form_MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit Form_MainForm(QWidget *parent = nullptr);
    ~Form_MainForm();

private slots:
    void on_Button_Sample_pressed();

private:
    Ui::Form_MainForm *ui;
};

#endif // FORM_MAINFORM_H
