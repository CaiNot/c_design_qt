#ifndef DEALFILE_H
#define DEALFILE_H

/*
**将年度计划指针里面的内容按照一定的格式写入文件
*/

#include "content.h"
/*
**@parameter year: 年度计划的头指针;
**@parameter pFile: 以只写方式打开的文件指针;
**
**@return value: 0 文件指针为NULL
**				-1 其它问题
**				 1 一切正常
*/
int writeFile(Year *year, FILE *pFile);

/*
**@parameter year: 要写入的年度计划的头指针;
**@parameter pFile: 以只读方式打开的文件指针;
**
**@return value: 0 文件指针为NULL
**				-1 其它问题
**				 1 一切正常
*/
int readFile(Year* year, FILE *pFile);



#endif // DEALFILE_H
