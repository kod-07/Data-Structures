#include <stdio.h>

void search(int *a, int n) {
    int low = 0, high = 8; // 9 elements mean index ranges from 0 to 8
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == n) {
            printf("Element found at position %d\n", mid + 1); // Display position as 1-based
            return;
        } else if (a[mid] < n) { // Change here for descending order
            high = mid - 1; // Move the high pointer down
        } else {
            low = mid + 1; // Move the low pointer up
        }
    }

    printf("!!Element not found!!\n");
}

int main() {
    int arr[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; // Example sorted array in descending order
    int n;

    printf("Enter the element to search: ");
    scanf("%d", &n);

    search(arr, n);
    return 0;
}
