#ifndef CONTENT_H
#define CONTENT_H

#include <stdio.h>
#include <stdlib.h>

enum Rank {
    PERFECT, GOOD, OK, BAD, UNFINISHED
};

enum AchiveType {
    SOFTWARE, PAPER, PRODUCTION, OTHER
};

enum PersonType {
    UNDERGRADUATE, POSTGRADUATE, DOCTOR, TEACHER
};

typedef struct year Year;
typedef struct project Project;
typedef struct person Person;

struct year {
    char* yearNum;
    float yearMoney;
    char* yearHostPerson;
    int applyProjectNum;
    int actProjectNum;
    int endProjectNum;
    int startTime;
    int endTime;
    Project *project;
    Year *nextYear;
};

struct project {
    char* projectNum;
    char* projectName;
    float projectMoney;
    int personNum;
    int projectStartTime;
    int projectEndTime;
    enum Rank rank;
    char *projectHostPerson;
    char *projectHostPersonTel;
    enum AchiveType achiveType;
    char *achiveName;
    Person *person;
    Project *nextProject;
};

struct person {
    char *personID;
    char *personName;
    int age;
    enum PersonType personType;
    char *major;
    char *classRoom;
    char *skill;
    char *task;
    char *tel;
    int personRank;
    Person *nextPerson;
};




Year* mallocYear(Year *year);

Project* mallocProject(Project *project);

Person* mallocPerson(Person *person);

int freeOnePerson(Person *person);

int freeOneProject(Project *project);

int freeOneYear(Year *year);


#endif // CONTENT_H
