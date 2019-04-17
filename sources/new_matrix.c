#include "scop.h"

t_matrix        new_matrix(int r, int c)
{
    t_matrix matr;
    int i;
    int j;

    i = 0;
    matr.rows = r;
    matr.cols = c;
    matr.mat = (float**)malloc(sizeof(float*) * r);
    while (i < r)
    {
        matr.mat[i] = (float*)malloc(sizeof(float) * c);
        j = 0;
        while (j < c) 
        {
            matr.mat[i][j] = 0.f;
            j++;
        }
        i++;
    }

    return (matr);
}

t_matrix        identity(int dimension)
{
    t_matrix matr;
    int i;
    int j;

    matr = new_matrix(dimension, dimension);
    i = 0;
    while (i < dimension)
    {
        j = 0;
        while (j < dimension)
        {
            matr.mat[i][j] = (i == j ? 1.f : 0.f);
            j++;
        }
        i++;
    }
    return (matr);
}

t_matrix        new_viewport(int x, int y, int w, int h)
{
    t_matrix m;

    m = identity(4);

    m.mat[0][3] = x + w / 2.f;
    m.mat[1][3] = y + h / 2.f;
    m.mat[2][3] = depth / 2.f;

    m.mat[0][0] = w / 2.f;
    m.mat[1][1] = h / 2.f;
    m.mat[2][2] = depth / 2.f;
    return (m);
}

t_matrix        matrix_mult(t_matrix m1, t_matrix m2)
{
    t_matrix result;
    int i;
    int j;
    int k;

    if (m1.cols != m2.rows)
    {
        printf("blabla\n");
        exit(0);
    }
    result = new_matrix(m1.rows, m2.cols);
    i = 0;
    while (i < m1.rows)
    {
        j = 0;
        while (j < m2.cols)
        {
            result.mat[i][j] = 0.f;
            k = 0;
            while (k < m1.cols)
            {
                result.mat[i][j] += m1.mat[i][k] * m2.mat[k][j];
                k++;
            }
            j++;
        }
        i++;
    }
    return (result);
}

t_matrix        v2m(t_vect3f v)
{
    t_matrix m;

    m = new_matrix(4, 1);
    m.mat[0][0] = v.x;
    m.mat[1][0] = v.y;
    m.mat[2][0] = v.z;
    m.mat[3][0] = 1.f;
    return (m);
}

t_vect3f        m2v(t_matrix m)
{
    t_vect3f v;

    v = copy_vect3f(m.mat[0][0] / m.mat[3][0], m.mat[1][0] / m.mat[3][0],
                    m.mat[2][0] / m.mat[3][0]);
    return (v);
}
