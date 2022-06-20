#ifndef _MY_CLINIC_PROTOTYPES_H_
#define _MY_CLINIC_PROTOTYPES_H_


#define CORRECT_PASSWORD (1234)
#define INITIAL_SZ (10)

typedef struct {
	int age;
	int id;
	char gender[6];
	char st_name[20];
	char last_name[20];
}patient;


void print_schedule_admin(int slots[], int size);
patient* add_patient(patient ptr[], int* ads_counter);
int search_id (patient ptr[], int scanned_id, int size );
void print_patient_info(patient ptr[], int location);
void edit_patient(patient ptr[]);
void reserve_slot(int slots[], int size, patient ptr[]);
void cancel_slot(int slots[], patient ptr[]);
void view_record(patient ptr[]);
void print_slot(int i);
void view_reserve (int slots[], int size, patient ptr[]);
void print_admin_options(void);
void print_user_options(void);
int check_password(int password);
int user_options(patient ptr[]);
int admin_options(patient arr_patient[], int counter);
#endif


