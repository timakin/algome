//
//  main.cpp
//  hashtable
//
//  Created by Seiji Takahashi on 2015/04/20.
//  Copyright (c) 2015年 Seiji Takahashi. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

typedef struct {
    char *english;
    char *japanese;
} WORDSET;

typedef struct {
    WORDSET **data;
    unsigned int size;
} HASHTABLE;

unsigned int MakeHash2(char* str, unsigned int hashmax) {
    unsigned int n, length, hash, weight;
    
    length = strlen(str);
    for (n = weight = hash = 0; n < length; n++, weight++) {
        if (weight > 7) {
            weight = 0;
        }
        hash += (int)str[n] << (4 * weight);
    }
    return hash % hashmax;
}

unsigned int ReHash(HASHTABLE *hashtable, unsigned int firsthash) {
    unsigned int hashval, k;
    for (k = 1; k<=hashtable->size/2; k++) {
        hashval = (firsthash + k * k) % hashtable->size;
        if (hashtable->data[hashval] == NULL) {
            return hashval;
        }
    }
    
    return -1;
}

void AddDataToMap(HASHTABLE *hashtable, WORDSET *newdata) {
    unsigned int hashval;
    
    hashval = MakeHash2(newdata->english, hashtable->size);
    if (hashtable->data[hashval] == NULL) {
        hashval = ReHash(hashtable, hashval);
        
        if (hashval == -1) {
            printf("%sをマップに挿入しようとしましたが、空きがありませんでした", newdata->english);
            return;
        }
    }
    hashtable->data[hashval] = newdata;
}

char *GetDataFromMap(HASHTABLE *hashtable, char *key) {
    unsigned int hashval, k;
    WORDSET *word;
    hashval = MakeHash2(key, hashtable->size);
    
    for (k = 0; k < hashtable->size / 2; k++) {
        word = hashtable->data[(hashval + k * k) % hashtable->size];
        if(word != NULL) {
            if (strcmp(key, word->english) == 0) {
                return word->japanese;
            }
        }
    }
    return NULL;
}

WORDSET *DeleteDataFromMap(HASHTABLE *hashtable, char *key) {
    unsigned int hashval, k;
    WORDSET *word;
    hashval = MakeHash2(key, hashtable->size);
    
    for (k = 0; k <= hashtable->size / 2; k++) {
        word = hashtable->data[(hashval + k * k) % hashtable->size];
        if (word != NULL) {
            if (strcmp(key, word->english) == 0) {
                hashtable->data[(hashval + k * k) % hashtable->size] = NULL;
                return word;
            }
        }
    }
    return NULL;
}

void InitHashTable(HASHTABLE *hashtable, unsigned int size) {
    hashtable->data = (WORDSET **)malloc(sizeof(WORDSET *) * size);
    memset(hashtable->data, NULL, sizeof(WORDSET *) * size);
    hashtable->size = size;
}

void CleanupHashTable(HASHTABLE *hashtable) {
    free(hashtable->data);
    hashtable->size = 0;
}

void PrintAllData(HASHTABLE *hashtable) {
    unsigned int n;
    for (n=0; n<=hashtable->size; n++) {
        if(hashtable->data[n] != NULL) {
            printf("%d:%s|%s\n", n, hashtable->data[n]->english, hashtable->data[n]->japanese);
        }
    }
}

int main(int argc, const char * argv[]) {
    unsigned int n;
    char key[64], *japanese;
    HASHTABLE hashtable;
    WORDSET *wordfound;
    WORDSET words[5] = {
        {"dolphin", "イルカ"},{"beluga", "シロイルカ"},
        {"grampus", "シャチ"},{"medusa", "海月"},
        {"otter", "カワウソ"}
    };
    InitHashTable(&hashtable, 503);
    
    for (n=0; n < 5; n++) {
        AddDataToMap(&hashtable, &words[n]);
    }
}
