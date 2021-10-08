# include <stdio.h>
#include <string.h>

void is_LoShuMagic_Matrix(int i, int j, int arr[][3]);
void generateSquare(int n);

int main()
{
    //int arr[3][3];
    int i, j;

    int arr[3][3] ={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    /*int arr[3][3] ={
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    };
    */

    is_LoShuMagic_Matrix(3, 3, arr);
    generateSquare(3);
    return 0;
}

void is_LoShuMagic_Matrix(int i, int j, int arr[][3])
{
    //int i, j;
    int d1, d2, flag, row_sum, column_sum;
    d1 = 0;
    d2 = 0;
    flag = 0;
    row_sum = 0;
    column_sum = 0;

    printf("The given matrix is:\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(i==j)
            {
                d1 = d1 + arr[i][j];
            }
            if(i+j== 3-1)
            {
                d2 =d2 + arr[i][j];
            }
        }
    }
    if(d1 != d2)
    {
        flag = 1;
    }
    else 
    {
        for(i=0; i<3; i++)
        {   
            row_sum = 0;
            column_sum = 0;
            for(j=0; j<3; j++)
            {
                column_sum = column_sum + arr[j][i];
                row_sum = row_sum + arr[i][j];
            }
            if(column_sum != d1)
            {
                flag = 1;
            }
            else if(row_sum != d1)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }

    }
    if (flag == 0)
    {
        printf("The matrix is Lo Shu Magic Square\n");
    }
    else
    {
        printf("The matrix is not Lo Shu Magic Square\n");
    }
}

void generateSquare(int n)
{
    int magicSquare[n][n];
    static int count = 0;
 
    // set all slots as 0
    memset(magicSquare, 0, sizeof(magicSquare));
 
    // Initialize position for 1
    int i = n / 2;
    int j = n - 1;
 
    // One by one put all values in magic square
    for (int num = 1; num <= n * n;) {
        if (i == -1 && j == n) // 3rd condition
        {
            j = n - 2;
            i = 0;
        }
        else {
            // 1st condition helper if next number
            // goes to out of square's right side
            if (j == n)
                j = 0;
 
            // 1st condition helper if next number
            // is goes to out of square's upper side
            if (i < 0)
                i = n - 1;
        }
        if (magicSquare[i][j]) // 2nd condition
        {
            j -= 2;
            i++;
            continue;
        }
        else
            magicSquare[i][j] = num++; // set number
 
        j++;
        i--; // 1st condition
        count++;
    }
 
    // Print magic square
    printf("The number of attempt is %d\n", count);
    printf("The Magic Square for %d x %d:\nSum of "
           "each row or column %d:\n\n",
           n, n, n * (n * n + 1) / 2);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%3d ", magicSquare[i][j]);
        printf("\n");
    }
}