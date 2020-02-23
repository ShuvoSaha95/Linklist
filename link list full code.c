#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list *next;
}node;



void insert(node *cur_node, int a){
    while(cur_node->next != NULL){
        cur_node = cur_node->next;
    }

    node *new_node = (node*)malloc(sizeof(node));

    new_node->data = a;
    new_node->next = NULL;
    cur_node->next = new_node;
}

void insert_before(node *cur_node, int node_number, int a){
    node *prev_node;
    int cnt = 0;
    while(cur_node->next != NULL){
            if(cnt == node_number){
                node *new_node = (node*)malloc(sizeof(node));

                new_node->data = a;
                new_node->next = prev_node->next;

                prev_node->next = new_node;

            }else{
                prev_node = cur_node;
                cur_node = cur_node->next;
            }
        cnt++;
    }
}


void insert_after(node *cur_node, int node_number, int a){
    node *prev_node;
    int cnt = 0;
    while(cur_node->next != NULL){
            if(cnt == node_number+1){
                node *new_node = (node*)malloc(sizeof(node));

                new_node->data = a;
                new_node->next = prev_node->next;

                prev_node->next = new_node;

            }else{
                prev_node = cur_node;
                cur_node = cur_node->next;
            }
        cnt++;
    }
}

void delete_node(node *cur_node, int del_node_num){
    node *prev_node;
    int cnt = 0;
    while(cur_node->next != NULL){
            if(cnt == del_node_num){
                node *next_node_adrs = cur_node->next;
                prev_node->next = next_node_adrs;

            }else{
                prev_node = cur_node;
                cur_node = cur_node->next;
            }
        cnt++;
    }
}

void display(node *s){
    int cnt = 0;
    while(s->next != NULL){
        s = s->next;
        cnt++;
        printf("%d Node Data = %d\n",cnt,s->data);

    }

    printf("Number of Node : %d\n",cnt);
}

void search(node *cur_node, int search_data){
    int cnt = 1;
    cur_node = cur_node->next;
    while(cur_node->next != NULL){
        if(cur_node->data == search_data){
            printf("Data Found Node Number = %d\n",cnt);
        }
        cur_node = cur_node->next;
        cnt++;
    }
}

int main()
{
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;

    int selection;
    int data;
    int node_number;
    while(1){
        printf("\n1 => Insert");
        printf("\n2 => Insert Before");
        printf("\n3 => Insert After");
        printf("\n4 => Delete");
        printf("\n5 => Display");
        printf("\n6 => Search");
        printf("\n7 => Exit\n");
        printf("Enter input: ");
        scanf("%d",&selection);

        switch(selection){
        case 1:
            printf("\nEnter List Data: ");
            scanf("%d",&data);
            insert(head,data);
            break;

        case 2:
            printf("\nEnter Node Number: ");
            scanf("%d",&node_number);
            printf("\nEnter List Data: ");
            scanf("%d",&data);
            insert_before(head,node_number,data);
            break;

        case 3:
            printf("\nEnter Node Number: ");
            scanf("%d",&node_number);
            printf("\nEnter List Data: ");
            scanf("%d",&data);
            insert_after(head,node_number,data);
            break;

        case 4:
            printf("\nEnter Node Number: ");
            scanf("%d",&data);
            delete_node(head,data);
            break;
        case 5:
            display(head);
            break;
        case 6:
            printf("\nEnter Search Data: ");
            scanf("%d",&data);
            search(head,data);
            break;
        case 7:
            return 0;
        default:
            printf("Wrong input !\n");
        }
    }
    return 0;
}
