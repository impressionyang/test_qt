#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <string>
#include "calculator.h"

using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void doClick(bool);
    void on_btn_del_clicked();
    void on_btn_0_clicked();
    void on_btn_dot_clicked();
    void on_btn_result_clicked();
    void on_btn_1_clicked();
    void on_btn_2_clicked();
    void on_btn_3_clicked();
    void on_btn_add_clicked();
    void on_btn_4_clicked();
    void on_btn_5_clicked();
    void on_btn_6_clicked();
    void on_btn_diffrent_clicked();
    void on_btn_7_clicked();
    void on_btn_8_clicked();
    void on_btn_9_clicked();
    void on_btn_div_clicked();
    void on_btn_clear_clicked();
    void on_btn_left_con_clicked();
    void on_btn_right_con_clicked();
    void on_btn_multi_clicked();

private:
    Ui::Widget *ui;
    void initIcons();
    QPushButton *sender;
    string formula;
    void setLine(string line_str);
    Calculator cal;
};

#endif // WIDGET_H
