#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// phone book in C By Lazare Mirziashvili
// Functions I'm gonna make: Add Contact, Delete Contact, Update Contact
// Get Contacts, Get Contact (by name) 

typedef char string;

typedef struct {
	string name[100]; // e.g Lazare , Giorgi....
	string phone[100]; // e.g 123 456 789....
	int index; // e.g 1,2,3,4....
	string countryCode[3]; // e.g +995 / +1 ....	
} contact;

#define MAX_CONTACTS 100
contact CONTACTS[MAX_CONTACTS];
int CONTACTS_SIZE = 0;

int AddContact(string name[100],string phone[100],string countryCode[3]);
int DeleteContact(string name[100]);
int UpdateContact(string name[100]);
int GetContacts();
int GetContact(string name[100]);

bool compareStrings(string str1[100], string str2[100]);
int StringLength(string str[100]);

int main(void){
		
	

	return 0;
}

int StringLength(string str[100]){
	int length = 0;
	
	int i=0;
	while(str[i] != '\0'){
		i++;
		length++;
	}

	return length;
};

bool compareStrings(string str1[100], string str2[100]){
	int str1Length = StringLength(str1);
	int str2Length = StringLength(str2);

	if(str1Length < str2Length || str1Length > str2Length){
		return 1;
	}

	for(int i =0;i<str1Length;i++){
		if(str1[i] != str2[i]) return 1;
	}

	return 0;
}

int AddContact(string name[100],string phone[100],string countryCode[3]){
	for(int i =0;i<CONTACTS_SIZE;i++){
		if(compareStrings(name,CONTACTS[i].name) && compareStrings(phone,CONTACTS[i].phone)){
			printf("Contact with same number already exists !");
			return 1;
		}
	}
	
	strcpy(CONTACTS[CONTACTS_SIZE+1].name, name);
	strcpy(CONTACTS[CONTACTS_SIZE+1].phone,phone);
	CONTACTS[CONTACTS_SIZE].index = CONTACTS_SIZE;
	strcpy(CONTACTS[CONTACTS_SIZE+1].countryCode,countryCode);

	CONTACTS_SIZE++;

	printf("Added successfully !");
	return 0;
}

int DeleteContact(string name[100]){
	for(int i =0;i<CONTACTS_SIZE;i++){
		if(compareStrings(CONTACTS[i].name,name)){
			CONTACTS[i].name[0] = '\0';
			CONTACTS[i].phone[0] = '\0';
			CONTACTS[i].index = -1;
			CONTACTS[i].countryCode[0] = '\0';
			CONTACTS_SIZE--;
			printf("%s with index %d has been deleted !",CONTACTS[i].name,CONTACTS[i].index);
			return 0;
		}
	}


	printf("%s was not found !",name);
	return 1;
}

int UpdateContact(string name[100]){}
int GetContacts(){}
int GetContact(string name[100]){}
