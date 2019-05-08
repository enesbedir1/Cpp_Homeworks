/*
Abdullah Enes BEDÝR 
040170743
25334
Data Structure
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

struct person {
	string name;
	string number;
	person *next;
};

int lenlist(person * r){ //calculate lenght of list 
	if (r -> name == ""){
		return 0;
	}
	int i = 0;
	while (r != NULL){
		i++;
		r = r->next;
	}
	return i;
}

void swap (person * a,person *b){ // swap two elements of list 
	person * temp = new person;
	temp -> name = a->name;
	temp -> number = a->number;
	a->name = b -> name;
	a->number = b -> number;
	b->name = temp -> name;
	b->number = temp -> number;
}


void bubblesort(person *r){ // sort the list
	int counter = lenlist(r);
	person * root;
	root = r;

	int i;
	int j;
	for (i = 0; i < counter-1;i++){
		for (j = 0; j < counter-1;j++){
			if (r->name > r->next->name){
				swap(r->name, r->next->name);
			}
		r  = r->next;
		}
		r = root;
	}
}

void printing(person * r){ // print the list
	if (r -> name == ""){
		cout << "phonebook is empty" << endl;
		return;
	}
	int i = 0;
	while (r != NULL){
		printf("***********************************\n");
		i++;
		cout <<i << ". isim: " << r -> name  << endl ;
		cout <<i << ". number: " << r -> number << endl ;
		r = r->next;
	}
	cout<<endl;
}

void alphabetical_print(person * r){ // print the list alphabetically
	int len = lenlist(r);
	if (r -> name == ""){
		cout<<"Phone Book is Empty";
		return;
	}
	bubblesort(r);
	printing(r);
	cout<<endl;
}

void add_end(person * r){ // add an element end of list
	string inputname;
	string inputnumber;
	cout << "enter name: ";
	cin >> inputname;
	cout << "enter number: ";
	cin >> inputnumber;
	
	if (r -> name == ""){
		cout<<"burayagir";
		r -> name = inputname;
		r -> number = inputnumber;
		r -> next = NULL;
		return;
	} 
	
	else if (r -> next == NULL){
		r -> next = new person; // önce yeni person oluþturuyoruz
		r = r -> next; // sonra o personýn pointerýna gidip onun name ve number ýnýn deðiþtiriyoruz.
		r -> name = inputname;
		r -> number = inputnumber;
		r -> next = NULL;
		return;
	}

	while (r -> next != NULL){
		r = r -> next;
	}
	

	person * temp = new person;
	temp -> name = inputname ;
	temp -> number = inputnumber ;
	r ->next = temp;
	r -> next -> next = NULL;
	return;
}

person * add_beg(person * r){ // add an element beginning of list
	string inputname;
	string inputnumber;
	cout << "enter name: ";
	cin >> inputname;
	cout << "enter number: ";
	cin >> inputnumber;

	if (r -> name == ""){
		r -> name = inputname;
		r -> number = inputnumber;
		r -> next = NULL;
		return r;
	} 

	person *temp = new person ;
	temp -> name  = inputname ;
	temp -> number = inputnumber ;
	temp -> next = r ;
	return temp; 
}

void add_middle(person * r){ // add an element middle of list
	int len = lenlist(r);
	string inputname;
	string inputnumber;
	cout << "enter name: ";
	cin >> inputname;
	cout << "enter number: ";
	cin >> inputnumber;
	person * temp = new person;
	temp -> name = inputname;
	temp -> number = inputnumber;
	if (r -> name == ""){
		r -> name = inputname;
		r -> number = inputnumber;
		r -> next = NULL;
		return;
	}
	int i;
	for (i = 0; i < (len/2) -1 ; i++){
		r = r -> next;
	}
	temp->next = r->next; 
    r->next = temp; 
}

void search_name(person * r){ // search a name in the list
	string search_name;
	cout << "Enter the name you want to search :";
	cin >> search_name;
	if (r -> name == ""){
		cout <<"phonebook is empty !!" << endl;
		return;
	} 
	while (r != NULL){
		cout << "search name: "<< search_name <<endl;
		cout << "  name: " << r -> name <<endl;
		if (search_name == r -> name){
			cout << "Phone number of " << search_name << " is " << r -> number << endl ;
			return;
		}
		r = r -> next;
	}
	cout <<search_name <<" cannot be found !";
}

void update_name(person * r){ // update an element of list
	int index,len,i;
	string new_name;
	string new_number;
	len = lenlist(r);
	cout << "lenght of linked list: " << len <<endl;
	printing(r);
	cout << "Enter the index you want to update: ";
	cin >> index;
	if (index > len ){
		cout<<"Index is out of range ";
		return;
	}
	
	for (i=0;i<index-1;i++){
		r = r -> next;
	}
	
	cout << r -> name <<" will change" <<endl;
	cout <<"Enter new name to update : ";
	cin >> new_name;
	cout <<"Enter new number to update : ";
	cin >> new_number;
	r -> name = new_name;
	r -> number = new_number;
}

void add_alp(person * r){ // add an element alphabetically
	add_end(r);
	bubblesort(r);
}

int main (){

	person* root = new person; 
	int command;
	while (1) {
		cout << "To exit PRESS 0" << endl;
		cout << "PRESS 1 to insert at the beggining " << endl;
		cout << "PRESS 2 to insert at the middle " << endl;
		cout << "PRESS 3 to insert at the end " << endl;
		cout << "PRESS 4 to insert to the phonebook alphabetically " << endl;
		cout << "PRESS 5 to search name " << endl;
		cout << "PRESS 6 To update record " << endl;
		cout << "PRESS 7 To print " << endl;
		cout << "PRESS 8 To print alphabetically " << endl;
		
		cout << "Enter your selection:";
		cin >> command;
		if (command == 0) {
			break;
		}
		if (command == 1) {
			root = add_beg(root);
		}
		else if (command == 2) {
			add_middle(root);
		}
		else if (command == 3) {
			add_end(root);
		}
		else if (command == 4) {
			add_alp(root);
		}
		else if (command == 5) {
			search_name(root);
		}
		else if (command == 6) {
			update_name(root);
		}
		else if (command == 7) {
			printing(root);
		}
		else if (command == 8) {
			alphabetical_print(root);
		}
		else {
			cout << "Please enter a appropriate number" << endl;
		}
		if (command == 0) {
			break;
		}
	}
}		
	
/*	add_end(root);
	counter++;

	add_end(root);
	counter++;

	add_end(root);
	counter++;

	add_end(root);
	counter++;

	add_end(root);
	counter++;

	add_end(root);
	counter++;

	printing(root);
	
	alphabetical_print(root,counter);*/
	
	
	
	//cout << root -> next -> next -> next -> name << endl;
	//cout << root -> next -> next -> next -> number << endl;

/*	
		
		while (1) {
			cout << "To exit PRESS 0" << endl;

			cout << "To list the phonebook alphabetically PRESS 1" << endl;
			cout << "To search name press PRESS 2" << endl;
			cout << "To update record press PRESS 3" << endl;
			cout << "To insert at the beggining PRESS 4" << endl;
			cout << "To insert at the middle PRESS 5" << endl;
			cout << "To insert at the end PRESS 6" << endl;
			cout << "To print list non-alphabetically PRESS 7" << endl;
			cin >> command;
			if (command == "0") {
				break;
			}
			if (command == "1") {
				cout<<"";
			}
			else if (command == "2") {
				cout<<""; //list.list_alphabetically(head);
			}
			else if (command == "3") {
				cout << "Search name" << endl;
				
				cout<<""; //list.search(head, isim);
			}
			else if (command == "4") {
				root = add_beg(root);
			}
			else if (command == "5") {
				root = add_beg(root);
			}
			else if (command == "6") {
				add_end(root);
			}
			else if (command == "7") {
				add_end(root);
			}
			else if (command == "8") {
				cout<<""; //list.print_list(head);
			}
			else {
				cout << "Please enter a appropriate number" << endl;
			}
			if (command == "0") {
				break;
			}
		}
*/

