#ifndef _APUE_DB_H_
#define _APUE_DB_H

typedef void *DBHANDLE;

#define DB_INSERT 1
#define DB_REPLACE 2
#define DB_STORE 3

#define IDXLEN_MIN 6
#define IDXLEN_MAX 1024 // single index can not exceed this size
#define DATLEN_MIN 2
#define DATLEN_MAX 1024 // single data can not exceed this size
#define NHASH_DEF 137 // default hash table size

DBHANDLE db_open(char const *pathname, int oflag, .../*mode*/);
void db_close(DBHANDLE db);
/*
	存储一个key，flag 指定覆盖方式：
DB_INSERT 当已经有这个key时会返回失败
DB_REPLACE 当没有这个key时会返回失败
DB_STORE 综合了上面两种情况，有时REPLACE，没有时INSERT
*/
int db_store(DBHANDLE db, const char *key, const char *data, int flag);
char* db_fetch(DBHANDLE db, char *key);//db_fetch 获取一个key对应的data
int db_delete(DBHANDLE db, const char *key);
void db_rewind(DBHANDLE db);
char *db_nextrec(DBHANDLE db, char *key);
void db_dump(DBHANDLE db);

#endif