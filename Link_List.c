//
// Created by Sakura on 2022/3/21.
//

#include "stdio.h"
#include "stdlib.h"
#include "Link_List.h"

/*
 * -> 此链表为带头节点型单链表
 * 1. 定义节点抽象类型
 * 2. 分配内存空间（实例化）
 * 3. 增删改查
 */

typedef struct Node{
    int value;
    struct Node* next;
}node;


node* head_node_creat(){
    node* head_node = (node*) malloc(sizeof (node));
    head_node->value = 0;
    head_node->next = NULL;

    return head_node;
}


int node_invert_with_tail(node* head_node, int x){
    node* normal_node = (node*) malloc(sizeof (node));
    normal_node->next = NULL;
    normal_node->value = x;

//    判断所插入节点是否为第一个节点
    if(head_node->next == NULL){
        head_node->next = normal_node;
    }

    else{
        while(head_node->next != NULL){
            head_node = head_node->next;
        }
        head_node->next = normal_node;
    }

    return 0;
}


int print_link_list(node* head_node){
    while (head_node->next != NULL){
        printf("%d->", head_node->next->value);
        head_node = head_node->next;
    }
    printf("null\n");

    return 0;
}


int link_list_test(){
    node* head_node;
    head_node = head_node_creat();
    node_invert_with_tail(head_node, 1);
    node_invert_with_tail(head_node, 2);
    node_invert_with_tail(head_node, 3);
    print_link_list(head_node);

    return 0;
}
