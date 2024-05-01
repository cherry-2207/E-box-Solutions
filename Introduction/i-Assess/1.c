// Introduction Module i-Assess solution
#include <stdio.h>
int main()
{
    int n, a[100], b[100], c[100], k = 0, t, i, count = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    t = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] != t)
        {
            count++;
            b[k] = i;
            while (a[i] != t && i < n)
                i++;
            c[k] = i - b[k] + 2;
            k++;
        }
    }
    printf("%d\n", count);
    for (i = 0; i < k; i++)
    {
        printf("%d ", b[i]);
        printf("%d\n", c[i]);
    }
    return 0;
}
