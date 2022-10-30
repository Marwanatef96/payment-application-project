#include "server.h"
#include "card.h"
#include "terminal.h"
#include "strings.h"

int currentAccount = -1;
ST_accountsDB_t accounts[255]={{1200, "7391462851236798125"}, {7500, "7391462851236798126"}, {6000, "7391462851236798127"}, {2500, "7391462851236798128"}};

ST_transaction_t transactions[255]={0};

EN_transState_t recieveTransactionData(ST_transaction_t *transData){
     if(isValidAccount(&transData->cardHolderData) == OK_SERVER){
        if(isAmountAvailable(&transData->terminalData) == LOW_BALANCE){
        printf("DECLINED_INSUFFECIENT_FUND\n");
        return DECLINED_INSUFFECIENT_FUND;
    }
        printf("Transaction APPROVED\n");
        printf("your balance before transaction is: %f\n", accounts[currentAccount].balance);
        accounts[currentAccount].balance=accounts[currentAccount].balance-transData->terminalData.transAmount;
        printf("your balance now is:");
        printf(" %f", accounts[currentAccount].balance);
        return OK_SERVER;
    }
    if(isValidAccount(&transData->cardHolderData) == ACCOUNT_NOT_FOUND){
        printf("DECLINED_STOLEN_CARD\n");
        return DECLINED_STOLEN_CARD;
    }
    currentAccount = -1;
}

EN_serverError_t isValidAccount(ST_cardData_t *cardData){
    for(int i=0; i<255; i++){
        
        if(atoi(cardData->primaryAccountNumber)==atoi(accounts[i].primaryAccountNumber)){
            currentAccount = i;
            return OK_SERVER;
        }
    }
    return ACCOUNT_NOT_FOUND;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData){
    if(termData->transAmount > accounts[currentAccount].balance){
        return LOW_BALANCE;
    }
     return OK_SERVER;
}

EN_serverError_t saveTransaction(ST_transaction_t *transData){
    int flag = 0;
    transactions[transData->transactionSequenceNumber].cardHolderData = transData->cardHolderData;
    transactions[transData->transactionSequenceNumber].terminalData = transData->terminalData;
    transactions[transData->transactionSequenceNumber].transState = transData->transState;
    flag = 1;
    if(flag){
        return OK_SERVER;
    }
    return SAVING_FAILED;

}
