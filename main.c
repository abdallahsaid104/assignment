#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    char name [50];    //data
    int ID;
    int day;
    int month;
    int year;
    int last_year_score;
    struct Student*next; //next is pointer to the next node (student)

//struct student is a Self Referential structure that have one or more
//pointers which point to the same type of structure, as their member.

}*head,*tail;   //Global pointers of type student that will point to the first node

int  count_nodes()
{

int count=0;
struct Student* temp = head;
while (temp!=NULL)
{
    count++;
    temp=temp->next;
}
return count;
}

//insert_beginning Function should take student details as argument and create new node with those details at the beginning
void insert_beginning (char* name,int ID , int day , int month , int year , int last_year_score)
{

    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
	student->ID = ID;
	strcpy(student->name, name);
	student->last_year_score = last_year_score;
	student->day=day;
	student->month=month;
	student->year=year;
	student->next = NULL;

	if(head==NULL){
		// if head is NULL
		// set student as the new head
		head = student;
	}
	else{
		// if list is not empty
		// insert student in beginning of head
		student->next = head;
		head = student;
	}


}


void insert_end (char* name,int ID , int day , int month , int year , float last_year_score)
{

    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
	student->ID = ID;
	strcpy(student->name, name);
	student->last_year_score = last_year_score;
	student->day=day;
	student->month=month;
	student->year=year;
	student->next = NULL;
    tail=head;
    while(tail != NULL && tail->next != NULL)
    {
        tail=tail->next;
    }

        student->next = NULL;
        tail->next = student;
        tail=student;

}

void insert_mid (char* name,int ID , int day , int month , int year , int last_year_score,int position)
{

    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
	student->ID = ID;
	strcpy(student->name, name);
	student->last_year_score = last_year_score;
	student->day=day;
	student->month=month;
	student->year=year;
	student->next = NULL;
    struct Student *temp;

	if(head==NULL){
		// if head is NULL
		// set student as the new head
		head = student;
	}
	else{
		// if list is not empty
		// insert student in beginning of head

        int length=count_nodes();
		if (position==1)
        {
            insert_beginning( name, ID , day , month , year , last_year_score);
        }

        else if (position==length)
        {
            insert_end( name, ID , day , month , year , last_year_score);
        }
       else if (position>length+1 || position<1)
       {
           printf("Error! \nThe length of the list is %d \nPlease choose an integer appropriate position!\n\n",length);
       }
        else {
        temp=head;
		for (int i=0;i<position-2;i++)
        {
            temp=temp->next;
        }
            student->next=temp->next;
            temp->next=student;
	}

	}
}
void display()
{
    struct Student * temp = head;
    while(temp!=NULL ){

        printf("Name: %s\n", temp->name);
        printf("ID: %d\n", temp->ID);
        printf("Percentage: %d \n", temp->last_year_score);
        printf("Birth Date: %d/%d/%d\n\n",temp->day,temp->month,temp->year);
        temp = temp->next;
    }
    }


int main()
{

    printf("\n\n\n \t\t\t\t\t Welcome to The Student Management System \n\n\n");

    insert_beginning("Sohila",1000,3,3,2001,83);
    insert_beginning("Abdallah",1001,10,4,2000,84);
    insert_end("3abbas",999,2,8,1980,67);
    insert_beginning("Yara",1003,6,4,2006,95);
    insert_beginning("Menna",1004,19,11,2002,70);
    insert_beginning("Abdelaziz",1005,17,10,2000,88);
    insert_mid("Salma",1002,15,6,2000,75,7);
    insert_end("3absame3",998,6,12,1986,69);
    insert_mid("Sarah",997,12,4,1957,65,12);
    display();
    return 0;
}
