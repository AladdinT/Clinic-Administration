#include <stdio.h>
#include <stdlib.h>
#include "my_clinic_prototypes.h"

extern int slots[5];


void print_schedule_admin(int slots[], int size){
	printf("Slot (1)        Slot (2)    Slot (3)        Slot (4)         Slot (5)\n");
	printf("2:00-2:30pm, 2:30-3:00pm, 3:00-3:30pm,    4:00-4:30pm,    4:30-5:00pm\n");
	for(int i = 0; i < size ; i++){
		/*if(slots[i] == 0){
			printf("%d\t\t", slots[i]);
		}else{
			printf("N/A\t\t");
		}*/
		printf("%d\t\t", slots[i]);
	}
	printf("-------------\n");
}
patient* add_patient(patient ptr[], int* ads_counter){
	patient* ptr_holder = ptr;
	printf("Patient ID : %d\n", (ptr[*ads_counter].id) );
	
	printf("First Name : ");
	scanf("%s", (ptr[*ads_counter].st_name));
	
	printf("Last Name  : ");
	scanf("%s", (ptr[*ads_counter].last_name));

	printf("Gender : ");
	scanf("%s" ,&( ptr[*ads_counter].gender ));
	
	printf("Age : ");
	scanf("%d", &(ptr[*ads_counter].age) );
	(*(ads_counter))++;
	printf("----> counter = %d", *ads_counter);
	if( (*ads_counter) % INITIAL_SZ == 0){
		printf("in");
		patient* extra_size = (patient*) realloc(ptr, (INITIAL_SZ+*ads_counter) * sizeof(patient) );
		if( extra_size != ptr ){
			printf("iaan");
			free(ptr);
		}
		ptr_holder = extra_size;
		for(int i = 0 ; i < INITIAL_SZ ; i++ ){
			ptr_holder[i+INITIAL_SZ].id = 221000+INITIAL_SZ+i;
		}
	}
	
	printf("------------\n");
	return ptr_holder;
}
int search_id (patient ptr[], int scanned_id, int size ){
	int ret = -1;
	for(int i = 0 ; i < size ; i++){
		if(ptr[i].id == scanned_id){
			ret = i;
			printf("S\n");
			break;
		}else{
			ret = -1;
		}
	}
	return ret;
}
void print_patient_info(patient ptr[], int location){
	printf("Patient ID   : %d\n", ptr[location].id);
	printf("First Name   : %s\n", ptr[location].st_name);
	printf("Last Name    : %s\n", ptr[location].last_name);
	printf("Gender  : %s\n", ptr[location].gender);
	printf("Age     : %d\n", ptr[location].age);
	printf("---------------\n");
}
void edit_patient(patient ptr[]){
	int scanned_id;
	int location;
	int edit = 0;
	printf("\n");
	do{
		printf("Enter Patient id : ");
		scanf("%d", &scanned_id);
		
		location = search_id(ptr, scanned_id, INITIAL_SZ);
		
		if(location == -1){
			printf("Wrong ID.\n");
		}else{
			print_patient_info(ptr,location);
		}
	}while(location == -1);
	printf("Enter 1 to edit data. 0 to go back\n->");
	scanf("%d", &edit);
	if(edit == 1){
		printf("Patient ID : %d\n", (ptr[location].id) );
		printf("New First Name : ");
		scanf("%s", (ptr[location].st_name));
		printf("New Last Name  : ");
		scanf("%s", (ptr[location].last_name));
		printf("Gender : ");
		scanf("%s" ,&( ptr[location].gender ));
		printf("New Age : ");
		scanf("%d", &(ptr[location].age) );
	}
	printf("-------------\n");
}
void reserve_slot(int slots[], int size, patient ptr[]){
	int res, redirect, res_id;
	printf("Reserving  a slot\n");
	print_schedule_admin(slots,size);
	do{
		printf("Reserve slot number : ");
		scanf("%d",&res);
		if( (slots[res-1] == 0) && (res <= size) && (res > 0)){
			redirect = 0;
			do{
				printf("Enter patient id : ");
				scanf("%d", &res_id);
				if( search_id(ptr, res_id, INITIAL_SZ) != -1){
					slots[res-1] = res_id;
					break;
				}else{
					printf("invalid ID.\n");
				}
			}while(1);
		}else if(res > size || res <= 0){
			printf("Please entre a valid slot \n-> ");
			redirect = 1;
		}else{
			printf("Slot already reserved. Please choose another slot\n-> ");
			redirect = 1;
		}
	}while(redirect == 1);
	printf("---------\n");
}


void cancel_slot(int slots[], patient ptr[]){
	int slot;
	print_schedule_admin( slots, 5);
	printf("Pick a slot to cancel its reservation : ");
	scanf("%d", &slot);
	slots[slot-1] = 0;
	printf("--------\nNew Schedule\n");
	print_schedule_admin(slots, 5);
}

void view_record(patient ptr[]){
	int id, location;
	do{
		printf("Enter Patient ID : ");
		scanf("%d", &id);
		location = search_id(ptr , id, 5);
		if( location == -1){
			printf("Invalid ID.\n");
		}else{
			print_patient_info(ptr , location);
			break;
		}
	}while(1);
}
void print_slot(int i){
	switch(i){
		case 0:
		printf("You have a Reservation at 2:00 pm to 2:30pm\n");
		break;

		case 1:
		printf("You have a Reservation at 2:00 pm to 2:30pm\n");
		break;

		case 2:
		printf("You have a Reservation at 2:00 pm to 2:30pm\n");
		break;

		case 3:
		printf("You have a Reservation at 2:00 pm to 2:30pm\n");
		break;

		case 4:
		printf("You have a Reservation at 2:00 pm to 2:30pm\n");
		break;
		
		default:
		printf("No Reservation found for this ID \n");
		break;
	}
	printf("-----------\n");
}
void view_reserve (int slots[], int size, patient ptr[]){
	int id, location, match;
	match = 0;
	int re_do = 0;
	do{
		printf("Enter Patient ID : ");
		scanf("%d", &id);
		location = search_id(ptr , id, 5);
		if(location == -1){
			printf("Invalid ID.\n");
			re_do = 1;
		}else{
			re_do = 0;
			for(int i = 0 ; i < 5 ; i++){
				if(slots[i] == id){
					print_slot(i);
					match ++;
				}else if(i == 4 && match == 0){
					printf("No Reservations found\n");
				}
			}
		}
	}while(re_do == 1);
	printf("---------\n");
}
void print_admin_options(void){
	printf("-------------\n");
	printf("Enter 1 to add new patient record\nEnter 2 to Edit patient record\n");
	printf("Enter 3 to Reserve a slot with the doctor\nEnter 4 to cancel reservation");
	printf("\nEnter 5 to log out");
	printf("\n->");
}

void print_user_options(void){
	printf("Enter 1 to view patient record\nEnter 2 to view reservations");
	printf("\nEnter 3 to go to Home page");
	printf("\n->");
}

int check_password(int password){
	if(password != CORRECT_PASSWORD){

		for(int i = 1 ; i < 3 ; i++){
			printf("Incorrect passord , You have %d more tries\n\n", 3-i);
			printf("Admin's Password : ");
			scanf("%d", &password);
			if(password == CORRECT_PASSWORD){
				break;
			}else if(i == 2){
				printf("Incorrect. No more tries \n");
				return 0;
			}else{
				continue;
			}
		}
	}
}
int user_options(patient ptr[]){
	int choose;
	int redirect = 1;
	int re_main = 0; 
	do{
		print_user_options();
		scanf("%d", &choose);
		printf("----------\n");
		switch(choose){
			case 1: 
			view_record(ptr);
			break;
			
			case 2: 
			view_reserve(slots, 5, ptr);
			break;
			
			case 3:
			re_main = 1;
			redirect = 0;
			printf("----------\n");
			break;
			
			default:
			printf("Invalid option. Please choose again ");
			printf("\n->");
			redirect = 1;
			break;
		}
	}while(redirect == 1);

	return re_main;
}


int admin_options(patient arr_patient[], int counter){
	int choose;
	int redirect;
	int re_main;
	do{
		redirect = 1;
		print_admin_options();
		scanf("%d", &choose);
		printf("----------\n");
		switch(choose){
			case 1:
			arr_patient = add_patient(arr_patient, &counter);
			break;
			
			case 2:
			edit_patient(arr_patient);
			break;
			
			case 3:
			reserve_slot(slots, 5, arr_patient);
			break;
			
			case 4:
			cancel_slot(slots, arr_patient);
			break;
			
			case 5:
			re_main = 1;
			redirect = 0;
			break;
			
			default:
			printf("Invalid option. Please choose again ");
			printf("\n->");
			redirect = 1;
			break;
		}
	}while(redirect == 1);
	
	return re_main;
	
}
