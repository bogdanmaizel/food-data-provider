#include <stdio.h>
#include <stdlib.h>

#define MAX_FOOD_NAME 10
#define MAX_MEAL_NAME 20
#define MAX_LINE 25
int main() {
    FILE *f=fopen("C:\\00SCHOOL\\CP\\food-data-provider\\data.txt", "w");
    //read no of foods
    int noOfFoods;
    printf("Please input number of food types\n");
    scanf("%d", &noOfFoods);
    getchar();
    //read foods
    char **foods;
    foods = (char **) malloc(noOfFoods * sizeof(char *));
    printf("Please input the food types (each on a new line, may contain spaces)\n");
    for (int i = 0; i < noOfFoods; i++) {
        // read each FOOD
        foods[i] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
        scanf("%s", foods[i]);
        getchar();
    }

    int *noOfmeals = (int *) malloc(noOfFoods * sizeof(int));
    char ***meals = (char ***) malloc(noOfFoods * sizeof(char **));
    double **prices = (double **) malloc(noOfFoods * sizeof(double *));
    for (int i = 0; i < noOfFoods; i++) {
            // read no of meals
            printf("Please input no of speciffic foods for food %s\n",foods[i]);
            scanf("%d", &noOfmeals[i]);
            getchar();
            //read meals & prices
            meals[i] = (char**)malloc(noOfmeals[i]* sizeof(char*));
            prices[i] = (double*)malloc(noOfmeals[i]* sizeof(double));

            printf("Please input %s speciffic foods &prices: each line in the format <speciffic food> (price):\n", foods[i]);
            for(int j=0;j<noOfmeals[i];j++){
                meals[i][j] = (char*)malloc(MAX_MEAL_NAME* sizeof(char));
                char line[MAX_LINE];
                gets(line);
                sscanf(line, "%s (%lf)\n", meals[i][j], &prices[i][j]);
            }

        }
    //read drinks
    int noOfDrinks;
    printf("Please input number of drinks.\n");
    scanf("%d", &noOfDrinks);
    char **drinks=(char**)malloc(noOfDrinks*sizeof(char*));
    double *drinksPrices=(double*)malloc(noOfDrinks* sizeof(double));
    getchar();
    printf("Please input the drinks: each line in the format <drink> (price):\n");
    for (int i=0;i<noOfDrinks;++i) {
        char line[MAX_LINE];
        gets(line);
        drinks[i]=(char*)malloc(MAX_FOOD_NAME* sizeof(char));
        sscanf(line, "%s (%lf)\n", drinks[i], &drinksPrices[i]);
    }


    // display data
    fprintf(f, "%d:\n", noOfFoods);
    for(int i=0;i<noOfFoods;i++) {
        // display FOOD
        fprintf(f, "%s %d:", foods[i], noOfmeals[i]);
        for (int j = 0; j < noOfmeals[i]; j++) {
            fprintf(f, " (%s - %.2lf),", meals[i][j], prices[i][j]);
        }
        fprintf(f, "\n");
    }
    fprintf(f, "%d:\n", noOfDrinks);
    for (int i=0;i<noOfDrinks;++i) {
        // display drinks
        fprintf(f, "(%s - %.2lf) ", drinks[i], drinksPrices[i]);
    }
}

