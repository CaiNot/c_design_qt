#include "dealfile.h"
#include "stdio.h"

int writeFile(Year *year, FILE *pFile) {

    Project *project = NULL;
    Person *person = NULL;

    //确认文件指针是否为NULL
    if(pFile == NULL) {
        printf("file pointer wrong!");
        return 0;
    }

    //将年度计划中的所有信息写入文件中
    //(因为不同的变量是以空格为分界,所以,应当事先将所有的字符串进行预处理:将空格转换成下划线)
    fprintf(pFile, "{\n");
    while(year != NULL) {
        fprintf(pFile, "{%s %f %s %d %d %d %d %d\n", year->yearNum, year->yearMoney, year->yearHostPerson,
            year->applyProjectNum, year->actProjectNum, year->endProjectNum, year->startTime, year->endTime);

        project = year->project;

        while(project != NULL) {
            fprintf(pFile, "{%s %s %f %d %d %d %d %s %s %d %s\n", project->projectNum, project->projectName,
                project->projectMoney, project->personNum, project->projectStartTime, project->projectEndTime,
                project->rank, project->projectHostPerson, project->projectHostPersonTel, project->achiveType,
                project->achiveName);

            person = project->person;

            while(person != NULL) {
                fprintf(pFile, "{%s %s %d %d %s %s %s %s %s %d\n", person->personID, person->personName,
                    person->age, person->personType, person->major, person->classRoom, person->skill,
                    person->task, person->tel, person->personRank);
                fprintf(pFile, "}\n");
                person = person->nextPerson;
            }
            fprintf(pFile, "}\n");
            project = project->nextProject;
        }
        fprintf(pFile, "}\n");
        year = year->nextYear;
    }
    fprintf(pFile, "}");
    return 1;
}

int readFile(Year *year, FILE *pFile) {

    Year *nextYear = NULL;
    Project *project = NULL, *nextProject = NULL;
    Person *person = NULL, *nextPerson = NULL;

    int endMarkNum = 0, endWord = 0;

    fgetc(pFile);
    fgetc(pFile);
    while(fscanf(pFile, "{%s %f %s %d %d %d %d %d\n", year->yearNum, &year->yearMoney, year->yearHostPerson,
        &year->applyProjectNum, &year->actProjectNum, &year->endProjectNum, &year->startTime, &year->endTime) != EOF) {

        project = mallocProject(project);//为project分配头指针
        year->project = project;
        while(fscanf(pFile, "{%s %s %f %d %d %d %d %s %s %d %s\n", project->projectNum, project->projectName,
            &project->projectMoney, &project->personNum, &project->projectStartTime, &project->projectEndTime,
            &project->rank, project->projectHostPerson, project->projectHostPersonTel, &project->achiveType,
            project->achiveName) != EOF) {

            person = mallocPerson(person);//为person分配头指针
            project->person = person;
            while(fscanf(pFile, "{%s %s %d %d %s %s %s %s %s %d\n", person->personID, person->personName,
                &person->age, &person->personType, person->major, person->classRoom, person->skill,
                person->task, person->tel, &person->personRank) != EOF) {
                endWord = fgetc(pFile);
                if(endWord == '}')//读取到第一个'}', 意味着这个person的内容已经结束了
                    endMarkNum++;

                fgetc(pFile);
                endWord = fgetc(pFile);
                if(endWord == '}') {//读取到第二个'}', 意味着所有的person的内容已经结束了, 同时也意味着这个project的内容已经结束了
                    person->nextPerson = NULL;
                    endMarkNum++;
                    break;
                }
                else if(endWord == '{') {//读取到一个'{', 开始储存下一个person的内容
                    nextPerson = mallocPerson(nextPerson);
                    person->nextPerson = nextPerson;
                    person = nextPerson;
                    fseek(pFile, -1, SEEK_CUR);//将读取文件的位置返回一位,
                    endMarkNum = 0;
                    continue;
                }
            }
            //这里要好好考虑一下....
            fgetc(pFile);
            endWord = fgetc(pFile);
            if(endWord == '}') {//意味着这个year已经结束了
                project->nextProject = NULL;
                endMarkNum++;
                break;
            }
            else if(endWord == '{') {//读取到第二个'{', 开始储存下一个project的内容
                nextProject = mallocProject(nextProject);
                project->nextProject = nextProject;
                project = nextProject;
                fseek(pFile, -1, SEEK_CUR);
                endMarkNum = 0;
                continue;
            }
        }
        fgetc(pFile);
        endWord = fgetc(pFile);
        if(endWord == '}') {
            year->nextYear = NULL;
            endMarkNum++;
            break;
        }
        else if(endWord == '{') {
            nextYear = mallocYear(nextYear);
            year->nextYear = nextYear;
            year = nextYear;
            fseek(pFile, -1, SEEK_CUR);
            continue;
        }

    }
    return 1;
}


