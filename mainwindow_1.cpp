#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "content.h"
#include "dealfile.h"
#include "handlecontent.h"
#include "search.h"
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showYearData();
}

void MainWindow::showYearData()
{
    header<<"年度编号"<<"投入资金( 万元 )"<<"负责人"<<"申报项目数目"<<"实际支持项目数目"<<"结题项目数目"<<"计划开始时间"<<"计划结束时间";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setRowCount(3);
    Year *year=mallocYear(year);
    FILE *pfile=fopen("d://test_2.txt","r");
    readFile(year, pfile);
    int columnPosition=0;


    while (year!=NULL) {

        ui->tableWidget->setItem(columnPosition,0,new QTableWidgetItem(year->yearNum));
        ui->tableWidget->setItem(columnPosition, 1, new QTableWidgetItem(QString::number(year->yearMoney,10,6)));
        ui->tableWidget->setItem(columnPosition,2, new QTableWidgetItem(year->yearHostPerson));
        ui->tableWidget->setItem(columnPosition,3, new QTableWidgetItem(QString::number(year->applyProjectNum)));
        ui->tableWidget->setItem(columnPosition,4, new QTableWidgetItem(QString::number(year->actProjectNum)));
        ui->tableWidget->setItem(columnPosition, 5, new QTableWidgetItem(QString::number(year->endProjectNum)));
        ui->tableWidget->setItem(columnPosition,6,new QTableWidgetItem(QString::number(year->startTime)));
        ui->tableWidget->setItem(columnPosition, 7,new QTableWidgetItem(QString::number(year->endTime)));
        columnPosition++;
        year=year->nextYear;
    }

}

void MainWindow::showPersonData(Person *person)
{
    header.clear();
    header<<"学号"<<"姓名"<<"年龄"<<"类别"<<"学校及专业"<<"班级"<<"本人特长"<<"承担任务"<<"联系电话"<<"项目成员排名";
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int columnPosition=0;
    while(person!=NULL){
        ui->tableWidget->setItem(columnPosition,0,new QTableWidgetItem(person->personID));
        ui->tableWidget->setItem(columnPosition,1,new QTableWidgetItem(person->personName));
        ui->tableWidget->setItem(columnPosition,2,new QTableWidgetItem(QString::number(person->age)));
        switch (person->personType) {
        case 0:
            personType="本科生";
            break;
        case 1:
            personType="研究生";
            break;
        case 2:
            personType="博士生";
            break;
        case 3:
            personType="指导教师";
            break;
        default:
            break;
        }
        ui->tableWidget->setItem(columnPosition,3,new QTableWidgetItem(personType));
        ui->tableWidget->setItem(columnPosition,4,new QTableWidgetItem(person->major));
        ui->tableWidget->setItem(columnPosition,5,new QTableWidgetItem(person->classRoom));
        ui->tableWidget->setItem(columnPosition,6,new QTableWidgetItem(person->skill));
        ui->tableWidget->setItem(columnPosition,7,new QTableWidgetItem(person->task));
        ui->tableWidget->setItem(columnPosition,8,new QTableWidgetItem(person->tel));
        ui->tableWidget->setItem(columnPosition,9,new QTableWidgetItem(QString::number(person->personRank)));
    }

}

void MainWindow::showProjectData(Project *project)
{
    header.clear();
    header<<"项目编号"<<"项目名称"<<"经费数"<<"参与人数"<<"立项时间"<<"结题时间"<<"完成评价"<<"负责人"<<"负责人电话"<<"成果形式"<<"成果名称";
    ui->tableWidget->setColumnCount(11);
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    int columnPosition=0;
    while (project!=NULL) {
        ui->tableWidget->setItem(columnPositon,0,new QTableWidgetItem(project->projectNum));
        ui->tableWidget->setItem(columnPositon,1,new QTableWidgetItem(project->projectName));
        ui->tableWidget->setItem(columnPositon,2,new QTableWidgetItem(QString::number(project->projectMoney,10,6)));
        ui->tableWidget->setItem(columnPositon,3,new QTableWidgetItem(QString::number(project->personNum)));
        ui->tableWidget->setItem(columnPositon,4,new QTableWidgetItem(QString::number(project->projectStartTime)));
        ui->tableWidget->setItem(columnPositon,5,new QTableWidgetItem(QString::number(project->projectEndTime)));

        switch (project->rank) {
        case 0:
            rank="优";
            break;
        case 1:
            rank="良";
            break;
        case 2:
            rank="及格";
            break;
        case 3:
            rank="未完成";
            break;
        default:
            break;
        }

        ui->tableWidget->setItem(columnPositon,6,new QTableWidgetItem(rank));
        ui->tableWidget->setItem(columnPositon,7,new QTableWidgetItem(project->projectHostPerson));
        ui->tableWidget->setItem(columnPositon,8,new QTableWidgetItem(project->projectHostPersonTel));

        switch (project->achiveType) {
        case 0:
            achiveType="软件";
            break;
        case 1:
            achiveType="论文";
            break;
        case 2:
            achiveType="产品";
            break;
        case 3:
            achiveType="其它";
            break;
        default:
            break;
        }

        ui->tableWidget->setItem(columnPositon,9,new QTableWidgetItem(achiveType));
        ui->tableWidget->setItem(columnPositon,10,new QTableWidgetItem(project->achiveName));

        columnPosition++;
        project=project->nextProject;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getProject(Project *)
{

}
