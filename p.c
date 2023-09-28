#include <stdio.h>

int main() {
    int arr[6]; // Declare an array to store the input
    int i;

    // Prompt the user to enter the elements
    printf("Enter 6 integers (0 or 1): \n");

    // Read the elements into the array
    for (i = 0; i < 6; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the elements to verify
    printf("You entered: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
