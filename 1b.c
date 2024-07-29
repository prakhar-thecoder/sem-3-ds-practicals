#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int is_anagram(char a[], char b[]) {
    if (strlen(a) != strlen(b)) {
        return 0;
    }

    int freq_a[256];
    int freq_b[256];

    for (int i = 0; i < 256; i++) {
        freq_a[i] = 0;
        freq_b[i] = 0;
    }

    for (int i = 0; a[i] != '\0'; i++) {
        freq_a[a[i]] += 1;
        freq_b[b[i]] += 1;
    }

    for (int i = 0; i < 256; i++) {
        if (freq_a[i] != freq_b[i]) {
            return 0;
        }
    }

    return 1;
}

void main () {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d strings\n\n", n);

    char c[n][100];
    for (int i = 0; i < n; i++) {
        printf("Enter string %d: ", i+1);
        scanf("%s", &c[i]);
    }

    srand(time(0));
    int r =  rand() % (n-1) + 1;
    char ana[100];

    printf("\nEnter the anagram of %s: ", c[r]);
    scanf("%s", &ana);

    if ("%d", is_anagram(c[r], ana) == 1) {
        printf("Coorect!");
    } else {
        printf("Incorrect!");
    }
}
