#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <locale>
#include <limits>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

// Iterative solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (NULL == head) return head;
        ListNode* next = head->next;
        head->next = NULL;
        while (NULL != next) {
            ListNode* new_next = next->next;
            next->next = head;
            head = next;
            next = new_next;
        }
        return head;
    }
};
