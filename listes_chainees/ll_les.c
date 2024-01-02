#include "ll_les.h"


LL_LE lll_create() {
    LL_LE linked_list = {
        .first_node = NULL
    };
    return linked_list;
}


int lll_length(LL_LE *linked_list) {
    int list_length = 0;
    LL_LE_NODE *current_node = linked_list->first_node;
    while (current_node) {
        list_length++;
        current_node = current_node->next_node;
    }
    return list_length;
}


void lll_append(LL_LE *linked_list, LE new_data) {
    if (!linked_list->first_node) {
        // if the list is empty, return a new link with the provided value
        linked_list->first_node = (LL_LE_NODE*) malloc(sizeof(LL_LE_NODE));
        linked_list->first_node->data = new_data;
        linked_list->first_node->next_node = NULL;
    }
    else {
        // otherwise, look for the last link of the list
        LL_LE_NODE* last_node = linked_list->first_node;
        while (last_node->next_node) {
            last_node = last_node->next_node;
        }
        // add a new link with the provided value
        last_node->next_node = (LL_LE_NODE*) malloc(sizeof(LL_LE_NODE));
        last_node->next_node->data = new_data;
        last_node->next_node->next_node = NULL;
    }
}


LE *lll_get(LL_LE *linked_list, int index) {
    if (index >= lll_length(linked_list)) {
        exit(EXIT_FAILURE);
    }
    int current_index = 0;
    LL_LE_NODE *current_node = linked_list->first_node;
    while (current_index != index) {
        current_node = current_node->next_node;
        current_index++;
    }
    return &current_node->data;
}


void lll_remove(LL_LE *linked_list, int index) {
    if (index >= lll_length(linked_list)) {
        exit(EXIT_FAILURE);
    }
    LL_LE_NODE *node_to_remove;
    if (index == 0) {
        // set the list first node as the second node (possibly NULL)
        node_to_remove = linked_list->first_node;
        linked_list->first_node = node_to_remove->next_node;
    }
    else {
        // get the node before and the node after (possibly NULL) the node to remove
        LL_LE_NODE *previous_node = linked_list->first_node;
        int current_index = 0;
        while (current_index != index - 1) {
            previous_node = previous_node->next_node;
            current_index++;
        }
        node_to_remove = previous_node->next_node;
        LL_LE_NODE *next_node = node_to_remove->next_node;
        // link the previous and the next nodes together
        previous_node->next_node = next_node;
    }
    // free the removed node
    free(node_to_remove);
}


void lll_free(LL_LE *linked_list) {
    LL_LE_NODE *current_node = linked_list->first_node, *next_node;
    while (current_node) {
        next_node = current_node->next_node;
        free(current_node);
        current_node = next_node;
    }
    linked_list->first_node = NULL;
}
