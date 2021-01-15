#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define ERROR 0;
#define TRUE 1;

///KMP����һ
/*
//��ʼ������
int InitData(char** source, char** target, int** value) {

    char ch;
    int i = 0;

    (*source) = (char*)malloc(sizeof(char) * 100);
    (*target) = (char*)malloc(sizeof(char) * 100);
    (*value) = (int*)malloc(sizeof(int) * 100);


    if (!(*source) || !(*target) || !(*value))return ERROR;

    printf("������Ҫ����Դ�ַ���,��#����:\n");

    while ((ch = getchar()) != '#') {

        (*source)[i++] = ch;
        (*source)[i] = '\0';
    }
    getchar();  //��������

    i = 0;  //����
    printf("������Ҫƥ����ַ���,��#����:\n");

    while ((ch = getchar()) != '#') {
        (*target)[i++] = ch;
        (*target)[i] = '\0';
    }

    //��ʼ��value����
    for (i = 0; i < 100; i++) {
        (*value)[i] = 0;
    }
    return TRUE;
}


//�ó�target�е�ƥ��ֵ
int GetValue(char* target, int* value) {

    char* head, * tail;
    int temp;
    //ABCDABD
    //ABCDAB
    int i = 1, j = 0;
    head = (char*)malloc(sizeof(char) * 100);
    tail = (char*)malloc(sizeof(char) * 100);
    if (!head || !tail)return ERROR;

    for (i = 1; i < strlen(target); i++) {  //��ͷ��β

        j = 0;
        while (target[j] != '\0') {  //���Ƶ���ʱ����
            head[j] = target[j];
            tail[j] = target[j];
            j++;
            head[j] = '\0';
            tail[j] = '\0';
        }

        head[i] = '\0';
        tail[i + 1] = '\0';

        for (j = 0; j < i; j++) {
            if (strcmp(head, tail + 1 + j) == 0) {  //�Ƚ�
                value[i] = strlen(head);
                break;
            }
            temp = strlen(head) - 1;
            head[temp] = '\0';
        }
    }
}

//KMP�������
int KMP(char* source, char* target, int* value) {

    int i = 0, j = 0;

    while (i < strlen(source)) {  //�����ݣ�source�ߵ�β

        if (source[i] == target[j] && j < strlen(target)) {
            i++;
            j++;
        }
        else if (j >= strlen(target)) {
            printf("�ҵ�...");
            return TRUE;

        }
        else if (source[i] != target[j]) {
            if (j == 0) {
                j = 0;
                i++;
            }
            else {
                j = value[j - 1];
            }
        }
    }
    if (i >= strlen(source) && j >= strlen(target))printf("�ҵ�...");
    else printf("δ�ҵ�...");
    return ERROR;
}
int main() {
    char* source, * target; //sourceԴ�ַ�����targetҪƥ����ַ���
    int* value;  //���ƥ��ֵ
    int i = 0;

    InitData(&source, &target, &value);  //��ʼ���ַ���
    GetValue(target, value);
    KMP(source, target, value);
}
*/
