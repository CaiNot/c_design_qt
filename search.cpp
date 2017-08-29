#include "search.h"
#include <string.h>

int isBetween(float low, float num, float high) {
    if(low > num)
        return -1;
    else if(high < num)
        return 1;
    else return 0;
}

YearGet* searchByYearNum(char *yearNum, Year *year) {
    YearGet *yearGet = NULL, *yearGetHead = NULL, *yearGetLast = NULL;
    int yearCount = 0;

    while(year != NULL) {
        if(strstr(year->yearNum, yearNum) != NULL) {
            yearCount++;
            yearGet = (YearGet *)malloc(sizeof(YearGet));

            yearGet->year = year;
            if(yearCount == 1) {
                yearGetHead = yearGet;
            }else{
                yearGetLast->nextYearGet=yearGet;
            }
            yearGetLast = yearGet;//储存上一个yearGet, 以便于将最后一个节点指向NULL.
        }
        year = year->nextYear;
    }
    if(yearGetLast!=NULL)
        yearGetLast->nextYearGet = NULL;
    return yearGetHead;
}

YearGet* searchByYearMoney(float low, float high, Year *year) {
    YearGet *yearGet = NULL, *yearGetHead = NULL, *yearGetLast = NULL;
    int yearCount = 0;

    while(year != NULL) {
        if(isBetween(low, year->yearMoney, high) == 0) {
            yearCount++;
            yearGet = (YearGet *)malloc(sizeof(YearGet));

            yearGet->year = year;
            if(yearCount == 1) {
                yearGetHead = yearGet;
            }else{
                yearGetLast->nextYearGet = yearGet;//储存上一个yearGet, 以便于将最后一个节点指向NULL.
            }
            yearGetLast=yearGet;
        }
        year = year->nextYear;
    }
    if(yearGetLast!=NULL)
        yearGetLast->nextYearGet = NULL;
    return yearGetHead;
}

YearGet* searchByYearActProject(int low, int high, Year *year) {
    YearGet *yearGet = NULL, *yearGetHead = NULL, *yearGetLast = NULL;
    int yearCount = 0;

    while(year != NULL) {
        if(isBetween(low, year->actProjectNum, high) == 0) {
            yearCount++;
            yearGet = (YearGet *)malloc(sizeof(YearGet));

            yearGet->year = year;
            if(yearCount == 1) {
                yearGetHead = yearGet;
            }else{
                yearGetLast->nextYearGet = yearGet;//储存上一个yearGet, 以便于将最后一个节点指向NULL.
            }
            yearGetLast=yearGet;
        }
        year = year->nextYear;
    }
    if(yearGetLast!=NULL)
        yearGetLast->nextYearGet = NULL;
    return yearGetHead;
}

ProjectGet* searchByProjectNum(char *projectNum, Year *year) {

    ProjectGet *projectGet = NULL, *projectGetHead = NULL, *projectGetLast = NULL;
    Project *project = NULL;
    int projectCount = 0;

    while(year != NULL) {
        project = year->project;
        while(project != NULL) {
            if(strstr(project->projectNum, projectNum) != NULL) {
                projectCount++;
                projectGet = (ProjectGet *)malloc(sizeof(ProjectGet));

                projectGet->year = year;
                projectGet->project = project;
                if(projectCount == 1) {
                    projectGetHead = projectGet;
                }else{
                    projectGetLast->nextProjectGet = projectGet;
                }
                projectGetLast = projectGet;
            }
            project = project->nextProject;
        }
        year = year->nextYear;
    }
    if(projectGetLast!=NULL)
        projectGetLast->nextProjectGet = NULL;
    return projectGetHead;
}

ProjectGet* searchByProjectName(char *projectName, Year *year) {

    ProjectGet *projectGet = NULL, *projectGetHead = NULL, *projectGetLast = NULL;
    Project *project = NULL;
    int projectCount = 0;

    while(year != NULL) {
        project = year->project;
        while(project != NULL) {
            if(strstr(project->projectName, projectName) != NULL) {
                projectCount++;
                projectGet = (ProjectGet *)malloc(sizeof(ProjectGet));

                projectGet->year = year;
                projectGet->project = project;
                if(projectCount == 1) {
                    projectGetHead = projectGet;
                }else{
                    projectGetLast->nextProjectGet = projectGet;
                }
                projectGetLast = projectGet;
            }
            project = project->nextProject;
        }
        year = year->nextYear;
    }
    if(projectGetLast!=NULL)
        projectGetLast->nextProjectGet = NULL;
    return projectGetHead;
}

ProjectGet* searchByProjectAchiveName(char *achiveName, Year *year) {

    ProjectGet *projectGet = NULL, *projectGetHead = NULL, *projectGetLast = NULL;
    Project *project = NULL;
    int projectCount = 0;

    while(year != NULL) {
        project = year->project;
        while(project != NULL) {
            if(strstr(project->achiveName, achiveName) != NULL) {
                projectCount++;
                projectGet = (ProjectGet *)malloc(sizeof(ProjectGet));

                projectGet->year = year;
                projectGet->project = project;
                if(projectCount == 1) {
                    projectGetHead = projectGet;
                }else{
                    projectGetLast->nextProjectGet = projectGet;
                }
                projectGetLast = projectGet;
            }
            project = project->nextProject;
        }
        year = year->nextYear;
    }
    if(projectGetLast!=NULL)
        projectGetLast->nextProjectGet = NULL;
    return projectGetHead;
}

ProjectGet* searchByProjectMoney(float low, float high, Year *year) {

    ProjectGet *projectGet = NULL, *projectGetHead = NULL, *projectGetLast = NULL;
    Project *project = NULL;
    int projectCount = 0;

    while(year != NULL) {
        project = year->project;
        while(project != NULL) {
            if(isBetween(low, project->projectMoney, high) == 0) {
                projectCount++;
                projectGet = (ProjectGet *)malloc(sizeof(ProjectGet));

                projectGet->year = year;
                projectGet->project = project;
                if(projectCount == 1) {
                    projectGetHead = projectGet;
                }else{
                    projectGetLast->nextProjectGet = projectGet;
                }
                projectGetLast = projectGet;
            }
            project = project->nextProject;
        }
        year = year->nextYear;
    }
    if(projectGetLast!=NULL)
        projectGetLast->nextProjectGet = NULL;
    return projectGetHead;
}

ProjectGet* searchByProjectRank(int rank, Year *year) {

    ProjectGet *projectGet = NULL, *projectGetHead = NULL, *projectGetLast = NULL;
    Project *project = NULL;
    int projectCount = 0;

    while(year != NULL) {
        project = year->project;
        while(project != NULL) {
            if(project->rank == rank) {
                projectCount++;
                projectGet = (ProjectGet *)malloc(sizeof(ProjectGet));

                projectGet->year = year;
                projectGet->project = project;
                if(projectCount == 1) {
                    projectGetHead = projectGet;
                }else{
                    projectGetLast->nextProjectGet = projectGet;
                }
                projectGetLast = projectGet;
            }
            project = project->nextProject;
        }
        year = year->nextYear;
    }
    if(projectGetLast!=NULL)
        projectGetLast->nextProjectGet = NULL;
    return projectGetHead;
}

ProjectGet* searchByProjectAchiveType(int achiveType, Year *year) {

    ProjectGet *projectGet = NULL, *projectGetHead = NULL, *projectGetLast = NULL;
    Project *project = NULL;
    int projectCount = 0;

    while(year != NULL) {
        project = year->project;
        while(project != NULL) {
            if(project->achiveType == achiveType) {
                projectCount++;
                projectGet = (ProjectGet *)malloc(sizeof(ProjectGet));

                projectGet->year = year;
                projectGet->project = project;
                if(projectCount == 1) {
                    projectGetHead = projectGet;
                }else{
                    projectGetLast->nextProjectGet = projectGet;
                }
                projectGetLast = projectGet;
            }
            project = project->nextProject;
        }
        year = year->nextYear;
    }
    if(projectGetLast!=NULL)
        projectGetLast->nextProjectGet = NULL;
    return projectGetHead;
}

PersonGet* searchByPersonName(char *personName, Year *year) {

    PersonGet *personGet = NULL, *personGetHead = NULL, *personGetLast = NULL;
    Project *project = NULL;
    Person *person = NULL;
    int personCount = 0;

    while(year != NULL) {
        project = year->project;
        while(project != NULL) {
            person = project->person;
            while(person != NULL) {
                if(strstr(person->personName, personName) != NULL) {
                    personCount++;
                    personGet = (PersonGet *)malloc(sizeof(PersonGet));

                    personGet->year = year;
                    personGet->project = project;
                    personGet->person = person;
                    if(personCount == 1) {
                        personGetHead = personGet;
                    }else{
                        personGetLast->nextPersonGet = personGet;
                    }
                    personGetLast = personGet;
                }
                person = person->nextPerson;
            }
            project = project->nextProject;
        }
        year = year->nextYear;
    }
    if(personGetLast!=NULL)
        personGetLast->nextPersonGet = NULL;
    return personGetHead;
}

PersonGet* searchByPersonMajor(char *major, Year *year) {

    PersonGet *personGet = NULL, *personGetHead = NULL, *personGetLast = NULL;
    Project *project = NULL;
    Person *person = NULL;
    int personCount = 0;

    while(year != NULL) {
        project = year->project;
        while(project != NULL) {
            person = project->person;
            while(person != NULL) {
                if(strstr(person->major, major) != NULL) {
                    personCount++;
                    personGet = (PersonGet *)malloc(sizeof(PersonGet));

                    personGet->year = year;
                    personGet->project = project;
                    personGet->person = person;
                    if(personCount == 1) {
                        personGetHead = personGet;
                    }else{
                        personGetLast->nextPersonGet = personGet;
                    }
                    personGetLast = personGet;
                }
                person = person->nextPerson;
            }
            project = project->nextProject;
        }
        year = year->nextYear;
    }
    if(personGetLast!=NULL)
        personGetLast->nextPersonGet = NULL;
    return personGetHead;
}

PersonGet* searchByPersonSkill(char *skill, Year *year) {

    PersonGet *personGet = NULL, *personGetHead = NULL, *personGetLast = NULL;
    Project *project = NULL;
    Person *person = NULL;
    int personCount = 0;

    while(year != NULL) {
        project = year->project;
        while(project != NULL) {
            person = project->person;
            while(person != NULL) {
                if(strstr(person->skill, skill) != NULL) {
                    personCount++;
                    personGet = (PersonGet *)malloc(sizeof(PersonGet));

                    personGet->year = year;
                    personGet->project = project;
                    personGet->person = person;
                    if(personCount == 1) {
                        personGetHead = personGet;
                    }else{
                        personGetLast->nextPersonGet = personGet;
                    }
                    personGetLast = personGet;
                }
                person = person->nextPerson;
            }
            project = project->nextProject;
        }
        year = year->nextYear;
    }
    if(personGetLast!=NULL)
        personGetLast->nextPersonGet = NULL;
    return personGetHead;
}

PersonGet* searchByPersonTask(char *task, Year *year) {

    PersonGet *personGet = NULL, *personGetHead = NULL, *personGetLast = NULL;
    Project *project = NULL;
    Person *person = NULL;
    int personCount = 0;

    while(year != NULL) {
        project = year->project;
        while(project != NULL) {
            person = project->person;
            while(person != NULL) {
                if(strstr(person->task, task) != NULL) {
                    personCount++;
                    personGet = (PersonGet *)malloc(sizeof(PersonGet));

                    personGet->year = year;
                    personGet->project = project;
                    personGet->person = person;
                    if(personCount == 1) {
                        personGetHead = personGet;
                    }else{
                        personGetLast->nextPersonGet = personGet;
                    }
                    personGetLast = personGet;
                }
                person = person->nextPerson;
            }
            project = project->nextProject;
        }
        year = year->nextYear;
    }
    if(personGetLast!=NULL)
        personGetLast->nextPersonGet = NULL;
    return personGetHead;
}
