#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int number_of_students=0;


struct student
{

    char name [50];
    int ID;
    int day;
    int month;
    int year;
    float last_year_score;
};

void input(struct student* array1)
{
    for (int i =0 ; i < number_of_students ; i ++)
    {
        array1[i].day=0;
        array1[i].ID=0;
        array1[i].month=0;
        array1[i].year=0;
        array1[i].last_year_score=0;

    }

}


struct student* insert_atFirst(struct student*  array_)
{
    struct student input1;
    printf("\nInserting New Element at first..\n");
    //printf("Enter New First Element name: ");
    /*fflush(stdin);
    gets(input1.name);
*/
    printf("Enter New First Element ID: ");
    scanf("%d",&input1.ID);
    printf("Enter New First Element Day: ");
    scanf("%d",&input1.day);
    printf("Enter New First Element month: ");
    scanf("%d",&input1.month);
    printf("Enter New First Element year: ");
    scanf("%d",&input1.year);
    printf("Enter New First Element Last Year Score: ");
    scanf("%f",&input1.last_year_score);


        struct student * array2 = (struct student*) calloc(number_of_students,sizeof(struct student));
        for ( int i=0 ; i <number_of_students ; i++)
        {
            array2[i]=array_[i];

        }
        free(array_);
        array_ = (struct student*) calloc(number_of_students+1,sizeof(struct student));
        for( int i =0 ; i <number_of_students+1 ; i ++ )
        {
            if(i==0) array_[i]=input1;
            else
            {
               array_[i]=array2[i-1];
            }

        }
        number_of_students++;
         return array_;
}

struct student*  insert_atEnd(struct student* array_)
{
    struct student input1;
    printf("\nInserting New Element at last..\n");
    //printf("Enter New Last Element name: ");
    /*fflush(stdin);
    gets(input1.name);
    fflush(stdin);*/
    printf("Enter New Last Element ID: ");
    scanf("%d",&input1.ID);
    printf("Enter New Last Element Day: ");
    scanf("%d",&input1.day);
    printf("Enter New Last Element month: ");
    scanf("%d",&input1.month);
    printf("Enter New Last Element year: ");
    scanf("%d",&input1.year);
    printf("Enter New Last Element Last Year Score: ");
    scanf("%f",&input1.last_year_score);


     struct student * array2 = (struct student*) calloc(number_of_students,sizeof(struct student));
        for ( int i=0 ; i <number_of_students ; i++)
        {
            array2[i]=array_[i];

        }
        free(array_);
        array_ = (struct student*) calloc(number_of_students+1,sizeof(struct student));
        for ( int i=0; i <number_of_students ; i ++)
        {
            if(i==number_of_students-1) array_[number_of_students]=input1;
            else
            {
                array_[i]=array2[i];
            }
        }

    number_of_students++;
    return array_;


}
struct student * insert_atMiddle(struct student* array_)
{
    int index;
    printf("Enter The index of the new element: ");
    scanf("%d",&index);
    while(index<=0)
    {
        printf("Enter a valid index: ");
        scanf("%d",&index);
    }
 struct student input1;
    /*printf("Enter Input 1 name: ");
    fflush(stdin);
    gets(input1.name);*/
    printf("Enter New Element ID: ");
    scanf("%d",&input1.ID);
    printf("Enter New Element Day: ");
    scanf("%d",&input1.day);
    printf("Enter New Element month: ");
    scanf("%d",&input1.month);
    printf("Enter New Element year: ");
    scanf("%d",&input1.year);
    printf("Enter New Element Last Year Score: ");
    scanf("%f",&input1.last_year_score);

     struct student * array2 = (struct student*) calloc(number_of_students,sizeof(struct student));
        for ( int i=0 ; i <number_of_students ; i++)
        {
            array2[i]=array_[i];

        }
        free(array_);
        array_ = (struct student*) calloc(number_of_students+1,sizeof(struct student));
        for ( int i=0; i <number_of_students+1 ; i ++)
        {
           if(i<index-1)
           {
               array_[i]=array2[i];
           }
           else if(i==index-1)
           {
               array_[i]=input1;
           }
           else
           {
               array_[i]=array2[i-1];
           }

        }
number_of_students++;
 return array_;

}
void Display_array(struct student* array1)
{
    for (int i =0 ; i<number_of_students ; i ++)
    {
       printf("Student %d ID= %d\n",i+1,array1[i].ID);
       printf("Student %d Day= %d\n",i+1,array1[i].day);
       printf("Student %d Month= %d\n",i+1,array1[i].month);
       printf("Student %d Year= %d\n",i+1,array1[i].year);
       printf("Student %d Last Year Score= %f\n",i+1,array1[i].last_year_score);
    }

}



int main()
{


    printf("\n\n\n \t\t\t\t\t welcome to the students system \n\n\n");


    printf("Enter Number of Students: ");
    scanf("%d",&number_of_students);
    while(number_of_students<=0)
    {
        printf("Enter a valid Number of Students: ");
        scanf("%d",&number_of_students);
    }
    struct student* array1 = (struct student*)calloc(number_of_students,sizeof(struct student));

    input(array1);





        array1=insert_atFirst(array1);

    Display_array(array1);


    array1=insert_atEnd(array1);   // first -> last -> mid

    Display_array(array1);

    array1=insert_atMiddle(array1);
    Display_array(array1);
    free (array1);

    /*array1=insert_atEnd(array1);
    number_of_students++;
    Display_array(array1);

    array1=insert_atMiddle(array1);   last -> mid -> first
    number_of_students++;
    Display_array(array1);


    array1=insert_atFirst(array1);
    number_of_students++;
    Display_array(array1);
    free(array1);*/

    return 0;
}

