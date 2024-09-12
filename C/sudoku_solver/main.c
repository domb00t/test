#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

const size_t ROWS = 9;
const size_t COLUMNS = 9;
const size_t NOT_SOLVED = ROWS * COLUMNS;

int FIELD[ROWS][COLUMNS] = { 0,0,0,  0,0,0,  0,0,0,
                             0,0,0,  0,0,0,  0,0,0,
                             0,0,0,  0,0,0,  0,0,0,

                             0,0,0,  0,0,0,  0,0,0,
                             0,0,0,  0,0,0,  0,0,0,
                             0,0,0,  0,0,0,  0,0,0,

                             0,0,0,  0,0,0,  0,0,0,
                             0,0,0,  0,0,0,  0,0,0,
                             0,0,0,  0,0,0,  0,0,0,
};

typedef struct Value
{
    int value_;
    bool is_possible_[10];
} value_t;

void init_vulue_t(int** field_) {

}

void print(int field_[][9])
{
    for (size_t i = 0; i < ROWS; ++i)
    {
        for (size_t j = 0; j < COLUMNS; ++j)
        {
            printf("%d", field_[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    print(FIELD);
    return 0;
}
