#ifndef DIALOGTOINSERT_H
#define DIALOGTOINSERT_H

#include <QDialog>

namespace Ui {
class DialogToInsert;
}

class DialogToInsert : public QDialog
{
    Q_OBJECT

public:
    explicit DialogToInsert(QWidget *parent = 0);

    void getYear();
    void getProject();
    void getPerson();

    char *getYearNum();
    float getYearMoney();
    char *getYearHostPerson();
    int getYearApplyProjectNum();
    int getActProjectNum();
    int getEndProjectNum();
    int getStartTime();
    int getEndTime();
    char* getProjectNum();
    char* getProjectName();
    float getProjectMoney();
    int getPersonNum();
    int getProjectStartTime();
    int getProjectEndTime();
    int getRank();
    char *getProjectHostPerson();
    char *getProjectHostPersonTel();
    int getAchiveType();
    char *getAchiveName();
    ~DialogToInsert();

private:
    Ui::DialogToInsert *ui;
};

#endif // DIALOGTOINSERT_H
