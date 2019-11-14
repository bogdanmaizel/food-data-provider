#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FOOD_NAME 10
#define MAX_MEAL_NAME 20
#define MAX_LINE 25
void readMeal(char * meal);
float readNumber(char nr[]);
int main() {

    //read no of foods
    int noOfFoods;
    printf("Please input number of food types\n");
    scanf("%d", &noOfFoods);

    //read foods
    char **foods;
    foods = (char **) malloc(noOfFoods * sizeof(char *));
    printf("Please input the food types (each on a new line, may contain spaces)\n");
    for (int i = 0; i < noOfFoods; i++) {
        // read each FOOD
        foods[i] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
        scanf("%s", foods[i]);
    }

    int *noOfmeals = (int *) malloc(noOfFoods * sizeof(int));
    char ***meals = (char ***) malloc(noOfFoods * sizeof(char **));
    double **prices = (double **) malloc(noOfFoods * sizeof(double *));
    for (int i = 0; i < noOfFoods; i++) {
            // read no of meals
            printf("Please input no of speciffic foods for food %s\n",foods[i]);
            scanf("%d",&noOfmeals[i]);

            //read meals & prices
            meals[i] = (char**)malloc(noOfmeals[i]* sizeof(char*));
            prices[i] = (double*)malloc(noOfmeals[i]* sizeof(double));

            printf("Please input %s speciffic foods &prices: each line in the format <speciffic food> (price):\n", foods[i]);
            for(int j=0;j<noOfmeals[i];j++){
                meals[i][j] = (char*)malloc(MAX_MEAL_NAME* sizeof(char));
                char line[MAX_LINE];
                gets(line);
                sscanf(line, "%s", meals[i][j]);
                line[strlen(line)]='\0';
                sscanf(line, "%1f", prices[i][j]);
            }

        }

    // display data
    printf("The data is:\n");
    for(int i=0;i<noOfFoods;i++) {
        // display FOOD
        printf("%s: ", foods[i]);
        for(int j=0;j<noOfmeals[i];j++) {
            printf("(%s, %.2lf) ",meals[i][j],prices[i][j]);
        }
        printf("\n");
    }

    // free memory
    for(int i=0;i<noOfFoods;i++) {
        for(int j=0;j<noOfmeals;j++) {
            free(meals[i][j]);
        }
        free(meals[i]);
        free(prices[i]);
        free(foods[i]);
    }
    free(meals);
    free(prices);
    free(foods);
    free(noOfmeals);

    return 0;
}

float readNumber(char nr[]) {
    float x=0;
    gets(nr);
    for (int i=strlen(nr)-1;i>=0;--i) {
        if (nr[i]>='0' && nr[i]<='9') x=x*10+(nr[i]-'0');
    }
}

void readMeal(char * meal) {
    char c = getchar();
    int i=0;
    while(c!='(') {
        meal[i] = c;
        c = getchar();
        i++;
    }
    meal[i]='\0';
    meal[i-1] = '\0';
}
