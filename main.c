#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 5

void listNameCards();
void addNameCard();
void removeNameCard();
void getNameCard();

struct nameCard{
    int nameCardID;
    char personName[20];
    char companyName[20];
};

struct nameCard people[MAX];

int count = 0;

char nullStr[20];

int main()
{
    int choice;

    printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM:\n");
    printf("1: listNameCards()\n");
    printf("2: addNameCard()\n");
    printf("3: removeNameCard()\n");
    printf("4: getNameCard()\n");
    printf("5: quit\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);

    while(choice != 5)
    {
        switch(choice){
            case 1:
                listNameCards();
                break;
            case 2:
                addNameCard();
                break;
            case 3:
                removeNameCard();
                break;
            case 4:
                getNameCard();
                break;
        }
        printf("Enter your choice:\n");
        scanf("%d",&choice);
    }
    return 0;
}

void listNameCards()
{
    printf("listNameCards():\n");
    if(count !=0)
    {
        int i;
        for (i=0;i<count;i++)
        {
            printf("nameCardID: %d\n", people[i].nameCardID);
            printf("personName: %s\n", people[i].personName);
            printf("companyName: %s\n", people[i].companyName);
        }
    }
    else
        printf("The name card holder is empty\n");
}

void addNameCard()
{
    char *p, dummy, nameID[20], companyID[20];
    int numID, k;

    printf("addNameCard():\n");

    printf("Enter nameCardID:\n");
    scanf("%d", &numID);

    printf("Enter personName:\n");
    scanf("%c",&dummy);
    fgets(nameID,20,stdin);
    if(p=strchr(nameID,'\n'))
        *p = '\0';

    printf("Enter companyName:\n");
    fgets(companyID,20,stdin);
    if(p=strchr(companyID,'\n'))
        *p = '\0';

    for(k=0;k<5;k++)
    {
        if(numID == people[k].nameCardID)
        {
            printf("The nameCardID has already existed\n");
            return;
        }
    }

    if(count==MAX)
        printf("The name card holder is full\n");
    else
    {
        if(count==0)
        {

            people[0].nameCardID = numID;
            strcpy(people[0].personName,nameID);
            strcpy(people[0].companyName,companyID);
        }
        else if(count==1)
        {
            if(numID>people[0].nameCardID)
            {
                people[1].nameCardID = numID;
                strcpy(people[1].personName,nameID);
                strcpy(people[1].companyName,companyID);
            }
            else
            {
                people[1].nameCardID = people[0].nameCardID;
                strcpy(people[1].personName,people[0].personName);
                strcpy(people[1].companyName,people[0].companyName);

                people[0].nameCardID = numID;
                strcpy(people[0].personName,nameID);
                strcpy(people[0].companyName,companyID);
            }
        }
        else if(count==2)
        {
            if(numID>people[0].nameCardID)
            {
                if(numID>people[1].nameCardID)
                {
                    people[2].nameCardID = numID;
                    strcpy(people[2].personName,nameID);
                    strcpy(people[2].companyName,companyID);
                }
                else
                {
                    people[2].nameCardID = people[1].nameCardID;
                    strcpy(people[2].personName,people[1].personName);
                    strcpy(people[2].companyName,people[1].companyName);

                    people[1].nameCardID = numID;
                    strcpy(people[1].personName,nameID);
                    strcpy(people[1].companyName,companyID);
                }
            }
            else
            {
                people[2].nameCardID = people[1].nameCardID;
                strcpy(people[2].personName,people[1].personName);
                strcpy(people[2].companyName,people[1].companyName);

                people[1].nameCardID = people[0].nameCardID;
                strcpy(people[1].personName,people[0].personName);
                strcpy(people[1].companyName,people[0].companyName);

                people[0].nameCardID = numID;
                strcpy(people[0].personName,nameID);
                strcpy(people[0].companyName,companyID);
            }
        }
        else if(count==3)
        {
            if(numID>people[0].nameCardID)
            {
                if(numID>people[1].nameCardID)
                {
                    if(numID>people[2].nameCardID)
                    {
                        people[3].nameCardID = numID;
                        strcpy(people[3].personName,nameID);
                        strcpy(people[3].companyName,companyID);
                    }
                    else
                    {
                        people[3].nameCardID = people[2].nameCardID;
                        strcpy(people[3].personName,people[2].personName);
                        strcpy(people[3].companyName,people[2].companyName);

                        people[2].nameCardID = numID;
                        strcpy(people[2].personName,nameID);
                        strcpy(people[2].companyName,companyID);
                    }
                }
                else
                {
                    people[3].nameCardID = people[2].nameCardID;
                    strcpy(people[3].personName,people[2].personName);
                    strcpy(people[3].companyName,people[2].companyName);

                    people[2].nameCardID = people[1].nameCardID;
                    strcpy(people[2].personName,people[1].personName);
                    strcpy(people[2].companyName,people[1].companyName);

                    people[1].nameCardID = numID;
                    strcpy(people[1].personName,nameID);
                    strcpy(people[1].companyName,companyID);
                }
            }
            else
            {
                people[3].nameCardID = people[2].nameCardID;
                strcpy(people[3].personName,people[2].personName);
                strcpy(people[3].companyName,people[2].companyName);

                people[2].nameCardID = people[1].nameCardID;
                strcpy(people[2].personName,people[1].personName);
                strcpy(people[2].companyName,people[1].companyName);

                people[1].nameCardID = people[0].nameCardID;
                strcpy(people[1].personName,people[0].personName);
                strcpy(people[1].companyName,people[0].companyName);

                people[0].nameCardID = numID;
                strcpy(people[0].personName,nameID);
                strcpy(people[0].companyName,companyID);
            }
        }
        else if(count==4)
        {
            if(numID>people[0].nameCardID)
            {
                if(numID>people[1].nameCardID)
                {
                    if(numID>people[2].nameCardID)
                    {
                        if(numID>people[3].nameCardID)
                        {
                            people[4].nameCardID = numID;
                            strcpy(people[4].personName,nameID);
                            strcpy(people[4].companyName,companyID);
                        }
                        else
                        {
                            people[4].nameCardID = people[3].nameCardID;
                            strcpy(people[4].personName,people[3].personName);
                            strcpy(people[4].companyName,people[3].companyName);

                            people[3].nameCardID = numID;
                            strcpy(people[3].personName,nameID);
                            strcpy(people[3].companyName,companyID);
                        }
                    }
                    else
                    {
                        people[4].nameCardID = people[3].nameCardID;
                        strcpy(people[4].personName,people[3].personName);
                        strcpy(people[4].companyName,people[3].companyName);

                        people[3].nameCardID = people[2].nameCardID;
                        strcpy(people[3].personName,people[2].personName);
                        strcpy(people[3].companyName,people[2].companyName);

                        people[2].nameCardID = numID;
                        strcpy(people[2].personName,nameID);
                        strcpy(people[2].companyName,companyID);
                    }
                }
                else
                {
                    people[4].nameCardID = people[3].nameCardID;
                    strcpy(people[4].personName,people[3].personName);
                    strcpy(people[4].companyName,people[3].companyName);

                    people[3].nameCardID = people[2].nameCardID;
                    strcpy(people[3].personName,people[2].personName);
                    strcpy(people[3].companyName,people[2].companyName);

                    people[2].nameCardID = people[1].nameCardID;
                    strcpy(people[2].personName,people[1].personName);
                    strcpy(people[2].companyName,people[1].companyName);

                    people[1].nameCardID = numID;
                    strcpy(people[1].personName,nameID);
                    strcpy(people[1].companyName,companyID);
                }
            }
            else
            {
                people[4].nameCardID = people[3].nameCardID;
                strcpy(people[4].personName,people[3].personName);
                strcpy(people[4].companyName,people[3].companyName);

                people[3].nameCardID = people[2].nameCardID;
                strcpy(people[3].personName,people[2].personName);
                strcpy(people[3].companyName,people[2].companyName);

                people[2].nameCardID = people[1].nameCardID;
                strcpy(people[2].personName,people[1].personName);
                strcpy(people[2].companyName,people[1].companyName);

                people[1].nameCardID = people[0].nameCardID;
                strcpy(people[1].personName,people[0].personName);
                strcpy(people[1].companyName,people[0].companyName);

                people[0].nameCardID = numID;
                strcpy(people[0].personName,nameID);
                strcpy(people[0].companyName,companyID);
            }
        }
        printf("The name card has been added successfully\n");
        count++;
    }
}

void removeNameCard()
{
    char *p, dummy, nameID[20], tempname[5][20];
    int h, i, k, j, n;

    printf("removeNameCard():\n");
    printf("Enter personName:\n");
    scanf("%c",&dummy);
    fgets(nameID,20,stdin);
    if(p=strchr(nameID,'\n'))
        *p = '\0';

    if(count==0)
        printf("The name card holder is empty\n");

    else
    {
        for(j=0;j<20;j++)
            nameID[j] = toupper(nameID[j]);

        for(i=0;i<MAX;i++)
        {
            for(k=0;k<20;k++)
                tempname[i][k] = toupper(people[i].personName[k]);
        }

        for(h=0;h<MAX;h++)
        {
            if(strcmp(nameID,tempname[h])==0)
            {
                printf("The name card is removed\n");
                printf("nameCardID: %d\n", people[h].nameCardID);
                printf("personName: %s\n", people[h].personName);
                printf("companyName: %s\n", people[h].companyName);

                for(n=h;n<(MAX-1);n++)
                {
                    people[n].nameCardID = people[n+1].nameCardID;
                    strcpy(people[n].personName,people[n+1].personName);
                    strcpy(people[n].companyName,people[n+1].companyName);
                }
                people[4].nameCardID = 0;
                strcpy(people[4].personName,nullStr);
                strcpy(people[4].companyName,nullStr);
                count--;
                return;
            }
        }
        printf("The target person name is not in the name card holder\n");
    }
}

void getNameCard()
{
    char *p, dummy, nameID[20], tempname[MAX][20];
    int h, i, k, j;

    printf("getNameCard():\n");
    printf("Enter personName:\n");
    scanf("%c",&dummy);
    fgets(nameID,20,stdin);
    if(p=strchr(nameID,'\n'))
        *p = '\0';

    for(j=0;j<20;j++)
            nameID[j] = toupper(nameID[j]);

    for(i=0;i<MAX;i++)
    {
        for(k=0;k<20;k++)
            tempname[i][k] = toupper(people[i].personName[k]);
    }

    for(h=0;h<MAX;h++)
    {
        if(strcmp(nameID,tempname[h])==0)
        {
            printf("The target person name is found\n");
            printf("nameCardID: %d\n", people[h].nameCardID);
            printf("personName: %s\n", people[h].personName);
            printf("companyName: %s\n", people[h].companyName);
            return;
        }
    }
    printf("The target person name is not found\n");
}
