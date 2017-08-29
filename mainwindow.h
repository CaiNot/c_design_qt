#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "content.h"
#include "search.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void inputFile();
    void showYearData(Year *year);
    void showYearData(YearGet *yearGet);

    void showProjectData(Project *project);
    void showProjectData(ProjectGet *projectGet);

    void showPersonData(Person *person);
    void showPersonData(PersonGet *personGet);
    void searchByYearNumGUI();


    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStringList header;
    QString rank;
    QString achiveType;
    QString personType;
    Year *year;
    Year *yearHead;
    Project *projectHead;
    int yearPosition;
    int projectPosition;


private slots:
    void getProject(Project *);

    void on_showYearBtn_clicked();

    void on_showProjectBtn_clicked();

    void on_showPersonBtn_clicked();

    void mySortByColumn(int column);

    void on_actionYearNum_triggered();

    void on_actionYearMoney_triggered();

    void on_actionYearAct_triggered();

    void on_actionProjectNum_triggered();

    void on_actionProjectName_triggered();

    void on_actionProjectAchiveName_triggered();

    void on_actionProjectMoney_triggered();

    void on_actionProjectRank_triggered();

    void on_actionProjectAchiveType_triggered();

    void on_actionPersonName_triggered();

    void on_actionPersonMajor_triggered();

    void on_actionPersonSkill_triggered();

    void on_actionPersonTask_triggered();

signals:
    void sendProject(Project *);
};

#endif // MAINWINDOW_H
