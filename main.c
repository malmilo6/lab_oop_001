#include "fun.h"

int main()
{
    struct node * head = NULL;
    struct node * head_sup = NULL;
    struct node * merged = NULL;
    struct node * DLL = NULL;

    int node, index, n;

    int key = 1;
    while(key != 0)
    {
        
        printf("\n\t1  Append\n");
        printf("\t2  Prepend\n");
        printf("\t3  Reverse\n");
        printf("\t4  Add a value at the index\n");
        printf("\t5  Remove a value from the index\n");
        printf("\t6  Sort the linked list\n");
        printf("\t7  Search for a value\n");
        printf("\t8  Join Linked two lists\n");
        printf("\t9  Backwards traversal using double-linked-list\n");
        printf("\t10 Print list\n");
        printf("\t11 Print merged list\n");
        printf("\t12 Write the list into the file\n");
        printf("\t13 Read the list from the file\n");
        printf("\t0  Quit\n");
       
        scanf("%d", &key);

                switch (key) {
        case 1:
            printf("Enter node - ");
            scanf("%d",&node);
            appendNode(&head,node);
            break;
        case 2:
            printf("Enter node - ");
            scanf("%d",&node);
            prependNode(&head,node);
            break;
        case 3:
            reverselist(&head);
            break;
        case 4:
            printf("Enter index - ");
            scanf("%d",&index);
            printf("\nEnter node - ");
            scanf("%d",&node);
            insertAt(&head,node,index);
            break;
        case 5:
            printf("Enter index - ");
            scanf("%d",&index);
            removeFrom(&head, index);
            break;
        case 6:
            insertSort(&head);
            break;
        case 7:
            printf("Enter node - ");
            scanf("%d",&node);
            if(searchValue(head,node))
            {
                printf("Value exists\n");
            }
            else
            {
                printf("\n Value doesn't exist\n");
            }
            break;
        case 8:
            printf("\nHow many elements to be in 2nd list?\n");
            scanf("%d",&n);
            printf("Enter the nodes\n");
            for(int i = 0; i < n; i++)
            {
                printf("Enter node - ");
                scanf("%d",&node);
                appendNode(&head_sup,node);
            }
            merged = mergeLists(head,head_sup);
            break;
        case 9:
            printf("\n Enter the number of elements for DLL\n");
            scanf("%d",&n);
            for(int i = 0; i < n; i++)
            {
                printf("Enter node - ");
                scanf("%d",&node);
                appendDLL(&DLL,node);
            }
            printf("\nDLL");
            printDLL(DLL);
            reverseDLL(&DLL);
            printf("\nDLL in reverse order");
            printDLL(DLL);

            break;
        case 10:
            print(head);
            break;
        case 11:
            print(merged);
            break;
        case 12:
            writeNodes(head);
            break;
        case 13:
            readNodes(&head);
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("\n Invalid input");

        }
        printf("===================================");
    }
    
    return 0;
}