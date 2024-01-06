#include "ll_murs.h"


LL_MUR llm_create() {
    LL_MUR linked_list = {
        .first_node = NULL
    };
    return linked_list;
}


int llm_length(LL_MUR *linked_list) {
    int list_length = 0;
    LL_MUR_NODE *current_node = linked_list->first_node;
    while (current_node) {
        list_length++;
        current_node = current_node->next_node;
    }
    return list_length;
}


void llm_append(LL_MUR *linked_list, MUR new_data) {
    if (!linked_list->first_node) {
        // if the list is empty, return a new link with the provided value
        linked_list->first_node = (LL_MUR_NODE*) malloc(sizeof(LL_MUR_NODE));
        linked_list->first_node->data = new_data;
        linked_list->first_node->next_node = NULL;
    }
    else {
        // otherwise, look for the last link of the list
        LL_MUR_NODE* last_node = linked_list->first_node;
        while (last_node->next_node) {
            last_node = last_node->next_node;
        }
        // add a new link with the provided value
        last_node->next_node = (LL_MUR_NODE*) malloc(sizeof(LL_MUR_NODE));
        last_node->next_node->data = new_data;
        last_node->next_node->next_node = NULL;
    }
}


MUR *llm_get(LL_MUR *linked_list, int index) {
    if (index >= llm_length(linked_list)) {
        exit(EXIT_FAILURE);
    }
    int current_index = 0;
    LL_MUR_NODE *current_node = linked_list->first_node;
    while (current_index != index) {
        current_node = current_node->next_node;
        current_index++;
    }
    return &current_node->data;
}


void llm_remove(LL_MUR *linked_list, int index) {
    if (index >= llm_length(linked_list)) {
        exit(EXIT_FAILURE);
    }
    LL_MUR_NODE *node_to_remove;
    if (index == 0) {
        // set the list first node as the second node (possibly NULL)
        node_to_remove = linked_list->first_node;
        linked_list->first_node = node_to_remove->next_node;
    }
    else {
        // get the node before and the node after (possibly NULL) the node to remove
        LL_MUR_NODE *previous_node = linked_list->first_node;
        int current_index = 0;
        while (current_index != index - 1) {
            previous_node = previous_node->next_node;
            current_index++;
        }
        node_to_remove = previous_node->next_node;
        LL_MUR_NODE *next_node = node_to_remove->next_node;
        // link the previous and the next nodes together
        previous_node->next_node = next_node;
    }
    // free the node linked lists
    lll_free(&node_to_remove->data.liste_les);
    llo_free(&node_to_remove->data.liste_obstacles);
    // free the removed node
    free(node_to_remove);
}


void llm_free(LL_MUR *linked_list) {
    LL_MUR_NODE *current_node = linked_list->first_node, *next_node;
    while (current_node) {
        // free the current node linked lists
        lll_free(&current_node->data.liste_les);
        llo_free(&current_node->data.liste_obstacles);
        next_node = current_node->next_node;
        // free the current node
        free(current_node);
        current_node = next_node;
    }
    linked_list->first_node = NULL;
}
