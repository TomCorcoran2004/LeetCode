#include <list>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int ListToNum(ListNode* Node)
    {
        int Num = 0;

        while (Node)
        {
            Num *= 10;
            Num += Node->val;
            Node = Node->next;
        }

        return Num;
    }

    ListNode* NumToList(int num)
    {
        ListNode* start = new ListNode;
        ListNode* current = start;

        while (num)
        {
            int last_digit = num % 10;
            current->val = last_digit;
 
            num -= last_digit;
            
            if (num == 0)
            {
                break;
            }
            else
            {
                num /= 10;

                current->next = new ListNode;
                current = current->next;
            }

        }

        return start;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int num = ListToNum(l1) + ListToNum(l2);
        return NumToList(num);
    }
};