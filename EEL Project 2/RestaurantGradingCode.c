#include <stdio.h>

float calculateAverageRating(float price, float foodQuality, float staffService, float hygiene, float location) {
    return (price + foodQuality + staffService + hygiene + location) / 5;
}

void printStarRating(float rating) {
    int wholeStars = (int)rating;
    for(int i = 0; i < wholeStars; i++) {
        printf("*");
    }
    if(rating - wholeStars >= 0.5) {
        printf("*");
    }
    printf("\n");
}

int main() {
    int numRestaurants;
    
    while (1) {
        printf("Enter the number of restaurants to rate: ");
        if (scanf("%d", &numRestaurants) == 1 && numRestaurants > 0) {
            break;
        } else {
            printf("Invalid input. Please enter a positive integer.\n");

            while (getchar() != '\n');
        }
    }

    for(int i = 0; i < numRestaurants; i++) {
        char restaurantName[100];
        printf("Enter restaurant name: ");
        scanf(" %[^\n]", restaurantName); 

        float price, foodQuality, staffService, hygiene, location;
        printf("Rate %s on the following criteria (0-5):\n", restaurantName);
        printf("Price: ");
        scanf("%f", &price);
        while(price < 0 || price > 5) {
            printf("Invalid input. Please enter rating between 0 and 5: ");
            scanf("%f", &price);
        }

        printf("Food Quality: ");
        scanf("%f", &foodQuality);
        while(foodQuality < 0 || foodQuality > 5) {
            printf("Invalid input. Please enter rating between 0 and 5: ");
            scanf("%f", &foodQuality);
        }

        printf("Staff Service: ");
        scanf("%f", &staffService);
        while(staffService < 0 || staffService > 5) {
            printf("Invalid input. Please enter rating between 0 and 5: ");
            scanf("%f", &staffService);
        }

        printf("Hygiene: ");
        scanf("%f", &hygiene);
        while(hygiene < 0 || hygiene > 5) {
            printf("Invalid input. Please enter rating between 0 and 5: ");
            scanf("%f", &hygiene);
        }

        printf("Location: ");
        scanf("%f", &location);
        while(location < 0 || location > 5) {
            printf("Invalid input. Please enter rating between 0 and 5: ");
            scanf("%f", &location);
        }

        float averageRating = calculateAverageRating(price, foodQuality, staffService, hygiene, location);
        printf("%s rated %.2f/5\n", restaurantName, averageRating);
        printf("Rating: ");
printStarRating(averageRating);
        printf("\n");

        char feedback[200];
        printf("Any additional feedback about %s?\n", restaurantName);
        scanf(" %[^\n]", feedback); 
        printf("Thanks for the feedback!\n\n");
    }

    return 0;
}