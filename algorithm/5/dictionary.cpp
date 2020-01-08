#include <stdio.h>
#include<string>
#include <iostream>
#include <cstring>
#define MAX_VALUE 10000 // float型定数

class Dictionary {
    private:
        std::string arr[MAX_VALUE];
        int hash(std::string const str);
    public:
        void insert(std::string const str);
        std::string find(std::string const str);
} dict;

int Dictionary::hash(std::string const str) {
    int idx = 0;
    for(int i=0; i<str.size(); i++) {
        if (str[i] == 'A') idx += 1000; 
        else if (str[i] == 'C') idx += 100;
        else if (str[i] == 'G') idx += 10;
        else if (str[i] == 'T') idx += 1;
        else throw "おかしいって";
    }
    return idx % MAX_VALUE;
}

void Dictionary::insert(std::string const str) {
    int idx = hash(str);
    arr[idx] = str;
}

std::string Dictionary::find(std::string const str) {
    int idx = hash(str);
    std::string res = arr[idx];
    if (res.empty()) {
        return "no";
    }
    return "yes";
}

int main() {
    try {
        int n;
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            char command[6], str[12];
            scanf("%s %s", command, str);
            if (strcmp(command, "insert") == 0) {
                dict.insert(str);
            } else if (strcmp(command, "find") == 0) {
                std::string res = dict.find(str);
                printf("%s\n", res.c_str());
            } else {
                throw "????";
            }
        }
    } catch(char* const err) {
        printf("%s", err);
    }

    return 0;
}