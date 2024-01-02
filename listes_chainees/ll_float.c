#include "ll_float.h"


LL_FLOAT llf_create() {
    LL_FLOAT linked_list = {
        .first_node = NULL
    };
    return linked_list;
}


int llf_length(LL_FLOAT *linked_list) {
    int list_length = 0;
    LL_FLOAT_NODE *current_node = linked_list->first_node;
    while (current_node) {
        list_length++;
        current_node = current_node->next_node;
    }
    return list_length;
}


void llf_append(LL_FLOAT *linked_list, float new_data) {
    if (!linked_list->first_node) {
        // if the list is empty, return a new link with the provided value
        linked_list->first_node = (LL_FLOAT_NODE*) malloc(sizeof(LL_FLOAT_NODE));
        linked_list->first_node->data = new_data;
        linked_list->first_node->next_node = NULL;
    }
    else {
        // otherwise, look for the last link of the list
        LL_FLOAT_NODE* last_node = linked_list->first_node;
        while (last_node->next_node) {
            last_node = last_node->next_node;
        }
        // add a new link with the provided value
        last_node->next_node = (LL_FLOAT_NODE*) malloc(sizeof(LL_FLOAT_NODE));
        last_node->next_node->data = new_data;
        last_node->next_node->next_node = NULL;
    }
}


float *llf_get(LL_FLOAT *linked_list, int index) {
    if (index >= llf_length(linked_list)) {
        exit(EXIT_FAILURE);
    }
    int current_index = 0;
    LL_FLOAT_NODE *current_node = linked_list->first_node;
    while (current_index != index) {
        current_node = current_node->next_node;
        current_index++;
    }
    return &current_node->data;
}


void llf_remove(LL_FLOAT *linked_list, int index) {
    if (index >= llf_length(linked_list)) {
        exit(EXIT_FAILURE);
    }
    LL_FLOAT_NODE *node_to_remove;
    if (index == 0) {
        // set the list first node as the second node (possibly NULL)
        node_to_remove = linked_list->first_node;
        linked_list->first_node = node_to_remove->next_node;
    }
    else {
        // get the node before and the node after (possibly NULL) the node to remove
        LL_FLOAT_NODE *previous_node = linked_list->first_node;
        int current_index = 0;
        while (current_index != index - 1) {
            previous_node = previous_node->next_node;
            current_index++;
        }
        node_to_remove = previous_node->next_node;
        LL_FLOAT_NODE *next_node = node_to_remove->next_node;
        // link the previous and the next nodes together
        previous_node->next_node = next_node;
    }
    // free the removed node
    free(node_to_remove);
}


void llf_free(LL_FLOAT *linked_list) {
    LL_FLOAT_NODE *current_node = linked_list->first_node, *next_node;
    while (current_node) {
        next_node = current_node->next_node;
        free(current_node);
        current_node = next_node;
    }
    linked_list->first_node = NULL;
}
