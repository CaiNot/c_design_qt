#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "content.h"
#include "dealfile.h"
#include "handlecontent.h"
#include "search.h"
#include "dialog.h"
#include <stdio.h>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    year=mallocYear(year);
    FILE *pfile=fopen("d://test_2.txt","r");
    readFile(year, pfile);
    yearHead=year;
    ui->showProjectBtn->setDisabled(true);
    ui->showPersonBtn->setDisabled(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setHidden(true);
    connect(ui->tableWidget->horizontalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(mySortByColumn(int)));
}

void MainWindow::showYearData(Year *year)
{
    ui->tableWidget->clear();
    header.clear();
    header<<"年度编号"<<"投入资金( 万元 )"<<"负责人"<<"申报项目数目"<<"实际支持项目数目"<<"结题项目数目"<<"计划开始时间"<<"计划结束时间";
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int columnPosition=0;


    while (year!=NULL) {

        ui->tableWidget->setItem(columnPosition,0,new QTableWidgetItem(year->yearNum));
        QTableWidgetItem *yearMoneyItem=new QTableWidgetItem();
        yearMoneyItem->setData(Qt::DisplayRole,year->yearMoney);
        ui->tableWidget->setItem(columnPosition, 1, yearMoneyItem);
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

void MainWindow::showYearData(YearGet *yearGet)
{
    Year *year=NULL;
    ui->tableWidget->clear();
    header.clear();
    header<<"年度编号"<<"投入资金( 万元 )"<<"负责人"<<"申报项目数目"<<"实际支持项目数目"<<"结题项目数目"<<"计划开始时间"<<"计划结束时间";
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int columnPosition=0;


    while (yearGet!=NULL) {
        year=yearGet->year;
        ui->tableWidget->setItem(columnPosition,0,new QTableWidgetItem(year->yearNum));
        QTableWidgetItem *yearMoneyItem=new QTableWidgetItem();
        yearMoneyItem->setData(Qt::DisplayRole,year->yearMoney);
        ui->tableWidget->setItem(columnPosition, 1, yearMoneyItem);
        ui->tableWidget->setItem(columnPosition,2, new QTableWidgetItem(year->yearHostPerson));
        ui->tableWidget->setItem(columnPosition,3, new QTableWidgetItem(QString::number(year->applyProjectNum)));
        ui->tableWidget->setItem(columnPosition,4, new QTableWidgetItem(QString::number(year->actProjectNum)));
        ui->tableWidget->setItem(columnPosition, 5, new QTableWidgetItem(QString::number(year->endProjectNum)));
        ui->tableWidget->setItem(columnPosition,6,new QTableWidgetItem(QString::number(year->startTime)));
        ui->tableWidget->setItem(columnPosition, 7,new QTableWidgetItem(QString::number(year->endTime)));
        columnPosition++;
        yearGet=yearGet->nextYearGet;
    }

}

void MainWindow::showPersonData(Person *person)
{
    ui->tableWidget->clear();
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
        columnPosition++;
        person=person->nextPerson;
    }

}

void MainWindow::searchByYearNumGUI()
{
    bool isOK;
    YearGet *yearGet=NULL;
    QString text = QInputDialog::getText(NULL,"SearchYearNum","输入年度计划的编号",QLineEdit::Normal,"",&isOK);
    if(isOK){
        QByteArray ba=text.toLatin1();
        yearGet=searchByYearNum(ba.data(),yearHead);
    }else return;
    if(yearGet!=NULL)
        showYearData(yearGet);

}

void MainWindow::showProjectData(Project *project)
{
    ui->tableWidget->clear();
    header.clear();
    header<<"项目编号"<<"项目名称"<<"经费数"<<"参与人数"<<"立项时间"<<"结题时间"<<"完成评价"<<"负责人"<<"负责人电话"<<"成果形式"<<"成果名称";
    ui->tableWidget->setColumnCount(11);
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(header);


// unfinished!


    int columnPosition=0;
    while (project!=NULL) {
        ui->tableWidget->setItem(columnPosition,0,new QTableWidgetItem(project->projectNum));
        ui->tableWidget->setItem(columnPosition,1,new QTableWidgetItem(project->projectName));
        QTableWidgetItem *projectMoneyItem=new QTableWidgetItem();
        projectMoneyItem->setData(Qt::DisplayRole,project->projectMoney);
        ui->tableWidget->setItem(columnPosition,2,projectMoneyItem);
        ui->tableWidget->setItem(columnPosition,3,new QTableWidgetItem(QString::number(project->personNum)));
        ui->tableWidget->setItem(columnPosition,4,new QTableWidgetItem(QString::number(project->projectStartTime)));
        ui->tableWidget->setItem(columnPosition,5,new QTableWidgetItem(QString::number(project->projectEndTime)));

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
            rank="不及格";
            break;
        case 4:
            rank="未完成";
            break;
        default:
            break;
        }

        ui->tableWidget->setItem(columnPosition,6,new QTableWidgetItem(rank));
        ui->tableWidget->setItem(columnPosition,7,new QTableWidgetItem(project->projectHostPerson));
        ui->tableWidget->setItem(columnPosition,8,new QTableWidgetItem(project->projectHostPersonTel));

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

        ui->tableWidget->setItem(columnPosition,9,new QTableWidgetItem(achiveType));
        ui->tableWidget->setItem(columnPosition,10,new QTableWidgetItem(project->achiveName));

        columnPosition++;
        project=project->nextProject;
    }
}

void MainWindow::showProjectData(ProjectGet *projectGet){
    ui->tableWidget->clear();
    header.clear();
    header<<"项目编号"<<"项目名称"<<"经费数"<<"参与人数"<<"立项时间"<<"结题时间"<<"完成评价"<<"负责人"<<"负责人电话"<<"成果形式"<<"成果名称";
    ui->tableWidget->setColumnCount(11);
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(header);


    Project *project=NULL;
    int columnPosition=0;
    while (projectGet!=NULL) {
        project=projectGet->project;
        ui->tableWidget->setItem(columnPosition,0,new QTableWidgetItem(project->projectNum));
        ui->tableWidget->setItem(columnPosition,1,new QTableWidgetItem(project->projectName));
        QTableWidgetItem *projectMoneyItem=new QTableWidgetItem();
        projectMoneyItem->setData(Qt::DisplayRole,project->projectMoney);
        ui->tableWidget->setItem(columnPosition,2,projectMoneyItem);
        ui->tableWidget->setItem(columnPosition,3,new QTableWidgetItem(QString::number(project->personNum)));
        ui->tableWidget->setItem(columnPosition,4,new QTableWidgetItem(QString::number(project->projectStartTime)));
        ui->tableWidget->setItem(columnPosition,5,new QTableWidgetItem(QString::number(project->projectEndTime)));

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
            rank="不及格";
            break;
        case 4:
            rank="未完成";
            break;
        default:
            break;
        }

        ui->tableWidget->setItem(columnPosition,6,new QTableWidgetItem(rank));
        ui->tableWidget->setItem(columnPosition,7,new QTableWidgetItem(project->projectHostPerson));
        ui->tableWidget->setItem(columnPosition,8,new QTableWidgetItem(project->projectHostPersonTel));

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

        ui->tableWidget->setItem(columnPosition,9,new QTableWidgetItem(achiveType));
        ui->tableWidget->setItem(columnPosition,10,new QTableWidgetItem(project->achiveName));

        columnPosition++;
        projectGet=projectGet->nextProjectGet;
    }
}

void MainWindow::showPersonData(PersonGet *personGet)
{
    ui->tableWidget->clear();
    header.clear();
    header<<"学号"<<"姓名"<<"年龄"<<"类别"<<"学校及专业"<<"班级"<<"本人特长"<<"承担任务"<<"联系电话"<<"项目成员排名";
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    Person *person=NULL;


    int columnPosition=0;
    while(personGet!=NULL){
        person = personGet->person;
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
        columnPosition++;
        personGet=personGet->nextPersonGet;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getProject(Project *)
{

}

void MainWindow::on_showYearBtn_clicked()
{
    showYearData(yearHead);
    ui->showYearBtn->setDisabled(true);
    ui->showProjectBtn->setDisabled(false);
    ui->showPersonBtn->setDisabled(true);
    ui->yearLabel->clear();
    ui->projectLabel->clear();
}

void MainWindow::on_showProjectBtn_clicked()
{
    QByteArray ba;
    YearGet *yearGet;
    Year *yearSelect=yearHead;
    ui->projectLabel->clear();
    if(QString::compare(ui->tableWidget->horizontalHeaderItem(0)->text(),"年度编号")!=0){
        ba=ui->yearLabel->text().toLatin1();
        yearGet=searchByYearNum(ba.data(),yearHead);
    }
    else{
    yearPosition = ui->tableWidget->currentRow();
    if(yearPosition==-1)
        yearPosition=0;
    ba=ui->tableWidget->item(yearPosition, 0)->text().toLatin1();
    yearGet=searchByYearNum(ba.data(),yearHead);
    qDebug()<<"www"<<ui->tableWidget->horizontalHeaderItem(0)->text();
    }

    if(yearGet==NULL){
        qDebug()<<"bbb";

        QMessageBox::warning(NULL,"warning","请选择正确的年度计划",QMessageBox::Yes);
        return;
    }
    ui->yearLabel->setText(QString(yearGet->year->yearNum));

    showProjectData(yearGet->year->project);
    projectHead=yearSelect->project;
    ui->showYearBtn->setDisabled(false);
    ui->showProjectBtn->setDisabled(true);
    ui->showPersonBtn->setDisabled(false);
}

void MainWindow::on_showPersonBtn_clicked()
{
    Project *projectSelect=projectHead;
    QByteArray ba,baYear;
    YearGet *yearGet;
    ProjectGet *projectGet;

    if(QString::compare(ui->tableWidget->horizontalHeaderItem(0)->text(),"项目编号")!=0){
        ba=ui->projectLabel->text().toLatin1();
        baYear=ui->yearLabel->text().toLatin1();
        yearGet=searchByYearNum(baYear.data(),yearHead);
        projectGet = searchByProjectNum(ba.data(),yearGet->year);
    }else{
        projectPosition=ui->tableWidget->currentRow();
        if(projectPosition==-1)
            projectPosition=0;
        ba=ui->tableWidget->item(projectPosition,0)->text().toLatin1();
        baYear=ui->yearLabel->text().toLatin1();
        yearGet=searchByYearNum(baYear.data(),yearHead);
        projectGet = searchByProjectNum(ba.data(),yearGet->year);
    }

    if(projectGet==NULL){
        qDebug()<<"bbb";

        QMessageBox::warning(NULL,"warning","请选择正确的项目",QMessageBox::Yes);
        return;
    }
    projectSelect=projectGet->project;

    ui->projectLabel->setText(QString(projectSelect->projectNum));
    showPersonData(projectSelect->person);
    ui->showYearBtn->setDisabled(false);
    ui->showProjectBtn->setDisabled(false);
    ui->showPersonBtn->setDisabled(true);
}

void MainWindow::mySortByColumn(int column)
{
    static bool f=true;
    ui->tableWidget->sortByColumn(column, f? Qt::AscendingOrder:Qt::DescendingOrder);
    f=!f;
}

void MainWindow::on_actionYearNum_triggered()
{
    searchByYearNumGUI();
}

void MainWindow::on_actionYearMoney_triggered()
{
    Dialog *dlg=new Dialog(this);
    YearGet *yearGet=NULL;
    dlg->show();

    if(dlg->exec())
    {
        yearGet=searchByYearMoney(dlg->getMin(),dlg->getMax(),yearHead);
    }else return;

    if(yearGet!=NULL)
        showYearData(yearGet);
}

void MainWindow::on_actionYearAct_triggered()
{
    Dialog *dlg=new Dialog(this);
    YearGet *yearGet=NULL;
    dlg->show();

    if(dlg->exec())
    {
        yearGet=searchByYearActProject(dlg->getMin(),dlg->getMax(),yearHead);
    }else return;

    if(yearGet!=NULL)
        showYearData(yearGet);
}

void MainWindow::on_actionProjectNum_triggered()
{
    bool isOK;
    ProjectGet *projectGet=NULL;
    QString text = QInputDialog::getText(NULL,"SearchYearNum","输入项目的编号",QLineEdit::Normal,"",&isOK);
    if(isOK){
        QByteArray ba=text.toLatin1();
        projectGet=searchByProjectNum(ba.data(),yearHead);
    }else return;
    if(projectGet!=NULL)
        showProjectData(projectGet);
}

void MainWindow::on_actionProjectName_triggered()
{
    bool isOK;
    ProjectGet *projectGet=NULL;
    QString text = QInputDialog::getText(NULL,"SearchYearNum","输入项目的名称",QLineEdit::Normal,"",&isOK);
    if(isOK){
        QByteArray ba=text.toLatin1();
        projectGet=searchByProjectName(ba.data(),yearHead);
    }else return;
    if(projectGet!=NULL)
        showProjectData(projectGet);
}

void MainWindow::on_actionProjectAchiveName_triggered()
{
    bool isOK;
    ProjectGet *projectGet=NULL;
    QString text = QInputDialog::getText(NULL,"SearchYearNum","输入项目的成果名称",QLineEdit::Normal,"",&isOK);
    if(isOK){
        QByteArray ba=text.toLatin1();
        projectGet=searchByProjectAchiveName(ba.data(),yearHead);
    }else return;
    if(projectGet!=NULL)
        showProjectData(projectGet);
}

void MainWindow::on_actionProjectMoney_triggered()
{
    Dialog *dlg=new Dialog(this);
    ProjectGet *projectGet=NULL;
    dlg->show();

    if(dlg->exec())
    {
        projectGet=searchByProjectMoney(dlg->getMin(),dlg->getMax(),yearHead);
    }else return;

    if(projectGet!=NULL)
        showProjectData(projectGet);
}

void MainWindow::on_actionProjectRank_triggered()
{
    bool isOK;
    ProjectGet *projectGet=NULL;
    int rank = QInputDialog::getInt(NULL,"SearchYearNum","输入项目的评级",1,0,4,1,&isOK);
    if(isOK){
        projectGet=searchByProjectRank(rank,yearHead);
    }else return;
    if(projectGet!=NULL)
        showProjectData(projectGet);
}

void MainWindow::on_actionProjectAchiveType_triggered()
{
    bool isOK;
    ProjectGet *projectGet=NULL;
    int type = QInputDialog::getInt(NULL,"SearchYearNum","输入项目的成果类型",1,0,3,1,&isOK);
    if(isOK){
        projectGet=searchByProjectAchiveType(type,yearHead);
    }else return;
    if(projectGet!=NULL)
        showProjectData(projectGet);
}

void MainWindow::on_actionPersonName_triggered()
{
    bool isOK;
    PersonGet *personGet=NULL;
    QString text = QInputDialog::getText(NULL,"SearchYearNum","输入人员姓名",QLineEdit::Normal,"",&isOK);
    if(isOK){
        QByteArray ba=text.toLatin1();
        personGet=searchByPersonName(ba.data(),yearHead);
    }else return;
    if(personGet!=NULL)
        showPersonData(personGet);
}

void MainWindow::on_actionPersonMajor_triggered()
{
    bool isOK;
    PersonGet *personGet=NULL;
    QString text = QInputDialog::getText(NULL,"SearchYearNum","输入人员专业信息",QLineEdit::Normal,"",&isOK);
    if(isOK){
        QByteArray ba=text.toLatin1();
        personGet=searchByPersonMajor(ba.data(),yearHead);
    }else return;
    if(personGet!=NULL)
        showPersonData(personGet);
}

void MainWindow::on_actionPersonSkill_triggered()
{
    bool isOK;
    PersonGet *personGet=NULL;
    QString text = QInputDialog::getText(NULL,"SearchYearNum","输入人员特长",QLineEdit::Normal,"",&isOK);
    if(isOK){
        QByteArray ba=text.toLatin1();
        personGet=searchByPersonSkill(ba.data(),yearHead);
    }else return;
    if(personGet!=NULL)
        showPersonData(personGet);
}

void MainWindow::on_actionPersonTask_triggered()
{
    bool isOK;
    PersonGet *personGet=NULL;
    QString text = QInputDialog::getText(NULL,"SearchYearNum","输入人员任务",QLineEdit::Normal,"",&isOK);
    if(isOK){
        qDebug()<<"bbb";

        QByteArray ba=text.toLatin1();
        personGet=searchByPersonTask(ba.data(),yearHead);
        qDebug()<<"sxac";

    }else return;
    if(personGet!=NULL)
        showPersonData(personGet);
    qDebug()<<"acsxac";
}
