#include "ll_rouleaux.h"


LL_ROULEAU llr_create() {
    LL_ROULEAU linked_list = {
        .first_node = NULL
    };
    return linked_list;
}


int llr_length(LL_ROULEAU *linked_list) {
    int list_length = 0;
    LL_ROULEAU_NODE *current_node = linked_list->first_node;
    while (current_node) {
        list_length++;
        current_node = current_node->next_node;
    }
    return list_length;
}


void llr_append(LL_ROULEAU *linked_list, ROULEAU new_data) {
    if (!linked_list->first_node) {
        linked_list->first_node = (LL_ROULEAU_NODE*) malloc(sizeof(LL_ROULEAU_NODE));
        linked_list->first_node->data = new_data;
        linked_list->first_node->next_node = NULL;
    } else {
        LL_ROULEAU_NODE* last_node = linked_list->first_node;
        while (last_node->next_node) {
            last_node = last_node->next_node;
        }
        last_node->next_node = (LL_ROULEAU_NODE*) malloc(sizeof(LL_ROULEAU_NODE));
        last_node->next_node->data = new_data;
        last_node->next_node->next_node = NULL;
    }
}


ROULEAU *llr_get(LL_ROULEAU *linked_list, int index) {
    if (index >= llr_length(linked_list)) {
        exit(EXIT_FAILURE);
    }
    int current_index = 0;
    LL_ROULEAU_NODE *current_node = linked_list->first_node;
    while (current_index != index) {
        current_node = current_node->next_node;
        current_index++;
    }
    return &current_node->data;
}


void llr_remove(LL_ROULEAU *linked_list, int index) {
    if (index >= llr_length(linked_list)) {
        exit(EXIT_FAILURE);
    }
    LL_ROULEAU_NODE *node_to_remove;
    if (index == 0) {
        node_to_remove = linked_list->first_node;
        linked_list->first_node = node_to_remove->next_node;
    } else {
        LL_ROULEAU_NODE *previous_node = linked_list->first_node;
        int current_index = 0;
        while (current_index != index - 1) {
            previous_node = previous_node->next_node;
            current_index++;
        }
        node_to_remove = previous_node->next_node;
        LL_ROULEAU_NODE *next_node = node_to_remove->next_node;
        previous_node->next_node = next_node;
    }
    // free the node linked lists
    llf_free(&node_to_remove->data.liste_chutes);
    // free the removed node
    free(node_to_remove);
}


void llr_free(LL_ROULEAU *linked_list) {
    LL_ROULEAU_NODE *current_node = linked_list->first_node, *next_node;
    while (current_node) {
        // free the node linked lists
        llf_free(&current_node->data.liste_chutes);
        next_node = current_node->next_node;
        // free the current node
        free(current_node);
        current_node = next_node;
    }
    linked_list->first_node = NULL;
}
