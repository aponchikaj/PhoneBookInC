#include <stdio.h>

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

int contactsLength = 0;
contact CONTACTS[contactsLength];

void AddContact(string name[100],string phone[100],string countryCode[3]);
void DeleteContact(string name[100]);
void UpdateContact(string name[100]);
void GetContacts();
void GetContact(string name[100]);

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

void AddContact(string name[100],string phone[100],string countryCode[3]){
	
}

void DeleteContact(string name[100]){}
void UpdateContact(string name[100]){}
void GetContacts(){}
void GetContact(string name[100]){}
