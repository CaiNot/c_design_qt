#include "content.h"

Year* mallocYear(Year *year) {
    year = (Year*)malloc(sizeof(Year));

    year->yearNum = (char*)malloc(10 * sizeof(char));
    year->yearHostPerson = (char*)malloc(50 * sizeof(char));
    year->project = (Project*)malloc(sizeof(Project));

    return year;
}

Project* mallocProject(Project *project) {
    project = (Project*)malloc(sizeof(Project));

    project->projectNum = (char*)malloc(10 * sizeof(char));
    project->projectName = (char*)malloc(80 * sizeof(char));
    project->projectHostPerson = (char*)malloc(50 * sizeof(char));
    project->projectHostPersonTel = (char*)malloc(20 * sizeof(char));
    project->achiveName = (char*)malloc(100 * sizeof(char));

    return project;
}

Person* mallocPerson(Person *person) {
    person = (Person*)malloc(sizeof(Person));

    person->personID = (char*)malloc(20 * sizeof(char));
    person->personName = (char*)malloc(16 * sizeof(char));
    person->major = (char*)malloc(30 * sizeof(char));
    person->classRoom = (char*)malloc(16 * sizeof(char));
    person->skill = (char*)malloc(200 * sizeof(char));
    person->task = (char*)malloc(200 * sizeof(char));
    person->tel = (char*)malloc(20 * sizeof(char));

    return person;
}

int freeOnePerson(Person *person) {
    if(person == NULL)
        return 0;
    free(person->personID);
    free(person->personName);
    free(person->major);
    free(person->classRoom);
    free(person->skill);
    free(person->task);
    free(person->tel);
    free(person);

    person = NULL;
    return 1;
}

int freeOneProject(Project *project) {
    if(project == NULL)
        return 0;

    Person *person = NULL, *nextPerson = NULL;
    person = project->person;

    while(person != NULL) {
        nextPerson = person->nextPerson;
        freeOnePerson(person);
        person = nextPerson;
    }

    free(project->projectNum);
    free(project->projectName);
    free(project->projectHostPerson);
    free(project->projectHostPersonTel);
    free(project->achiveName);
    free(project);

    project = NULL;
    return 1;
}

int freeOneYear(Year *year) {
    if(year == NULL)
        return 0;
    Project *project = NULL, *nextProject = NULL;
    project = year->project;

    while(project != NULL) {
        nextProject = project->nextProject;
        freeOneProject(project);
        project = nextProject;
    }

    free(year->yearNum);
    free(year->yearHostPerson);
    free(year);

    year = NULL;
    return 1;
}
