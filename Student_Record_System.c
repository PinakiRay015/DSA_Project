#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct Student
{
    int rollnumber;
    char name[100];
    char phone[100];
    float percentage;
    struct Student *next;
    
}* head;
void insert(int rollnumber, char* name, char* phone, float percentage)
{
    
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->rollnumber = rollnumber;
    strcpy(student->name, name);
    strcpy(student->phone, phone);
    student->percentage = percentage;
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
    printf("\n************************************************\n");
    printf("********STUDENT DETAILS ADDED SUCCESSFULLY*********\n");
    printf("************************************************\n");
    
}
void search(int rollnumber)
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->rollnumber==rollnumber){
            printf("\n****************\n");
            printf("Roll number: %d\n", temp->rollnumber);
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            printf("Percentage: %0.4f\n", temp->percentage);
            printf("****************\n");
            return;
        }
        temp = temp->next;
    }
    printf("\n********Student with roll number %d is not found !!!\n********", rollnumber);
}
void update(int rollnumber)
{
    
    struct Student * temp = head;
    while(temp!=NULL){
        
        if(temp->rollnumber==rollnumber){
            printf("Record with roll number %d Found !!!\n", rollnumber);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("Enter new percentage: ");
            scanf("%f",&temp->percentage);
            printf("\n************************************************\n");
            printf("********Updation Successful!!!********\n");
            printf("************************************************\n");
            return;
        }
        temp = temp->next;
        
    }
    printf("\n******Student with roll number %d is not found !!!******\n", rollnumber);
    
}
void Delete(int rollnumber)
{
    struct Student * temp1 = head;
    struct Student * temp2 = head; 
    while(temp1!=NULL){
        
        if(temp1->rollnumber==rollnumber){
            
            printf("\n***Record with roll number %d Found !!!***\n", rollnumber);
            
            if(temp1==temp2){
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1); 
            }
            printf("\n************************************************\n");
            printf("********Record Successfully Deleted !!!********\n");
            printf("************************************************\n");
            return;
            
        }
        temp2 = temp1;
        temp1 = temp1->next;
        
    }
    printf("\n********Student with roll number %d is not found !!!********\n", rollnumber);
    
}
void display()
{
    struct Student * temp = head;
    while(temp!=NULL){
        printf("\n***********HERE ARE THE DETAILS OF STUDENTS*************************************\n");
        printf("Roll Number: %d\n", temp->rollnumber);
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        printf("Percentage: %0.4f\n\n", temp->percentage);
        temp = temp->next;
        printf("**********************************************************************************\n");
    
    }
}
int main()
{
    head = NULL;
    int choice;
    char name[100];
    char phone[100];
    int rollnumber;
    float percentage;
    printf("\n\n\n\t\t******WELCOME TO STUDENT RECORD SYSTEM******\n\n\n");
    do
    {
        printf("\n1-> Insert student details\n");
        printf("2-> Search a student details\n");
        printf("3-> Delete a studen details\n");
        printf("4-> Update a student details\n");
        printf("5-> Display a student details\n");
        printf("Enter 0 to exit\n");
        printf("Enter Choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &rollnumber);
                printf("Enter name: ");
                fflush(stdin);
                scanf("%[^\n]s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter percentage: ");
                scanf("%f", &percentage);
                insert(rollnumber, name, phone, percentage);
                break;
            case 2:
                printf("Enter roll number to search: ");
                scanf("%d", &rollnumber);
                search(rollnumber);
                break;
            case 3:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollnumber);
                Delete(rollnumber);
                break;
            case 4:
                printf("Enter roll number to update: ");
                scanf("%d", &rollnumber);
                update(rollnumber);
                break;
            case 5:
                display();
                break;
        }
        
    } while (choice != 0);
}