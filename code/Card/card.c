#include "card.h"
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
    char monthtr[3];
    char yearStr[3];
    printf("Enter card Expiration date (in MM/YY format)\n");
    scanf("%s",&cardData->cardExpirationDate);
    while(checkexd(cardData->cardExpirationDate)==1||length_str(cardData->cardExpirationDate)>5){
        printf("WRONG FORMAT ENTER AGAIN (in MM/YY format) \n");
        scanf("%s",&cardData->cardExpirationDate);
    }
    str_slice(cardData->cardExpirationDate, 0, 1, monthtr);
    str_slice(cardData->cardExpirationDate, 3, 4, yearStr);
    if (atoi(monthtr) > 12){
        return WRONG_EXP_DATE;
    }
    if (atoi(yearStr) < 22){
        return WRONG_EXP_DATE;
    }
    return OK_CARD;
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData){
     char str[20];
    printf("Enter card primary AccountNumber (number range 16:19 )\n");
    copy_str( cardData->cardExpirationDate,str);
    scanf("%s",&cardData->primaryAccountNumber);
    if(length_str(cardData->primaryAccountNumber) < 17  || length_str(cardData->primaryAccountNumber) > 20){
        cardData->primaryAccountNumber[0]='\0';
        copy_str( str,cardData->cardExpirationDate);
        return WRONG_PAN;
    }
    return OK_CARD;
}
EN_cardError_t getCardData(ST_cardData_t *cardData){
    printf("Your card data is:\n");
    printf("Name: %s",cardData->cardHolderName);
    printf("Expiration Date: %s\n",cardData->cardExpirationDate);
    printf("primary Account Number: %s\n",cardData->primaryAccountNumber);
    

}