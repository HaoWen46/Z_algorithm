#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[1024], str2[1024], str[2048];
    printf("enter the full string:");
    //fgets(str2, 1024, stdin);
    gets(str2);
    printf("enter the pattern you're looking for:");
    //fgets(str1, 1024, stdin);
    gets(str1);
    strcpy(str, str1), strcat(str, "#"), strcat(str, str2);
    int i, k, l = 0, r = 0, n = strlen(str), z[n], len = strlen(str1);
    memset(z, 0, n * sizeof(int));
    for (i = 1; i < n; i++) {
        if (i <= r) {
            k = i - l;
            if (z[k] > r - i) {
                l = i;
                while (r < n && str[r] == str[r - l]) r++;
                z[i] = r-- - l;
            }
            else z[i] = z[k];
        }
        else {
            l = r = i;
            while (r < n && str[r] == str[r - l]) r++;
            z[i] = r-- - l;
        }
    }
    for (i = 0; i < n; i++) {
        if (z[i] != len) continue;
        printf("pattern exists!\n");
        return 0;
    }
    printf("There is no such pattern :(\n");
    return 0;
}