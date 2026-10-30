#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
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
    newNode->prev=NULL;
    newNode->next=head;
    if(head!=NULL){
        head->prev=newNode;
    }
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
        newNode->prev=NULL;
        head=newNode;
        return;
    }
    struct node *current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
    newNode->prev=current;
}
void deleteAtBeginning(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
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
    while(current->next!=NULL){
        current=current->next;
    }
    current->prev->next=NULL;
    free(current);
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
    if(head==NULL){
        printf("Position out of bounds\n");
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
    newNode->prev=current;
    if(current->next!=NULL){
        current->next->prev=newNode;
    }
    current->next=newNode;
}
void deleteFromMiddle(int pos){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    if(pos<1){
        printf("Invalid position\n");
        return;
    }
    if(pos==1){
        deleteAtBeginning();
        return;
    }
    struct node *current=head;
    for(int i=1;i<pos && current!=NULL;i++){
        current=current->next;
    }
    if(current==NULL){
        printf("Position out of bounds\n");
        return;
    }
    current->prev->next=current->next;
    if(current->next!=NULL){
        current->next->prev=current->prev;
    }
    free(current);
}
void search(int value){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
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
void display(){
    if(head==NULL){
        printf("Linked list is empty.\n");
        return;
    }
    struct node *current=head;
    printf("Linked list elements:\n");
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
    int choice,value,position;
    do{
        printf("Enter your choice\n(1.Insert at beginning,\n2.Insert at end,\n3.Delete at beginning,\n4.Delete at end,\n5.Insert in middle,\n6.Delete from middle,\n7.Search,\n8.Display,\n9.Insert Data,\n10.Exit.): ");
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
                printf("Enter value to insert: ");
                scanf("%d",&value);
                insert(value);
                break;

            case 10:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
}while(choice!=10);

while (head != NULL) {
        deleteAtBeginning();
    }

return 0;
}