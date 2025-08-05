#include <stdio.h>
#define MAX 25

int main()
{
    int frag[MAX], b[MAX], f[MAX], bf[MAX] = {0}, ff[MAX] = {0};
    int i, j, nb, nf, temp, highest;

    printf("\nMemory Management Scheme - Worst Fit\n");

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 0; i < nb; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the files:\n");
    for (i = 0; i < nf; i++)
    {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    for (i = 0; i < nf; i++)
    {
        highest = -1;
        for (j = 0; j < nb; j++)
        {
            if (bf[j] == 0)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                {
                    if (highest == -1 || temp > b[highest] - f[i])
                        highest = j;
                }
            }
        }

        if (highest != -1)
        {
            ff[i] = highest;
            frag[i] = b[highest] - f[i];
            bf[highest] = 1;
        }
        else
        {
            ff[i] = -1;
            frag[i] = -1;
        }
    }

    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment");
    for (i = 0; i < nf; i++)
    {
        if (ff[i] != -1)
            printf("\n%d\t%d\t\t%d\t\t%d\t\t%d", i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        else
            printf("\n%d\t%d\t\tNot Allocated", i + 1, f[i]);
    }

    return 0;
}