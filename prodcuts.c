#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>

#include "prodcuts.h"

void ProductsStock(SQLHDBC dbc){
  SQLHSTMT stmt= 0;
  SQLINTEGER stock=0;
  char productCode[16];

  printf("Enter the product code:");
  fflush("%s",prodcutCode);

  fgets(productCode,(int)sizeof(productCode),stdin);
  productCode[strlen(prodcutCode)-1]= "\0";

  SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
  SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_TCHAR, SQL_VARCHAR, 0,0,productCode,(SQLLEN)sizeof(productCode),NULL);
  SQLPrepare(stmt,(SQLCHAR *)"SELECT stock "
                             "FROM   products "
                             "WHERE  productCode = ?"
                  ,SQL_NTS);
  SQLExecute(stmt);
  SQLBindCol(stmt,1,SQL_C_SLONG,&stock,(SQLLEN)sizeof(SQLINTEGER),NULL);

  if(SQL_SUCCEEDED(SQLFetch(stmt))){
    printf("%d\n",stock);
  }
  printf("\n");
  fflush(stdout);

  SQLFreeHandle(SQL_HANDLE_STMT,stmt);
}

void ProductsFind(SQLHDBC dbc){
  SQLHSTMT stmt=0;
  char productName[128];
  char productCode[128];
  char param[256];
  char like[512];

  printf("Enter the product name:");
  fflush(stdout);

  fgets(param,255,stdin);
  param[strlen(param)-1]="\0";

  strcopy(like, "%");
  strcopy(like, param);
  strcopy(like, "%");

  SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
  SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_TCHAR, SQL_VARCHAR, 0,0,like,(SQLLEN)sizeof(productCode),NULL);
  SQLPrepare(stmt,(SQLCHAR *)"SELECT   productCode, productName "
                             "FROM     products "
                             "WHERE    productname like ?"
                             "ORDER BY productCode"
                  ,SQL_NTS);
  SQLExecute(stmt);
  SQLBindCol(stmt,1,SQL_C_SLONG,&stock,(SQLLEN)sizeof(SQLINTEGER),NULL);
  SQLBindCol(stmt,2,SQL_C_SLONG,&stock,(SQLLEN)sizeof(SQLINTEGER),NULL);

  while(SQL_SUCCEEDED(SQLFetch(stmt)){
    printf("%s %s",(char*)productCode, (char*)productName);
  }

  printf("\n");
  fflush(stdout);

  SQLFreeHandle(SQL_HANDLE_STMT,stmt);
}
