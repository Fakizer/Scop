#ifndef MATRIX_H
# define MATRIX_H

typedef struct  s_matrix
{
    int         rows;
    int         cols;     
    float         **mat;
}               t_matrix;

t_matrix        new_matrix(int r, int c);
t_matrix        identity(int dimension);
t_matrix        new_viewport(int x, int y, int w, int h);
t_matrix        matrix_mult(t_matrix m1, t_matrix m2);
t_matrix        v2m(t_vect3f v);
t_vect3f        m2v(t_matrix m);



#endif