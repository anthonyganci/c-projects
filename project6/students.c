//Author: Anthony Ganci
//Student information program
//Project 6
//Date 4-8-2020
#include <stdio.h>
#define FILE_NAME "students.txt"
#define MAX_NUM 50
#define TABLE_TOP "=================================================="
#define TABLE_SEPERATION "||==============================================||"
#define DATA_SEPERATION "||------------|-------------------|-------------||"


int getMenuChoice();
int loadStudents(FILE *fp, int studentNumbers[], int studentCredits[], double studentGPAS[]);
void displayStudents(int numStudents, int studentNumbers[], int studentCredits[], double studentGPAS[]);
void calcStudents(int numStudents, double studentGPAS[], double *averageGPA, double *maxGPA, double *minGPA);
int saveStudents(FILE *fp, int numOfStudents, int studentNumbers[], int studentCredits[], double studentGPAS[]);

int main()  {
    int userChoice;
    FILE *fp;
    int studentNumbers[MAX_NUM], studentCredits[MAX_NUM], numStudents, numOfStudents;
    double studentGPAS[MAX_NUM], averageGPA, maxGPA, minGPA;

    //clearing file for fresh use
    fp = fopen(FILE_NAME, "w");
    fclose(fp);

    do
    {
        userChoice = getMenuChoice();
        
        switch (userChoice)
        {
        case 1:
            fp = fopen(FILE_NAME, "r");
            numStudents = loadStudents(fp, studentNumbers, studentCredits, studentGPAS);
            fclose(fp);
            break;
        case 2:
            displayStudents(numStudents, studentNumbers, studentCredits, studentGPAS);
            break;
        case 3:
            calcStudents(numStudents, studentGPAS, &averageGPA, &maxGPA, &minGPA);
            printf("Average GPA: %.2lf\n", averageGPA);
            printf("Minimum GPA: %.2lf\n", minGPA);
            printf("Maximum GPA: %.2lf\n", maxGPA); 
            break;
        case 4:
            fp = fopen(FILE_NAME, "r");
            numOfStudents = loadStudents(fp, studentNumbers, studentCredits, studentGPAS);
            fclose(fp);

            fp = fopen(FILE_NAME, "w");
            numStudents = saveStudents(fp, numOfStudents, studentNumbers, studentCredits, studentGPAS);
            fclose(fp);
            break;
        case 0:
            break;
        default:
            printf("Please enter a valid option!\n");
            break;
        }
    } while (userChoice != 0);
    
    return 0;
}

int getMenuChoice() {
    int userChoice;

    printf("***STUDENT SYSTEM***\n");
    printf("1. Load Students\n");
    printf("2. Display Students\n");
    printf("3. Analyze GPAs\n");
    printf("4. Add Students\n");
    printf("0. EXIT\n");

    printf("Enter your choice: ");
    scanf("%d", &userChoice);
    
    return userChoice;
}
int loadStudents(FILE *fp, int studentNumbers[], int studentCredits[], double studentGPAS[])  {
    int count, numOfStudents;
    fscanf(fp, "%d", &numOfStudents);
            if (numOfStudents == NULL)
            {
                count = 0;
            }
            else if (numOfStudents != NULL)
            {
                count = 0;
                while (!feof(fp))
                {
                    fscanf(fp, "\n%d, %d, %lf\n", &studentNumbers[count], &studentCredits[count], &studentGPAS[count]);
                    count++;

                }
            }
    
    return count;
}
void displayStudents(int numStudents, int studentNumbers[], int studentCredits[], double studentGPAS[])  {
    int count = 0;

    printf("\n STUDENTS\n");
    printf("%s\n", TABLE_TOP);
    printf("||Student ID  |      Credits      |     GPA     ||\n");
    printf("%s\n", TABLE_SEPERATION);
    printf("%s\n", DATA_SEPERATION);
    while (count != numStudents)
    {
        printf("||%9d   |%10d         |%7.2lf      ||\n", studentNumbers[count], studentCredits[count], studentGPAS[count]);
        printf("%s\n", DATA_SEPERATION);
        count++;
    }
    printf("%s\n", TABLE_TOP);
    
}
void calcStudents(int numStudents, double studentGPAS[], double *averageGPA, double *maxGPA, double *minGPA)   {
    int count = 0;
    double totalGPA = 0;
    double GPA1;

    while (count != numStudents)
    {
        totalGPA += studentGPAS[count];
        count++;
    }
    *averageGPA = totalGPA / count;
    

    count = 1;
    GPA1 = studentGPAS[0];
    while (count != numStudents)
    {
        
        if (GPA1 > studentGPAS[count])
        {
            *maxGPA = GPA1;
        }
        else
        {
            GPA1 = studentGPAS[count];
            *maxGPA = studentGPAS[count];
        }
        count++;
    }
    
    count = 1;
    GPA1 = studentGPAS[0];
    while (count != numStudents)
    {
        
        if (GPA1 < studentGPAS[count])
        {
            *minGPA = GPA1;
        }
        else
        {
            GPA1 = studentGPAS[count];
            *minGPA = studentGPAS[count];
        }
        count++;
    }
}
int saveStudents(FILE *fp, int numOfStudents, int studentNumbers[], int studentCredits[], double studentGPAS[])   {
    int count = 0;
    int studentCount = 0;

    printf("How many students are you adding? ");
    scanf("%d", &studentCount);
    
    studentCount = numOfStudents + studentCount;
    for (numOfStudents; numOfStudents != studentCount; numOfStudents++)
    {
        printf("Enter a student number: ");
        scanf("%d", &studentNumbers[numOfStudents]);
        
        printf("Enter the number of credits: ");
        scanf("%d", &studentCredits[numOfStudents]);
        
        printf("Enter a GPA: ");
        scanf("%lf", &studentGPAS[numOfStudents]);   
    }
    
    fprintf(fp, "%d\n", studentCount);
    for (count = 0; count != studentCount; count++)
    {
        printf("%d\n", count);
        fprintf(fp, "%d, ", studentNumbers[count]);
        fprintf(fp, "%d, ", studentCredits[count]);
        fprintf(fp, "%.4lf\n", studentGPAS[count]);
    }
    
    return studentCount;
}