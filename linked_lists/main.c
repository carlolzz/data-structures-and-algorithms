# include "linked_lists.h"

int main() {

    size_t values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Get the array lenght
    size_t arr_len = (sizeof(values) / sizeof(values[0]));
    ListNode* nodeList = create_list_from(values, arr_len);
    print_list(nodeList);    

    ListNode* reversedList = reverse_linked_list(nodeList);
    print_list(reversedList);

    size_t to_beg = 11;
    size_t to_end = 0;    

    reversedList = add_to_list_at_beg(reversedList, to_beg);
    reversedList = add_to_list_at_end(reversedList, to_end);

    print_list(reversedList);

    // Free the list
    free_list(reversedList);

    return 0;

}