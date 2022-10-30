#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"
#include "card.h"
#include "server.h"
#include "strings.h"
int main()
{
//initial states 
EN_transState_t stat1 ={1};
ST_terminalData_t term1={2000,20000,"10/11/2022"};
ST_cardData_t card1={"Marwan atef muhammed","7391462851236798128","11/25"};

//card implementation
while(getCardHolderName(&card1)==1){
    printf("WRONG NAME\n");
}
while(getCardExpiryDate(&card1)==2){
    printf("WRONG EXPIR DATE\n");
}
while(getCardPAN(&card1)==3){
    printf("WORNG PRIMARY ACCOUNT NUMBER\n");
}
getCardData(&card1);

//terminal implementation
getTransactionDate(&term1);
if(isCardExpired(&card1,&term1)==0){
    printf("Congrats your card isn't expired\n");
    while(getTransactionAmount(&term1)==4){
        printf("INVALID AMOUNT\n");
    }
    while(setMaxAmount(&term1)==6){
        printf("INVALID MAXIMUM AMOUNT\n");
    }
    if(isBelowMaxAmount(&term1)==0){
        printf("Your transaction amount is not exceeding the limit\n");
        if(isValidAccount(&card1)==0){
            ST_transaction_t trans1={card1,term1,stat1,1};
            if(isValidAccount(&card1)==OK_SERVER)
            printf("valid account\n");
            if(isValidAccount(&card1)==ACCOUNT_NOT_FOUND)
            printf("not valid account\n");
            if(isAmountAvailable(&term1)==OK_SERVER)
            printf("amount available\n");
            if(isAmountAvailable(&term1)==LOW_BALANCE)
            printf("low balance\n");
            recieveTransactionData(&trans1);
        }
        else{
            printf("STOLEN CARD\n");
        }
    }
    else{
        printf("The amount you entered excedded the aviable amount\n");
    }
}
else{
    printf("Sadly your card  is expired\n");
}
}
