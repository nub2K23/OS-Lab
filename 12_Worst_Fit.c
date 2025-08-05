#include <stdio.h>
#define MAX 25
int main()
{
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp;
    static int bf[MAX], ff[MAX];
    printf("\n\tMemory Management Scheme - First Fit\n");
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
    printf("Enter the size of the files:\n");
    for (i = 0; i < nf; i++)
    {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }
    for (i = 0; i < nf; i++)
    {
        ff[i] = -1; // No block allocated yet
        for (j = 0; j < nb; j++)
        {
            if (bf[j] == 0 && b[j] >= f[i])
            {
                ff[i] = j;
                frag[i] = b[j] - f[i];
                bf[j] = 1; // Mark block as used
                break;
            }
        }
    }
    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment");
    for (i = 0; i < nf; i++)
    {
        if (ff[i] != -1)
        {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        }
        else
        {
            printf("\n%d\t\t%d\t\tNot Allocated", i + 1, f[i]);
        }
    }
    return 0;
}
