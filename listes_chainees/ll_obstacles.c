#include "ll_obstacles.h"

LL_OBSTACLE llo_create() {
    LL_OBSTACLE linked_list = {
        .first_node = NULL
    };
    return linked_list;
}


int llo_length(LL_OBSTACLE *linked_list) {
    int list_length = 0;
    LL_OBSTACLE_NODE *current_node = linked_list->first_node;
    while (current_node) {
        list_length++;
        current_node = current_node->next_node;
    }
    return list_length;
}

void llo_append(LL_OBSTACLE *linked_list, OBSTACLE new_data) {
    if (!linked_list->first_node) {
        linked_list->first_node = (LL_OBSTACLE_NODE*) malloc(sizeof(LL_OBSTACLE_NODE));
        linked_list->first_node->data = new_data;
        linked_list->first_node->next_node = NULL;
    } else {
        LL_OBSTACLE_NODE* last_node = linked_list->first_node;
        while (last_node->next_node) {
            last_node = last_node->next_node;
        }
        last_node->next_node = (LL_OBSTACLE_NODE*) malloc(sizeof(LL_OBSTACLE_NODE));
        last_node->next_node->data = new_data;
        last_node->next_node->next_node = NULL;
    }
}

OBSTACLE *llo_get(LL_OBSTACLE *linked_list, int index) {
    if (index >= llo_length(linked_list)) {
        exit(EXIT_FAILURE);
    }
    int current_index = 0;
    LL_OBSTACLE_NODE *current_node = linked_list->first_node;
    while (current_index != index) {
        current_node = current_node->next_node;
        current_index++;
    }
    return &current_node->data;
}

void llo_remove(LL_OBSTACLE *linked_list, int index) {
    if (index >= llo_length(linked_list)) {
        exit(EXIT_FAILURE);
    }
    LL_OBSTACLE_NODE *node_to_remove;
    if (index == 0) {
        node_to_remove = linked_list->first_node;
        linked_list->first_node = node_to_remove->next_node;
    } else {
        LL_OBSTACLE_NODE *previous_node = linked_list->first_node;
        int current_index = 0;
        while (current_index != index - 1) {
            previous_node = previous_node->next_node;
            current_index++;
        }
        node_to_remove = previous_node->next_node;
        LL_OBSTACLE_NODE *next_node = node_to_remove->next_node;
        previous_node->next_node = next_node;
    }
    free(node_to_remove);
}

void llo_free(LL_OBSTACLE *linked_list) {
    LL_OBSTACLE_NODE *current_node = linked_list->first_node, *next_node;
    while (current_node) {
        next_node = current_node->next_node;
        free(current_node);
        current_node = next_node;
    }
    linked_list->first_node = NULL;
}

