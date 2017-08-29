#include "handlecontent.h"
#include "string.h"

Year *insertYear(Year *yearHead, Year *year) {

    Year *nextYear = NULL, *lastYear = NULL, *curYear = NULL;

    curYear = yearHead;
    while(curYear != NULL) {
        nextYear = curYear->nextYear;
        if(strcmp(year->yearNum, curYear->yearNum) > 0) {
            if(nextYear == NULL) { /*if the next node is NULL, insert 'year'.*/
                curYear->nextYear = year;
                year->nextYear = NULL;
                break;
            }
            else {
                curYear = curYear->nextYear;
            }
        }
        else {
            if(curYear == yearHead) { /*if the current node is head, reset the head */
                year->nextYear = yearHead;
                yearHead = year;
                break;
            }
            else {
                year->nextYear = curYear;
                lastYear->nextYear = year;
                break;
            }
        }
        lastYear = curYear;
        curYear = curYear->nextYear;
    }
    return yearHead;
}

Project *insertProject(Year *yearNeeded, Project *project) {

    Project *nextProject = NULL, *lastProject = NULL, *curProject = NULL, *projectHead = NULL;

    curProject = yearNeeded->project;
    projectHead = curProject;

    while(curProject != NULL) {
        nextProject = curProject->nextProject;

        if(strcmp(project->projectNum, curProject->projectNum) > 0) {
            if(nextProject == NULL) { /*if the next node is NULL, insert 'year'.*/
                curProject->nextProject = project;
                project->nextProject = NULL;
                break;
            }
            else {
                curProject = curProject->nextProject;
            }
        }
        else {
            if(curProject == projectHead) { /*if the current node is head, reset the head */
                project->nextProject=projectHead;
                projectHead->nextProject = project;
                break;
            }
            else {
                project->nextProject = curProject;
                lastProject->nextProject = project;
                break;
            }
        }
        lastProject = curProject;
        curProject = curProject->nextProject;
    }
    return projectHead;
}

Person *insertPerson(Project *projectNeeded, Person *person) {

    Person *nextPerson = NULL, *lastPerson = NULL, *curPerson = NULL, *personHead = NULL;

    curPerson = projectNeeded->person;
    personHead = curPerson;

    while(curPerson != NULL) {
        nextPerson = curPerson->nextPerson;

        if(strcmp(person->personID, curPerson->personID) > 0) {
            if(nextPerson == NULL) { /*if the next node is NULL, insert 'year'.*/
                curPerson->nextPerson = person;
                person->nextPerson = NULL;
                break;
            }
            else {
                curPerson = curPerson->nextPerson;
            }
        }
        else {
            if(curPerson==personHead) { /*if the current node is head, reset the head */
                person->nextPerson = personHead;
                personHead->nextPerson = person;
                break;
            }
            else {
                person->nextPerson = curPerson;
                lastPerson->nextPerson = person;
                break;
            }
        }
        lastPerson = curPerson;
        curPerson = curPerson->nextPerson;
    }

    return personHead;
}

Year *deleteYear(Year *yearHead, Year *year) {

    Year *curYear = NULL, *nextYear = NULL, *lastYear = NULL;

    curYear = yearHead;
    while(curYear != NULL) {
        nextYear= curYear->nextYear;
        if(curYear == year) {
            if(curYear == yearHead) { /*if delete the head node*/
                yearHead = yearHead->nextYear;
            }
            else {
                lastYear->nextYear = nextYear;
            }
            freeOneYear(curYear);
            break;
        }
        lastYear = curYear;
        curYear = curYear->nextYear;
    }
    return yearHead;
}

Project *deleteProject(Year *yearNeeded, Project *project) {
    Project *curProject = NULL, *nextProject = NULL, *lastProject = NULL, *projectHead = NULL;

    curProject = yearNeeded->project;
    projectHead = curProject;

    while(curProject!=NULL) {
        nextProject = curProject->nextProject;
        if(curProject == project) {
            if(curProject == projectHead) {
                yearNeeded->project = nextProject;
            }
            else {
                lastProject->nextProject = nextProject;
            }
            freeOneProject(curProject);
            break;
        }
        lastProject = curProject;
        curProject = nextProject;
    }

    return projectHead;
}

Person *deletePerson(Project *projectNeeded, Person *person) {
    Person *nextPerson = NULL, *lastPerson = NULL, *curPerson = NULL, *personHead = NULL;

    curPerson = projectNeeded->person;
    personHead = curPerson;

    while (curPerson!=NULL)
    {
        nextPerson = curPerson->nextPerson;
        if(curPerson == person) {
            if(curPerson == personHead) {
                projectNeeded->person = nextPerson;
            }
            else {
                lastPerson->nextPerson = nextPerson;
            }
            freeOnePerson(curPerson);
            break;
        }
        lastPerson = curPerson;
        curPerson = nextPerson;
    }

    return personHead;
}
