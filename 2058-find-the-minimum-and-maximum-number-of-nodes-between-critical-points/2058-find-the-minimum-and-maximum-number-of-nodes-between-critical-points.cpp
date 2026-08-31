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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int minDist = INT_MAX;

        int first = -1;       // position of first critical point
        int prev = -1;        // position of previous critical point

        int pos = 1;

        ListNode* prevNode = head;
        ListNode* curr = head->next;

        while (curr->next != nullptr) {

            ListNode* nextNode = curr->next;

            // Check whether curr is a critical point
            bool isCritical =
                (curr->val > prevNode->val && curr->val > nextNode->val) ||
                (curr->val < prevNode->val && curr->val < nextNode->val);

            if (isCritical) {

                if (first == -1) {
                    // First critical point
                    first = pos;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - prev);
                }

                prev = pos;
            }

            prevNode = curr;
            curr = nextNode;
            pos++;
        }

        // Fewer than two critical points
        if (first == -1 || first == prev) {
            return {-1, -1};
        }

        int maxDist = prev - first;

        return {minDist, maxDist};
    }
};