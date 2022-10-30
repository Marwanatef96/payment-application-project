#include "terminal.h"
#include "card.h"
#include "strings.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData){
    char str[15];
    char str1[15];
    char str2[15];
    char str3[15];
    // day
    printf("Enter Transaction day (in DD format)\n");    
    get_string(str1);
    // month
    printf("Enter Transaction mounth (in MM format)\n");    
    get_string(str2);
    // year
    printf("Enter Transaction year (in YYYY format)\n");    
    get_string(str3);
    if (string_to_int(str1) > 30){
        return WRONG_DATE;
    }
    if (string_to_int(str2) > 12){
        return WRONG_DATE;
    }
    if (string_to_int(str3) < 2022){
        return WRONG_DATE;
    }
    copy_str(str1, str);
    str[2] = '/';
    str_concat(str, str, str2);
    str[5] = '/';
    str_concat(str, str, str3);
    copy_str(str, termData->transactionDate);
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

