#include <stdio.h>
#include <stdlib.h>
#define N 3
#define BNN -100

void check(double m_a[][N], double v_b[]);
void check_aug(double m_aug[][N + 1]);
void swap_rows_aug(double m_aug[][N + 1], int a, int b);
int largest(double arr[N]); /*returns indes of the largest element*/
void multiply_row_aug(double m_aug[][N + 1], int row, double multipier);
void change(double leftomst_n_z[]);

int main()
{
    double a[N][N] = { {2, 1, -1}, {-3, -1, 2}, {-2, 1, 2} };
    double b[N] = { 8, -11, -3 };
    double aug[N][N + 1]; /*augmented matrix*/
    double leftomst_n_z[N] = { BNN, BNN, BNN }; /*array of leftmost values in a matrix*/
    double temp[N + 1];
    int row, col;
    double m;/*m - scalar multiplier*/
    /*printf("Coefficients matrix ( A )\n");
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            printf("row %d column %d\n", row + 1, col + 1);
            int input;
            scanf_s("%d", &input);
            a[row][col] = input;
        }
    }
    printf("Solutions vector ( b )\n");
    for (row = 0; row < N; row++)
    {
        printf("row %d\n", row + 1);
        int input;
        scanf_s("%d", &input);
        b[row] = input;
    }*/
    /*print user's data*/
    printf("User's data\n");
    check(a, b);
    /*Gaussian elimination*/
    for (row = 0; row < N; row++) /*create an augmented matrix*/
    {
        for (col = 0; col < N + 1; col++)
        {
            if (col < N) aug[row][col] = a[row][col];
            else aug[row][col] = b[row];
        }
    }
    printf("\nCorresponding augmented matrix\n");
    check_aug(aug);
    int empty_rows = 0;
    /*Step 1: Swap the rows so that all rows with all zero entries are on the bottom*/
    for (row = 0; row < N; row++)
    {
        int zeros = 0;
        for (col = 0; col < N; col++)
        {
            if (a[row][col] == 0) zeros++;
        }
        //printf("zeros = %d\n", zeros);
        if (zeros == 3) /*if there are 3 zeros in a row, move it to the bottom*/
        {
            swap_rows_aug(aug, row, N - 1 - empty_rows);
            empty_rows++;
        }
    }
    printf("\n\tStep 1\n");
    check_aug(aug);
    /*Repeat steps 2-4 for the next leftmost nonzero entry until all the leading entries are 1.*/
    empty_rows = BNN;
    for (int a = 0; a < 2; a++) /*empty_rows != 3*/
    {

        printf("\n\n\t\tloop no %d\n", a);
        /*Step 2: Swap the rows so that the row with the largest, leftmost nonzero entry is on top.*/
        for (row = 0; row < N; row++) /*create array of leftmost values collected from every row ROW = 0*/
        {
            for (col = 0; col < N; col++)
            {
                if (aug[row][col] != 0 || col == N - 1)
                {
                    leftomst_n_z[row] = aug[row][col];
                    //change(leftomst_n_z);
                    //printf("leftomost[%d] = %lf\n", row, leftomst_n_z[row]);
                    break;
                }
            }
        }
        change(leftomst_n_z);
        swap_rows_aug(aug, largest(leftomst_n_z), 0);
        printf("\n\tStep 2\n");
        check_aug(aug);
        /*Step 3: Multiply the top row by a scalar (m) so that top row's leading entry becomes 1.*/
        int leading_i = 0;
        for (col = 0; col < N; col++)
        {
            if (aug[0][col] == 0)
            {
                leading_i++;
                break;
            }
        }
        m = 1 / aug[0][leading_i];
        multiply_row_aug(aug, 0, m);
        printf("\n\tStep 3 leading term = %d\n", leading_i);
        check_aug(aug);
        /*Step 4: Add/subtract multiples of the top row to the other rows so that all other entries
        in the column containing the top row's leading entry are all zero.*/
        for (row = 1; row < N; row++)
        {
            m = (-1) * aug[row][leading_i] / aug[0][leading_i]; /*find multiplier */
            for (col = 0; col < N + 1; col++)
            {
                temp[col] = m * aug[0][col]; /*multiply first row by m and store values*/
                aug[row][col] += temp[col]; /*add multiples of the top row*/
            }
        }
        printf("\n\tStep 4\n");
        check_aug(aug);
    }
    /*step 5: Swap the rows so that the leading entry of each nonzero row is to the right
    of the leading entry of the row above it.*/

    /*print the result*/
    //printf("\nResult\n");
    //check_aug(aug);
    //check(a, b);
}

void check(double m_a[][N], double v_b[])
{
    int row, col;
    printf("Coefficients matrix ( A )\n");
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            printf("%6.2lf", m_a[row][col]);
        }
        printf("\n");
    }
    printf("Solutions vector ( b )\n");
    for (row = 0; row < N; row++)
    {
        printf("%6.2f\n", v_b[row]);
    }
}

void check_aug(double m_aug[][N + 1])
{
    printf("Augmented matrix ( AUG )\n");
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N + 1; col++)
        {
            printf("%6.2f  ", m_aug[row][col]);
        }
        printf("\n");
    }
}

void swap_rows_aug(double m_aug[][N + 1], int a, int b)
{
    double temp[N + 1];
    for (int col = 0; col < N + 1; col++)
    {
        temp[col] = m_aug[b][col];
        m_aug[b][col] = m_aug[a][col];
        m_aug[a][col] = temp[col];
    }
}
int largest(double arr[N])
{
    int index_large = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > arr[index_large]) index_large = i;
    }
    return index_large;
}
void multiply_row_aug(double m_aug[][N + 1], int row, double multiplier)
{
    for (int col = 0; col < N + 1; col++)
    {
        m_aug[row][col] *= multiplier;
    }
}
void change(double leftomst_n_z[])
{
    for (int col = 0; col < N; col++)
    {
        if (leftomst_n_z[col] < 0) leftomst_n_z[col] *= (-1);
        if (leftomst_n_z[col] == 1 || leftomst_n_z[col] == 0) leftomst_n_z[col] = BNN;

    }

}
