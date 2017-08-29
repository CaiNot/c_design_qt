#include "dialogtoinsert.h"
#include "ui_dialogtoinsert.h"

DialogToInsert::DialogToInsert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogToInsert)
{
    ui->setupUi(this);
}

void DialogToInsert::getYear()
{
    ui->label_1->setText("年度计划编号");
    ui->label_2->setText("资金(万元)");
    ui->label_3->setText("年度计划负责人");
    ui->label_4->setText("申请项目数");
    ui->label_5->setText("实际通过项目数");
    ui->label_6->setText("结束项目数");
    ui->label_7->setText("年度开始时间");
    ui->label_8->setText("年度结束时间");
    ui->lineEdit_9->setDisabled(true);
    ui->lineEdit_10->setDisabled(true);
    ui->lineEdit_11->setDisabled(true);
}

void DialogToInsert::getProject()
{
    ui->label_1->setText("项目编号");
    ui->label_2->setText("项目名称");
    ui->label_3->setText("项目资金");
    ui->label_4->setText("项目人员数目");
    ui->label_5->setText("项目开始时间");
    ui->label_6->setText("项目结束时间");
    ui->label_7->setText("项目评级");
    ui->label_8->setText("项目负责人");
    ui->label_9->setText("项目负责人电话");
    ui->label_10->setText("项目成果类型");
    ui->label_11->setText("项目成果名称");
}

void DialogToInsert::getPerson()
{
    ui->label_1->setText("学号");
    ui->label_2->setText("姓名");
    ui->label_3->setText("年龄");
    ui->label_4->setText("身份");
    ui->label_5->setText("专业");
    ui->label_6->setText("班级");
    ui->label_7->setText("特长");
    ui->label_8->setText("任务");
    ui->label_9->setText("联系方式");
    ui->label_10->setText("参与度");
    ui->lineEdit_11->setDisabled(true);
}

char *DialogToInsert::getYearNum()
{
    QByteArray ba;

}

DialogToInsert::~DialogToInsert()
{
    delete ui;
}
