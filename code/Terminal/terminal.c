#include "terminal.h"
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData){
    char daystr[3];
    char monthtr[3];
    char yearStr[5];
    printf("Enter card Transaction date (in DD/MM/YYYY format)\n");
    scanf("%s",&termData->transactionDate);
    while(checktran(termData->transactionDate)==1||length_str(termData->transactionDate)>10){
        printf("WRONG FORMAT ENTER AGAIN (in DD/MM/YYYY format) \n");
        scanf("%s",&termData->transactionDate);
    }  
    str_slice(termData->transactionDate, 0, 1, daystr);
    str_slice(termData->transactionDate, 3, 4, monthtr);
    str_slice(termData->transactionDate, 6, 9, yearStr);
    if (string_to_int(daystr) > 30){
        return WRONG_DATE;
    }
    if (string_to_int(monthtr) > 12){
        return WRONG_DATE;
    }
    if (string_to_int(yearStr) < 2022){
        return WRONG_DATE;
    }
    return OK_TERMINAL;
}



EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData){
    // 11/12/2022
    char monthtr[2];
    char yearStr[2];
    slice_str(termData->transactionDate, monthtr, 2, 4);
    slice_str(termData->transactionDate, yearStr, 8, 9);
    int yearTerm= string_to_int(yearStr);
    int monthTerm = string_to_int(monthtr);
    str_slice(cardData->cardExpirationDate, -1, 1, monthtr);
    str_slice(cardData->cardExpirationDate, 3, 4, yearStr);
    int yearCard = string_to_int(yearStr);
    int monthCard = string_to_int(monthtr);
    if(yearTerm > yearCard ){
        return EXPIRED_CARD;
    }
    if(yearTerm == yearCard && monthTerm > monthCard){
        return EXPIRED_CARD;
    }
    return OK_TERMINAL;



}
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData){
    printf("Enter Transaction amount (in numbers format)\n");    
    scanf("%f",&termData->transAmount);
    if(termData->transAmount<=0){
        return INVALID_AMOUNT;
    }
    return OK_TERMINAL;

}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData){
    if(termData->transAmount > termData->maxTransAmount){
        return EXCEED_MAX_AMOUNT;
    }
    return OK_TERMINAL;

}
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData){
    printf("Enter maximum Transaction amount (in numbers format)\n");    
    scanf("%f",&termData->maxTransAmount);
    if(termData->maxTransAmount<=0){
        return INVALID_MAX_AMOUNT;
    }
    return OK_TERMINAL;

}

