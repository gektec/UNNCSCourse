#include <stdio.h>

void insertsort(int m[], int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (m[i] < m[j]) {
                k = m[i];
                m[i] = m[j];
                m[j] = k;
            }
        }
    }
}

int main() {
    printf("Enter number of marks: ");
    int n;
    scanf("%d", &n);
    int marks[n];
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter mark %d: ", i + 1);
        scanf("%d", &marks[i]);
    }
    insertsort(marks, n);
    for (i = 0; i < n; i++) {
        printf("%d\n", marks[i]);
    }
    return 0;
}
