/*
Name: OTIM AMOS
Registration Number: 25/U/BIO/01416/PD
*/

#include <stdio.h>
#include <string.h>

int main(void) {


    /* Declare variables here */
    float semester_one_gpa = 0;
    float semester_two_gpa = 0;
    float cgpa = 0;
    char cgpa_classification[25];

    // SEMESTER ONE VARIABLES

    char sem1_course_codes[8][10] = {"TEMB1101", "TEMB1102", "TEMB1103", "TEMB1104",
                                    "TEMB1105", "TEMB1106", "TEMB1107", "TEMB1108"
                                    };
    char sem1_course_names[8][40] ={
                                    "Fundamentals of engineering Math",
                                    "Biochemistry and Medical Physics",
                                    "Electrical Engineering Science",
                                    "Mechanics 1",
                                    "Computing 1",
                                    "Mechanical Drawing",
                                    "Engineering Profession",
                                    "Functional Anatomy and Physiology 1"
                                    };
    int sem1_credit_units[8] = {4, 3, 3, 3, 3, 3, 2, 3};
    int sum_credit_units1 = 24;
    int sem1_marks[8]; // = {65, 83, 84, 83, 88, 75, 56, 87};
    char sem1_grades[8];
    float sem1_grade_points[8];
    float sem1_weighted_contribution[8];

    // SEMESTER TWO VARIABLES
    char sem2_course_codes[8][10] = {"TEMB1201", "TEMB1202", "TEMB1203", "TEMB1204",
                                    "TEMB1205", "TEMB1206", "TEMB1207", "TEMB1208"
                                    };
    char sem2_course_names[8][40] ={
                                    "Fundamentals of engineering Math",
                                    "Biochemistry and Medical Physics",
                                    "Electrical Engineering Science",
                                    "Mechanics 1",
                                    "Computing 1",
                                    "Mechanical Drawing",
                                    "Engineering Profession",
                                    "Functional Anatomy and Physiology 2"
                                    };
    int sem2_credit_units[8] = {4, 3, 3, 3, 3, 3, 3, 3};
    int sum_credit_units2 = 25;
    int sem2_marks[8]; // = {60, 50, 50, 95, 76, 45, 65, 70};
    char sem2_grades[8];
    float sem2_grade_points[8];
    float sem2_weighted_contribution[8];



    /* Read 16 scores */
    /// printf("\n\n------------PLEASE ENTER SEMESTER ONE MARKS-------------");
    for(int d = 0; d < 8; d++){
        /// printf("\n%s:\t", sem1_course_codes[d]);
        scanf(" %d", &sem1_marks[d]);
    }

    /// printf("\n\n------------PLEASE ENTER SEMESTER TWO MARKS-------------");
    for(int d = 0; d < 8; d++){
        /// printf("\n%s:\t", sem2_course_codes[d]);
        scanf(" %d", &sem2_marks[d]);
    }

    /* Validate input */

    // VALIDATION FOR SEM 1
    for(int x = 0; x < 8; x++){
        if(sem1_marks[x] < 0 || sem1_marks[x] > 100){
            printf("\nInvalid score entered");
            return 0;
        }
        else{
            // printf("\nValidation for %s complete.", sem1_course_codes[x]);
        }
    }


    // VALIDATION FOR SEM 2
    for(int x = 0; x < 8; x++){
        if(sem2_marks[x] < 0 || sem2_marks[x] > 100){
            printf("\nInvalid score entered");
            return 0;
        }
        else{
            // printf("\nValidation for %s  complete.", sem2_course_codes[x]);
        }
    }

    /* Determine grades and grade points */

    // GRADES AND GRADE POINTS FOR SEMESTER ONE
    for(int g = 0; g < 8; ++g){
        switch(sem1_marks[g]){
            case 0 ... 49:
                {
                    sem1_grades[g] = 'F';
                    sem1_grade_points[g] = 0;
                    break;
                }
            case 50 ... 59:
                {
                    sem1_grades[g] = 'D';
                    sem1_grade_points[g] = 2;
                    break;
                }
            case 60 ... 69:
                {
                    sem1_grades[g] = 'C';
                    sem1_grade_points[g] = 3;
                    break;
                }
            case 70 ... 79:
                {
                    sem1_grades[g] = 'B';
                    sem1_grade_points[g] = 4;
                    break;
                }
            case 80 ... 100:
                {
                    sem1_grades[g] = 'A';
                    sem1_grade_points[g] = 5;
                    break;
                }
        }
    }



    // GRADES AND GRADE POINTS FOR SEMESTER TWO
    for(int g = 0; g < 8; ++g){
        switch(sem2_marks[g]){
            case 0 ... 49:
                {
                    sem2_grades[g] = 'F';
                    sem2_grade_points[g] = 0;
                    break;
                }
            case 50 ... 59:
                {
                    sem2_grades[g] = 'D';
                    sem2_grade_points[g] = 2;
                    break;
                }
            case 60 ... 69:
                {
                    sem2_grades[g] = 'C';
                    sem2_grade_points[g] = 3;
                    break;
                }
            case 70 ... 79:
                {
                    sem2_grades[g] = 'B';
                    sem2_grade_points[g] = 4;
                    break;
                }
            case 80 ... 100:
                {
                    sem2_grades[g] = 'A';
                    sem2_grade_points[g] = 5;
                    break;
                }
        }
    }

//    for(int i = 0; i < 8; i++){
//        printf("\n%s: %c: %f", sem2_course_codes[i], sem2_grades[i], sem2_grade_points[i]);
//    }

    /* Compute Semester I GPA */
    for(int k = 0; k < 8; k++){
        // NOTE: THIS LOOP CALCULATES GPA AND WEIGHTED CONTRIBUTION
        // grade_point * credit_unit / sum_credit_units1
        float igpa = sem1_grade_points[k] * sem1_credit_units[k] / sum_credit_units1;
        sem1_weighted_contribution[k] = igpa;
        semester_one_gpa += igpa;
    }



    /* Compute Semester II GPA */
    for(int k = 0; k < 8; k++){
        // NOTE: THIS LOOP CALCULATES GPA AND WEIGHTED CONTRIBUTION SEM 2
        // grade_point * credit_unit / sum_credit_units2
        float igpa = sem2_grade_points[k] * sem2_credit_units[k] / sum_credit_units2;
        sem2_weighted_contribution[k] = igpa;
        semester_two_gpa += igpa;
    }

    //printf("\n %f", semester_two_gpa);

    /* Compute CGPA */
    for(int m = 0; m < 8; m++){
        cgpa += sem1_grade_points[m] * sem1_credit_units[m];
        cgpa += sem2_grade_points[m] * sem2_credit_units[m];
    }
    cgpa = cgpa / (sum_credit_units1 + sum_credit_units2);

    /* Determine classification */
    if(cgpa < 2.00)
        // cgpa_classification = "Fail";
        strcpy(cgpa_classification, "Fail");
    else if(cgpa <= 2.79)
        // cgpa_classification = "Pass";
        strcpy(cgpa_classification, "Pass");
    else if(cgpa <= 3.59)
        // cgpa_classification = "Second Class Lower";
        strcpy(cgpa_classification, "Second Class Lower");
    else if(cgpa <= 4.39)
        // cgpa_classification = "Second Class Upper";
        strcpy(cgpa_classification, "Second Class Upper");
    else if(cgpa <= 5.00)
        // cgpa_classification = "First Class."
        strcpy(cgpa_classification, "First Class");
    else
        // cgpa_classification = "Sorry, an error occurred."
        strcpy(cgpa_classification, "Sorry, error occurred.");

    /* Display full academic report */
    /// printf("\n\n---------------SUMMARY OF RESULTS-----------------");
    printf("\nSemester I GPA: %.2f", semester_one_gpa);
    printf("\nSemester II GPA: %.2f", semester_two_gpa);
    printf("\nCGPA: %.2f", cgpa);
    printf("\nClassification: %s", cgpa_classification);

    printf("\n\n---------------SEMESTER ONE-----------------");
    for(int x = 0; x < 8; x++){
        printf("\n\t%s  %d  %c  %.2f  %d  %.2f", sem1_course_codes[x],
                        sem1_marks[x], sem1_grades[x],
                        sem1_grade_points[x], sem1_credit_units[x],
                        sem1_weighted_contribution[x]);
    }

    printf("\n\n---------------SEMESTER TWO-----------------");
    for(int x = 0; x < 8; x++){
        printf("\n\t%s  %d  %c  %.2f  %d  %.2f", sem2_course_codes[x],
                        sem2_marks[x], sem2_grades[x],
                        sem2_grade_points[x], sem2_credit_units[x],
                        sem2_weighted_contribution[x]);
    }



    return 0;
}
