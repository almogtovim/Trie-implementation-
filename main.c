#include <stdio.h>
#include "myBank.h"


int main(){
	char operator = ' ';
	while (operator != 'E'){
		printf("Please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n ");
		scanf(" %c", &operator);
		switch(operator){
			case 'O':
            	O();
            	break;
        	case 'B':
            	B();
            	break;
        	case 'D':
            	D();
            	break;
        	case 'W':
				W();
            	break;
			case 'C':
				C();
            	break;
			case 'I':
				I();
            	break;
			case 'P':
				P();
            	break;
			case 'E':
				E();
				return 0;
            	break;
			default:
				printf("Invalid transaction type \n");
		}
	}
	return 0;
}