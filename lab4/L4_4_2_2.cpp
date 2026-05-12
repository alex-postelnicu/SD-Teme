/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
struct cmp
{
    bool operator()(ListNode* u, ListNode* v)
    {
        return u->val>v->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp>pq;
        for (auto it : lists)
        {
            if (it!=nullptr)
                pq.push(it);
        }
        ListNode ans;
        ListNode* last=&ans;
        while (!pq.empty())
        {
            ListNode* mn=pq.top();
            pq.pop();
            last->next=mn;
            last=last->next;
            if (mn->next!=nullptr)
            {
                pq.push(mn->next);
            }
        }
        return ans.next;
    }
};
