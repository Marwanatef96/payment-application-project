#include "card.h"
#include "strings.h"
#include "string.h"
#include <stdlib.h>



EN_cardError_t getCardHolderName(ST_cardData_t *cardData){
    char str[50];
    printf("Enter card holder name (character range 20:24)\n");
    get_string(str);
    if(length_str(str) < 20 || length_str(str) > 24){
        return WRONG_NAME;
    }
    copy_str( str,cardData->cardHolderName);
    return OK_CARD;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData){
    char str[10];
    char str1[10];
    char str2[10];
    // month
    printf("Enter card Expiration mounth (in MM format)\n");
    get_string(str1);
    printf("Enter card Expiration year (in YY format)\n");
    // year
    get_string(str2);
    if (atoi(str1) > 12){
        return WRONG_EXP_DATE;
    }
    if (atoi(str2) < 22){
        return WRONG_EXP_DATE;
    }
    copy_str(str1, str);
    str[2] = '/';
    str_concat( str, str,str2); 
    copy_str(str, cardData->cardExpirationDate);
    return OK_CARD;
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData){
    char str[20];
    printf("Enter card primary AccountNumber (number range 16:19 )\n");
    get_string(str);
    if(length_str(str) < 17  || length_str(str) > 20){
        return WRONG_PAN;
    }
    copy_str(str, cardData->primaryAccountNumber);
    return OK_CARD;
}
EN_cardError_t getCardData(ST_cardData_t *cardData){
    printf("Your card data is:\n");
    printf("Name: %s",cardData->cardHolderName);
    printf("Expiration Date: %s",cardData->cardExpirationDate);
    printf("primary Account Number: %s",cardData->primaryAccountNumber);
    

}