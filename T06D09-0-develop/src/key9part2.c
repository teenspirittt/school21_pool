#include <stdio.h>

#define N 100

int sum(int *buff1, int len1, int *buff2, int len2, int *result) {
    int main_len;
    int len_of_result = 0;
    int flag ;
    int carry = 0;
    if (len1 >= len2) {
        main_len = len1;
        flag = 0;
    } else {
        main_len = len2;
        flag = 1;
    }
    if (flag == 0)
        for (int i = main_len; i >= 0; --i) {
            if ((i - (len1 - len2)) < 0) {
                result[i] = buff1[i] + carry;
                len_of_result++;
                carry = 0;
            } else if ((i - (len1 - len2)) >= 0) {
                result[i] = buff1[i] + buff2[i - (len1 - len2)] + carry;
                len_of_result++;
                carry = 0;
            }

            if (result[i] > 10) {
                carry = result[i] / 10;
                result[i] = result[i] - 10;
            } else if (result[i] == 10) {
                carry = 1;
                result[i] = 0;
            }
        }
    if (flag == 1) {
        for (int i = main_len; i >= 0; --i) {
            if ((i - (len2 - len1)) < 0) {
                result[i] = buff2[i] + carry;
                len_of_result++;
                carry = 0;
            } else if ((i - (len2 - len1)) >= 0) {
                result[i] = buff2[i] + buff1[i - (len2 - len1)] + carry;
                len_of_result++;
                carry = 0;
            }

            if (result[i] > 10) {
                carry = result[i] / 10;
                result[i] = result[i] - 10;
            } else if (result[i] == 10) {
                carry = 1;
                result[i] = 0;
            }
        }
    }
    return len_of_result;
}

int sub(int *buff1, int len1, int *buff2, int len2, int *result){
    int main_len = len1;
    int carry = 0;
    int len_of_result=0;
    if (len2 > len1) {
        printf("n/a");
        return -1;
    }
    for (int i = main_len; i >= 0; --i) {
        if ((i - (len1 - len2)) < 0) {
            result[i] = buff1[i] + carry;
            len_of_result++;
            carry = 0;
        } else if ((i - (len1 - len2)) >= 0) {
            result[i] = buff1[i] - buff2[i - (len1 - len2)] + carry;
            len_of_result++;
            carry = 0;
            if ((result[i] < 0) && (i != main_len)) carry = -1;

        }

        if (result[i] < 0) {
            result[i] = buff1[i]+10 - buff2[i - (len1 - len2)]+carry;
            carry = -1;

        }
    }
    return len_of_result;
}


int check(int *a) {
    char c;

    if ((scanf("%d", a) != 1)) {
        printf("n/a");
        return -1;
    }
    if ((scanf("%c", &c) != 0) && (c != ' ')) {
        if (c == '\n')
            return 2;
        printf("n/a");
        return -1;
    }
    return 0;
}


int input(int *a) {
    int num;
    int flag, cnt = 0;
    for (int i = 0; i < N; ++i) {
        flag = check(&num);
        if (num > 9){
            printf("n/a");
            return -1;
        }
        if (flag == -1) return -1;
        else if (flag == 2) {
            a[i] = num;
            cnt++;
            break;
        }
        a[i] = num;
        cnt++;

    }

    return cnt;
}

void output(int *a, int n) {
    int flag = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            if (a[i] == 0){
                flag = 1;
                continue;

            }
        } else if (flag == 1){
            if ((a[i] == 0) && (a[i-1] == 0))
                continue;
        }
        printf("%d ", a[i]);
    }
}

int main() {
    int  data_1[N], data_2[N];
    int result1[N], result2[N];
    int len1, len2, len_res;
    len1 = input(data_1) - 1;
    if (len1 == -2) return -1;
    if (len1 + 1 >= 100){
        printf("n/a");
        return -1;
    }
    len2 = input(data_2) - 1;
    if (len2 + 1 >= 100){
        printf("n/a");
        return -1;
    }
    if (len2 == -2) return -1;

    len_res = sum(data_1, len1, data_2, len2, result1);
    output(result1, len_res);
    printf("\n");
    len_res = sub(data_1, len1, data_2, len2, result2);

    output(result2, len_res);
    return 0;
}


