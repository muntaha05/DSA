#include <stdio.h>
#include <string.h>


int maxStrLength(char arr[][100], int n) {
    int maxLen = strlen(arr[0]);
    for (int i = 1; i < n; i++) {
        if (strlen(arr[i]) > maxLen) {
            maxLen = strlen(arr[i]);
        }
    }
    return maxLen;
}


void countingSort(char arr[][100], int n, int exp) {
    char output[n][100];
    int count[256] = {0};

    
    for (int i = 0; i < n; i++) {
        count[arr[i][exp]]++;        //freq
    }

    
    for (int i = 1; i < 256; i++) {     //cumulative freq
        count[i] += count[i - 1];
    }

   
    for (int i = n - 1; i >= 0; i--) {
        int index = count[arr[i][exp]] - 1;
        strcpy(output[index], arr[i]);
        count[arr[i][exp]]--;
    }

   
    for (int i = 0; i < n; i++) {
        strcpy(arr[i], output[i]);
    }
}


void radixSort(char arr[][100], int n) {
    int maxLen = maxStrLength(arr, n);

   
    for (int exp = maxLen - 1; exp >= 0; exp--) {
        countingSort(arr, n, exp);
    }
}

// Main function to test the code
int main() {
    char arr[5][100] = {"apple", "banana", "cherry", "date", "fig"};

    printf("Original array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", arr[i]);
    }

    radixSort(arr, 5);

    printf("\nSorted array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}