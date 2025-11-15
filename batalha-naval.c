#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 10

void init_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int r = 0; r < BOARD_SIZE; r++)
        for (int c = 0; c < BOARD_SIZE; c++)
            board[r][c] = 0;
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\nTabuleiro (0 = água, 3 = navio, 5 = área afetada):\n\n");
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

void create_cone(int n, int mat[n][n])
{
    int center = n / 2;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (abs(c - center) <= r)
                mat[r][c] = 1;
            else
                mat[r][c] = 0;
        }
    }
}

void create_cross(int n, int mat[n][n])
{
    int center = n / 2;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (r == center || c == center)
                mat[r][c] = 1;
            else
                mat[r][c] = 0;
        }
    }
}

void create_octahedron(int n, int mat[n][n])
{
    int center = n / 2;
    int radius = center;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            int dr = abs(r - center);
            int dc = abs(c - center);
            if (dr + dc <= radius)
                mat[r][c] = 1;
            else
                mat[r][c] = 0;
        }
    }
}

void overlay_ability(int board[BOARD_SIZE][BOARD_SIZE], int origin_r, int origin_c, int n, int ability[n][n])
{
    int center = n / 2;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (ability[r][c] != 1)
                continue;

            int board_r = origin_r - center + r;
            int board_c = origin_c - center + c;

            if (board_r < 0 || board_r >= BOARD_SIZE || board_c < 0 || board_c >= BOARD_SIZE)
            {
                continue;
            }

            if (board[board_r][board_c] == 0)
            {
                board[board_r][board_c] = 5;
            }
        }
    }
}

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);

    board[2][2] = 3;
    board[2][3] = 3;
    board[2][4] = 3;
    board[4][7] = 3;
    board[5][7] = 3;
    board[6][7] = 3;
    board[7][7] = 3;
    board[8][1] = 3;
    board[8][2] = 3;

    const int n = 7;
    int cone[n][n];
    int cross[n][n];
    int octa[n][n];

    create_cone(n, cone);
    create_cross(n, cross);
    create_octahedron(n, octa);

    int origin_cone_r = 1, origin_cone_c = 3;
    int origin_cross_r = 5, origin_cross_c = 5;
    int origin_octa_r = 7, origin_octa_c = 2;

    overlay_ability(board, origin_cone_r, origin_cone_c, n, cone);
    overlay_ability(board, origin_cross_r, origin_cross_c, n, cross);
    overlay_ability(board, origin_octa_r, origin_octa_c, n, octa);

    printf("Matriz Cone (1 = afetado, 0 = não afetado):\n");
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
            printf("%d ", cone[r][c]);
        printf("\n");
    }
    printf("\n");

    printf("Matriz Cruz (1 = afetado, 0 = não afetado):\n");
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
            printf("%d ", cross[r][c]);
        printf("\n");
    }
    printf("\n");

    printf("Matriz Octaedro/Losango (1 = afetado, 0 = não afetado):\n");
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
            printf("%d ", octa[r][c]);
        printf("\n");
    }
    printf("\n");

    print_board(board);

    return 0;
}