/*
* File: menu.c
* Author:   Sergio Sánchez Alcalde y Miguel Ángel Martinez Parra
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sql.h>
#include "odbc.h"
#define MAX_PRODUCT_ID 9

int main(void) {
    SQLHENV env;
    SQLHDBC dbc;
    SQLRETURN ret;
    int nChoice = 0;

    ret = odbc_connect(&env, &dbc);
    if (!SQL_SUCCEEDED(ret)) {
        printf("Error conecting the data base.");
        return EXIT_FAILURE;
    }

    do {
        nChoice = ShowMainMenu();
        switch (nChoice) {
            case 1: {
                ShowProductsMenu();
            }
                break;

            case 2: {
                ShowOrdersMenu();
            }
                break;

            case 3: {
                ShowCustomersMenu();
            }
                break;
            
            case 4: {
                printf("Bye Bye\n\n");
            }
                break;
        }
    } while (nChoice != 4);

    ret = odbc_disconnect(env, dbc);
    if (!SQL_SUCCEEDED(ret)) {
        return EXIT_FAILURE;
    }

    return 0;
}

int ShowMainMenu() {
    int nSelected = 0;
    char buf[16]; 


    do {
        printf("This is a data base program of a clasic cars enterprise\n");
        printf("You can choose to display the products, orders and customers\n\n");

        printf(" (1) Products\n"
               " (2) Orders\n"
               " (3) Customers\n"
               " (4) Exit\n\n"
               "Enter a number that corresponds to your choice > ");
        if (!fgets(buf, 16, stdin))
            /* reading input failed, give up: */
            nSelected =0;
        else
            /* have some input, convert it to integer: */
            nSelected = atoi(buf);
        printf("\n");

        if ((nSelected < 1) || (nSelected > 4)) {
            printf("You have entered an invalid choice. Please try again\n\n\n");
        }
    } while ((nSelected < 1) || (nSelected > 4));

    return nSelected;
}

void ShowProductsMenu() {
    SQLHDBC dbc;
    int nChoice = 0;
    do {
        nChoice = ShowProductsSubMenu();
        switch (nChoice) {

            case 1: {
                ProductsStock(hdbc);
            }
                break;

            case 2: {
                ProductsFind(hdbc);
            }
                break;

            case 3: {
                printf("Bye Bye\n\n");
            }
                break;
        }
    } while (nChoice != 3);

}

int ShowProductsSubMenu() {
    int nSelected = 0;
    char buf[16];

    do {

        printf(" (1) Stock\n"
               " (2) Find\n"
               " (3) Quit\n\n");
               

        printf("Enter a number that corresponds to your choice > ");
        if (!fgets(buf, 16, stdin))
            /* reading input failed, give up: */
            nSelected =0;
        else
            /* have some input, convert it to integer: */
            nSelected = atoi(buf);
        printf("\n");


        if ((nSelected < 1) || (nSelected > 4)) {
            printf("You have entered an invalid choice. Please try again\n\n\n");
        }
    } while ((nSelected < 1) || (nSelected > 4));

    return nSelected;
}

