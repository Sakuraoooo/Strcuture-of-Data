//
// Created by Sakura on 2022/3/21.
//

#include "stdio.h"
#include "stdlib.h"
#include "Stack_of_Mine.h"

#define Max_length 10

/*
 * 1. 表示栈的抽象概念
 * 2. 为该栈分配一块内存空间（实体化）
 * 3. 增删改查操作
 */

typedef struct {
    int value[Max_length];
    int top;
    int bottom;
}stack_sakura;


stack_sakura* StackCreat(){
    stack_sakura *sta = (stack_sakura*) malloc(sizeof(stack_sakura));
    if (sta == NULL)
        printf("False");

    else
        sta->bottom = sta->top = 0;

    return sta;
}


int StackInput(stack_sakura *sta, int x){
    if(sta->top == Max_length - 1){
        printf("Stack Is Full");
    }

    else{
        sta->value[sta->top] = x;
        sta->top++;
    }

    return 0;
}


int StackOutput(stack_sakura *sta){
    if(sta->bottom == sta->top){
        printf("Stack Is Empty");
    }

    else{
        sta->value[sta->top] = sta->value[sta->top - 1];
        sta->top--;
    }

    return 0;
}


int PrintStack(stack_sakura *sta){
    int i;
    for(i=0; i<sta->top; i++){
        printf("%d->", sta->value[i]);
    }

    printf("null\n");
    return 0;
}


int StackTest(){
    stack_sakura *sta;
    sta = StackCreat();
    StackInput(sta, 1);
    StackInput(sta, 3);
    StackInput(sta, 5);
    StackOutput(sta);
    PrintStack(sta);

    return 0;
}
