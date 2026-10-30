#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insertAtBeginning(int value){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data=value;
    newNode->next=head;
    head=newNode;
}
void insertAtEnd(int value){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    struct node *current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
}
void deleteAtBeginning(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp=head;
    head=head->next;
    free(temp);
}
void deleteAtEnd(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    struct node *current=head;
    while(current->next->next!=NULL){
        current=current->next;
    }
    free(current->next);
    current->next=NULL;
}
void insertInMiddle(int value, int position){
    if(position<1){
        printf("Invalid position\n");
        return;
    }
    if(position==1){
        insertAtBeginning(value);
        return;
    }
    if(head==NULL ){
        printf("List is empty\n");
        return;
    }
    struct node *current=head;
    for(int i=1;i<position-1 && current!=NULL;i++){
        current=current->next;
    }
    if(current==NULL){
        printf("Position out of bounds\n");
        return;
    }
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data=value;
    newNode->next=current->next;
    current->next=newNode;
}
void deleteFromMiddle(int pos){
    if(pos<1){
        printf("Invalid position\n");
        return;
    }
    if(head==NULL ){
        printf("List is empty\n");
        return;
    }
    if(pos==1){
        deleteAtBeginning();
        return;
    }
    struct node *current=head;
    for(int i=1;i<pos-1 && current!=NULL;i++){
        current=current->next;
    }
    if(current==NULL || current->next==NULL){
        printf("Position out of bounds\n");
        return;
    }
    struct node *temp=current->next;
    current->next=temp->next;
    free(temp);
}
void search(int value){
    struct node *current=head;
    int position=1;
    while(current!=NULL){
        if(current->data==value){
            printf("Value %d found at position %d\n",value,position);
            return;
        }
        current=current->next;
        position++;
    }
    printf("Value %d not found in the list\n",value);
}
void reverse(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    struct node *prev=NULL;
    struct node *current=head;
    struct node *next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    printf("Linked list reversed successfully\n");
}
void display(){
    if(head==NULL){
        printf("Linked list is empty.\n");
        return;
    }
    struct node *current;
    current=head;
    printf("Linked list data...........\n");
    while(current!=NULL){
        printf("%d\n",current->data);
        current=current->next;
    }
}
void insert(int value){
    if(head==NULL){
        insertAtBeginning(value);
        return;
    }
    insertAtEnd(value);
}
int main(){
    struct node *first=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));
    if(first==NULL || second==NULL || third==NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    first->data=10;
    second->data=20;
    third->data=30;
    first->next=second;
    second->next=third;
    third->next=NULL;
    head=first;
    int choice,value,position;
    do{
        printf("Enter your choice\n(1.Insert at beginning,\n2.Insert at end,\n3.Delete at beginning,\n4.Delete at end,\n5.Insert in middle,\n6.Delete from middle,\n7.Search,\n8.Display,\n9.Reverse,\n10.Insert Data,\n11.Exit.): ");
        scanf("%d",&choice); 

        switch(choice){        
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d",&value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d",&value);
                insertAtEnd(value);
                break;

            case 3:
                deleteAtBeginning();
                break;

            case 4:
                deleteAtEnd();
                break;

            case 5:
                printf("Enter value and position to insert in middle: ");
                scanf("%d %d",&value,&position);
                insertInMiddle(value,position);
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d",&position);
                deleteFromMiddle(position);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d",&value);
                search(value);
                break;

            case 8:
                display();
                break;

            case 9:
                reverse();
                break;

            case 10:
                printf("Enter value to insert: ");
                scanf("%d",&value);
                insert(value);
                break;

            case 11:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
}while(choice!=11);
while (head != NULL) {
        deleteAtBeginning();
    }

return 0;
}