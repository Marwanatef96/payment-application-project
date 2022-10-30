#ifndef CARD_H_
#define CARD_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct ST_cardData_t
{
uint8_t cardHolderName[25];

uint8_t primaryAccountNumber[21];
uint8_t cardExpirationDate[6];

} ST_cardData_t;

typedef enum EN_cardError_t
{
OK_CARD, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
} EN_cardError_t;

EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);
EN_cardError_t getCardData(ST_cardData_t *cardData);
#endif
