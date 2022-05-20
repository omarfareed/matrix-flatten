#include <iostream>
using std::cin;
using std::cout;
using std::endl;
bool validIndex(int i, int j, int k, int n, int m, int p)
{
    return i >= 0 && i < n && j >= 0 && j < m && k >= 0 && k < p;
}
int getFlattenedIndex(int i, int j, int k, int n, int m, int p)
{
    if (!validIndex(i, j, k, n, m, p))
        return -1;
    return i * m * p + j * p + k;
}
void fillFlattenedVector(int ***matrix, int *flattenedVector, int n, int m, int p)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                flattenedVector[getFlattenedIndex(i, j, k, n, m, p)] = matrix[i][j][k];
            }
        }
    }
}

int getFlattenedVectorSize(int n, int m, int p)
{
    return n * m * p;
}
int *createVector(int size)
{
    return new int[size];
}
void create2DMatrix(int **&matrix, int m, int p)
{
    matrix = new int *[m];
    for (int j = 0; j < m; j++)
        matrix[j] = createVector(p);
}
void create3DMatrix(int ***&matrix, int n, int m, int p)
{
    matrix = new int **[n];
    for (int i = 0; i < n; i++)
        create2DMatrix(matrix[i], m, p);
}

void read3DMatrix(int ***matrix, int n, int m, int p)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                cin >> matrix[i][j][k];
            }
        }
    }
}
int main()
{
    int n, m, p;
    cout << "Please Enter message dimensions: (n) (m) (p)" << endl;
    cin >> n >> m >> p;
    int ***matrix;
    create3DMatrix(matrix, n, m, p);
    cout << "Enter matrix elements : " << endl;
    read3DMatrix(matrix, n, m, p);
    int flattenedVectorSize = getFlattenedVectorSize(n, m, p);
    int *flattenedVector = createVector(flattenedVectorSize);
    fillFlattenedVector(matrix, flattenedVector, n, m, p);
    cout << "Flattened vector : " << endl;
    for (int i = 0; i < flattenedVectorSize; i++)
        cout << flattenedVector[i] << " ";
    return 0;
}