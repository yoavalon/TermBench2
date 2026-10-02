#include <stdio.h>
#include <string.h>

int match(char a, char b) {
    if (a == b) {
        return 1;
    } else {
        return -1;
    }
}

int score(const char *x, const char *y, int i, int j) {
    if (i == 0 || j == 0) {
        return 0;
    } else {
        return score(x, y, i - 1, j - 1) + match(x[i - 1], y[j - 1]);
    }
}

void align(const char *x, const char *y, int i, int j, char *aligned_x, char *aligned_y) {
    if (i == 0 || j == 0) {
        return;
    }
    if (x[i - 1] == y[j - 1]) {
        align(x, y, i - 1, j - 1, aligned_x, aligned_y);
        aligned_x[i - 1] = x[i - 1];
        aligned_y[i - 1] = y[i - 1];
    } else {
        int scores[3];
        scores[0] = score(x, y, i - 1, j - 1);
        scores[1] = score(x, y, i, j - 1);
        scores[2] = score(x, y, i - 1, j);
        int idx = 0;
        for (int k = 1; k < 3; k++) {
            if (scores[k] > scores[idx]) {
                idx = k;
            }
        }
        if (idx == 0) {
            align(x, y, i - 1, j - 1, aligned_x, aligned_y);
            aligned_x[i - 1] = x[i - 1];
            aligned_y[i - 1] = y[i - 1];
        } else if (idx == 1) {
            align(x, y, i, j - 1, aligned_x, aligned_y);
            aligned_x[i - 1] = '_';
            aligned_y[i - 1] = y[i - 1];
        } else {
            align(x, y, i - 1, j, aligned_x, aligned_y);
            aligned_x[i - 1] = x[i - 1];
            aligned_y[i - 1] = '_';
        }
    }
}

int main() {
    const char *x = "AGGTAB";
    const char *y = "GXTXAYB";
    int i = strlen(x);
    int j = strlen(y);
    char aligned_x[i + 1];
    char aligned_y[i + 1];
    align(x, y, i, j, aligned_x, aligned_y);
    aligned_x[i] = '\0';
    aligned_y[i] = '\0';
    printf("Aligned sequence 1: %s\n", aligned_x);
    printf("Aligned sequence 2: %s\n", aligned_y);
    return 0;
}