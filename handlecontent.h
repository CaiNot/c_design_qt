#ifndef HANDLECONTENT_H
#define HANDLECONTENT_H
#include "content.h"

Year *insertYear(Year *yearHead, Year *year);

Project *insertProject(Year *yearNeeded, Project *project);

Person *insertPerson(Project *projectNeeded, Person *person);

Year *deleteYear(Year *yearHead, Year *year);

Project *deleteProject(Year *yearNeeded, Project *project);

Person *deletePerson(Project *projectNeeded, Person *person);

#endif // HANDLECONTENT_H
