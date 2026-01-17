#include <stdio.h>
#define MAX 5

/* Structure for student */
struct Student {
    int roll;
    char name[20];
};
/* Global variables */
struct Student cq[MAX];
int front = 0, rear = 0;
/* Function declarations */
void enqueue();
void dequeue();
void display();

int main()
{
    int choice;

    do
    {
        printf("\n--- Bus Pass Distribution System ---");
        printf("\n1. Apply for Bus Pass");
        printf("\n2. Distribute Bus Pass");
        printf("\n3. Display Waiting Students");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Program Ended\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

/* Apply for Bus Pass (Enqueue) */
void enqueue()
{
    if ((rear + 1) % MAX == front)
    {
        printf("Waiting list is FULL\n");
        return;
    }

    rear = (rear + 1) % MAX;

    printf("Enter Roll Number: ");
    scanf("%d", &cq[rear].roll);
    printf("Enter Name: ");
    scanf("%s", cq[rear].name);

    printf("Student added to waiting list\n");
}

/* Distribute Bus Pass (Dequeue) */
void dequeue()
{
    if (front == rear)
    {
        printf("No students waiting\n");
        return;
    }

    front = (front + 1) % MAX;

    printf("\nBus Pass Distributed To:");
    printf("\nRoll No: %d", cq[front].roll);
    printf("\nName   : %s\n", cq[front].name);
}

/* Display Waiting Students */
void display()
{
    int i;

    if (front == rear)
    {
        printf("No students in waiting list\n");
        return;
    }

    printf("\nStudents Waiting for Bus Pass:\n");
    i = (front + 1) % MAX;

    while (i != (rear + 1) % MAX)
    {
        printf("Roll No: %d | Name: %s\n", cq[i].roll, cq[i].name);
        i = (i + 1) % MAX;
    }
}
