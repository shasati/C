#include <stdio.h>
#include <stdlib.h>
// Structure to represent a sparse matrix element
struct SparseElement {
    int row;
    int col;
    int value;
};

// Structure to represent a sparse matrix
struct SparseMatrix {
    int numRows;
    int numCols;
    int numNonZero;
    struct SparseElement *elements;
};

// Function to initialize a sparse matrix
void initializeSparseMatrix(struct SparseMatrix *matrix, int rows, int cols, int nonZero) {
    matrix->numRows = rows;
    matrix->numCols = cols;
    matrix->numNonZero = nonZero;
    matrix->elements = (struct SparseElement *)malloc(nonZero * sizeof(struct SparseElement));

    printf("Enter the elements (row, column, value) for %d non-zero elements:\n", nonZero);
    for (int i = 0; i < nonZero; ++i) {
        scanf("%d %d %d", &matrix->elements[i].row, &matrix->elements[i].col, &matrix->elements[i].value);
    }
}

// Function to perform matrix subtraction
struct SparseMatrix subtractMatrices(struct SparseMatrix matrix1, struct SparseMatrix matrix2) {
    struct SparseMatrix result;
    // Initialize result matrix with the same dimensions and zero non-zero count
    initializeSparseMatrix(&result, matrix1.numRows, matrix1.numCols, 0);

    // Iterate through both matrices and subtract corresponding elements
    int i = 0, j = 0, k = 0;
    while (i < matrix1.numNonZero && j < matrix2.numNonZero) {
        if (matrix1.elements[i].row < matrix2.elements[j].row ||
            (matrix1.elements[i].row == matrix2.elements[j].row && matrix1.elements[i].col < matrix2.elements[j].col)) {
            result.elements[k++] = matrix1.elements[i++];
        } else if (matrix1.elements[i].row == matrix2.elements[j].row && matrix1.elements[i].col == matrix2.elements[j].col) {
            struct SparseElement temp = {
                .row = matrix1.elements[i].row,
                .col = matrix1.elements[i].col,
                .value = matrix1.elements[i].value - matrix2.elements[j].value
            };
            if (temp.value != 0) {
                result.elements[k++] = temp;
            }
            ++i;
            ++j;
        } else {
            result.elements[k++] = matrix2.elements[j++];
        }
    }

    while (i < matrix1.numNonZero) {
        result.elements[k++] = matrix1.elements[i++];
    }

    while (j < matrix2.numNonZero) {
        result.elements[k++] = matrix2.elements[j++];
    }

    result.numNonZero = k;
    return result;
}

// Function to calculate the transpose of a matrix
struct SparseMatrix transposeMatrix(struct SparseMatrix matrix) {
    struct SparseMatrix result;
    // Initialize result matrix with the transposed dimensions and zero non-zero count
    initializeSparseMatrix(&result, matrix.numCols, matrix.numRows, 0);

    // Create an array to store the count of non-zero elements in each column of the original matrix
    int *colCounts = (int *)calloc(matrix.numCols, sizeof(int));

    // Count non-zero elements in each column
    for (int i = 0; i < matrix.numNonZero; ++i) {
        colCounts[matrix.elements[i].col]++;
    }

    // Calculate the starting index for each column in the transposed matrix
    int *colStartIndex = (int *)malloc((matrix.numCols + 1) * sizeof(int));
    colStartIndex[0] = 0;
    for (int i = 1; i <= matrix.numCols; ++i) {
        colStartIndex[i] = colStartIndex[i - 1] + colCounts[i - 1];
    }

    // Populate the transposed matrix
    for (int i = 0; i < matrix.numNonZero; ++i) {
        int col = matrix.elements[i].col;
        int index = colStartIndex[col];
        result.elements[index].row = matrix.elements[i].col;
        result.elements[index].col = matrix.elements[i].row;
        result.elements[index].value = matrix.elements[i].value;
        colStartIndex[col]++;
    }

    // Cleanup
    free(colCounts);
    free(colStartIndex);

    result.numNonZero = matrix.numNonZero;
    return result;
}

// Function to display a sparse matrix
void displaySparseMatrix(struct SparseMatrix matrix) {
    printf("Sparse Matrix:\n");
    for (int i = 0; i < matrix.numNonZero; ++i) {
        printf("%d %d %d\n", matrix.elements[i].row, matrix.elements[i].col, matrix.elements[i].value);
    }
}

int main() {
    struct SparseMatrix matrix1, matrix2, result, transposed;

    printf("Enter the number of rows, columns, and non-zero elements for matrix 1:\n");
    int rows1, cols1, nonZero1;
    scanf("%d %d %d", &rows1, &cols1, &nonZero1);
    initializeSparseMatrix(&matrix1, rows1, cols1, nonZero1);

    printf("Enter the number of rows, columns, and non-zero elements for matrix 2:\n");
    int rows2, cols2, nonZero2;
    scanf("%d %d %d", &rows2, &cols2, &nonZero2);
    initializeSparseMatrix(&matrix2, rows2, cols2, nonZero2);

    printf("Matrix 1:\n");
    displaySparseMatrix(matrix1);

    printf("Matrix 2:\n");
    displaySparseMatrix(matrix2);

    // Perform subtraction
    result = subtractMatrices(matrix1, matrix2);
    printf("Subtraction Result:\n");
    displaySparseMatrix(result);

    // Calculate transpose
    transposed = transposeMatrix(matrix1);
    printf("Transpose of Matrix 1:\n");
    displaySparseMatrix(transposed);

    // Clean up memory
    free(matrix1.elements);
    free(matrix2.elements);
    free(result.elements);
    free(transposed.elements);

    return 0;
}
