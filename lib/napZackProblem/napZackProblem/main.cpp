//
//  main.cpp
//  napZackProblem
//
//  Created by 高橋 誠二 on 2015/04/26.
//  Copyright (c) 2015年 高橋 誠二. All rights reserved.
//

// http://judge.u-aizu.ac.jp/onlinejudge/commentary.jsp?id=DPL_1_B

#include <iostream>

#define N 5
int size[N] = {5, 3, 2, 9, 6};
int value[N] = {7, 4, 2, 14, 10};

#define NAP_SIZE 16

int main(int argc, const char * argv[]) {
    // insert code here...
    int nap_value[NAP_SIZE + 1] = {0};
    int i,j,new_value;
    
    printf("ナップザックの大きさ  ");
    for (i = 1; i < NAP_SIZE + 1; i++) {
        printf("%2d ", i);
    }
    printf("\n\n");
    
    for (i = 0; i < N; i++) {
        for (j=size[i]; j<NAP_SIZE+1; j++) {
            new_value = nap_value[j - size[i]] + value[i];
            if (new_value > nap_value[j]) {
                nap_value[j] = new_value;
            }
        }
        printf("     品物 %dまで使う: ", i+1);
        for (j=1; j < NAP_SIZE+1; j++) {
            printf("%2d ", nap_value[j]);
        }
        printf("\n");
    }
    return 0;
}
