#include <stdio.h>
#include <stdlib.h>
#include "my_clinic_prototypes.h"

int slots[5]={0};



int main (void){

	int password;
	int choose;
	int counter = 0;
	
	patient* arr_patient = NULL;
	arr_patient = (patient*) calloc(INITIAL_SZ,sizeof(patient));
	
	for(int i = 0 ; i < INITIAL_SZ ; i++){
		arr_patient[i].id = 221000+i;
	}

	int re_main = 0;
	do{
		printf("Enter 1 for admin mode\nEnter 2 for user mode \nEnter 3 to EXIT\n-> ");
		scanf("%d", &choose);
		printf("---------\n");
		int redirect = 0;
		if(choose == 1){
			
			printf("Admin's Password : ");
			
			scanf("%d", &password);
			if(check_password(password) == 0){
				exit(0);
			}
			
			printf("\nWelcome, You are in admin mode now \n\n");
			
			re_main = admin_options(arr_patient, counter);
		
		
		}
		if(choose == 2 ){
			printf("Welcome ...\n\n");
			re_main = user_options(arr_patient);
		}
		if(choose == 3){
			re_main = 0;
		}
	}while(re_main == 1);
	
	printf("\n----------THANK YOU----------\n");
	return 0 ;
}

