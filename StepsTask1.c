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
    int current_line = 0;
//   Set initial row index
    int final_line = 3;
//    Set final row index
    char line[100];
//    Create the maximum character capacity for a line
    char date[11];
//    Date character capacity
    char time[6];
//    Time character capacity
    char steps[9];
//    Step number character capacity
    FILE *file = fopen("FitnessData_2023.csv", "r");
//   Open the specified file
    FITNESS_DATA date1[1000]; // Define a large installation of FITNESS_ Array of DATA data
    int count = 0;
//   Specify which FITNESS it is_ Elements of DATA date1 []
    while (fgets(line, sizeof(line), file)){
         tokeniseRecord(line, ",", date, time, steps);
//        Separate according to given conditions
         strcpy(date1[count].date, date);
//         Deposit date character
         strcpy(date1[count].time, time);
//        Save Time Characters
         int num = atoi(steps);
//        Convert step numbers in character form to numeric types
         date1[count].steps = num;
//        Number of stored steps
         count++;
//       Jump to the next FITNESS_ Elements of DATA date1 []
    }
      while (current_line < final_line)
//      When current_ Line is less than the final_ Line time
      {
          printf("%s/%s/%d", date1[current_line].date, date1[current_line].time, date1[current_line].steps);
//         Print the date, time, and number of steps in order, separated by/
          printf("\n");
//       wrap
          current_line += 1;
//        Continue printing the next line
         }
      fclose(file);
//      close file
      return 0;
}
