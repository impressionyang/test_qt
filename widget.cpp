#include "widget.h"
#include "ui_widget.h"
#include <QObject>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initIcons();
    formula="";


}

Widget::~Widget()
{
    delete ui;
}

void Widget::setLine(string line_str){
    ui->lineEdit->setText(QString::fromStdString(line_str));
}


void Widget::initIcons(){

}

void Widget::doClick(bool check){
    qDebug()<< sender->text();
    setLine(formula);
}

void Widget::on_btn_del_clicked()
{
    if(!formula.empty()){
        formula.erase(formula.length()-1);
        setLine(formula);
    }

}

void Widget::on_btn_0_clicked()
{
    formula.append("0");
    setLine(formula);
}

void Widget::on_btn_dot_clicked()
{
    formula.append(".");
    setLine(formula);
}

void Widget::on_btn_result_clicked()
{
    formula.append("#");
    QString temp=QString::number(cal.get_result(formula),10,4);
    formula=temp.toStdString();
    ui->lineEdit->setText(QString::fromStdString(formula));
}

void Widget::on_btn_1_clicked()
{
    formula.append("1");
    setLine(formula);
}

void Widget::on_btn_2_clicked()
{
    formula.append("2");
    setLine(formula);
}

void Widget::on_btn_3_clicked()
{
    formula.append("3");
    setLine(formula);
}

void Widget::on_btn_add_clicked()
{
    formula.append("+");
    setLine(formula);
}

void Widget::on_btn_4_clicked()
{
    formula.append("4");
    setLine(formula);
}

void Widget::on_btn_5_clicked()
{
    formula.append("5");
    setLine(formula);
}

void Widget::on_btn_6_clicked()
{
    formula.append("6");
    setLine(formula);
}

void Widget::on_btn_diffrent_clicked()
{
    formula.append("-");
    setLine(formula);
}

void Widget::on_btn_7_clicked()
{
    formula.append("7");
    setLine(formula);
}

void Widget::on_btn_8_clicked()
{
    formula.append("8");
    setLine(formula);
}

void Widget::on_btn_9_clicked()
{
    formula.append("9");
    setLine(formula);
}

void Widget::on_btn_div_clicked()
{
    formula.append("/");
    setLine(formula);
}

void Widget::on_btn_clear_clicked()
{
    formula.erase();
    setLine(formula);
}

void Widget::on_btn_left_con_clicked()
{
    formula.append("(");
    setLine(formula);
}

void Widget::on_btn_right_con_clicked()
{
    formula.append(")");
    setLine(formula);
}

void Widget::on_btn_multi_clicked()
{
    formula.append("*");
    setLine(formula);
}
