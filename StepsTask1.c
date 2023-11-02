#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    int current_line = 1;
    int final_line = 3;
    char line[100];
    char date[11];
    char time[6];
    char steps[9];
    FILE *file = fopen("FitnessData_2023.csv","r");
    while(fgets(line,sizeof(line),file)&& current_line<=final_line){
        tokeniseRecord(line,",", date,time,steps);
        FITNESS_DATA date1;
        strcpy(date1.date,date);
        strcpy(date1.time,time);
//        int num = atoi(steps);
//        date1.steps = num;
        strcpy(date1.steps,steps);
        printf("%s/%s/%d",date1.date,date1.time,date1.steps);
        current_line += 1;
        printf("\n");
    }
    fclose(file);
    return 0;
}
