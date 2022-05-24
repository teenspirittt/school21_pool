#ifndef DATA_IO_MACRO_H
#define DATA_IO_MACRO_H

#define ERROR 1

int input_int(int *data, int *n);
int input_float(float *data, int *n);
int input_double(double *data, int *n);
void output_int(int *data, int n);
void output_float(float *data, int n);
void output_double(double *data, int n);
#define input(data, n)  \
    _Generic ( (DATA, N),  \
    int: input_int,     \
    float:input_float,  \ 
    double:input_double,\
    default:input_int   \
    ) (DATA)

#define output(data, n)  \
    _Generic ( (DATA, N),  \
    int: output_int,     \
    float:output_float,  \
    double:output_double,\
    default:output_int   \
    ) (DATA)

#endif