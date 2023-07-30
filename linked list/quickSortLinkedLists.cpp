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
    vector<ListNode*> segregate (ListNode* head, int pivotIdx){
        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);
        ListNode* curr = head, *sp = small, *lp = large, *pivotNode = head;

        while (pivotIdx-- > 0) pivotNode = pivotNode->next;

        while (curr!=NULL){
            if (curr != pivotNode){
                if (curr->val <= pivotNode->val){
                    sp->next = curr;
                    sp = sp->next;
                }
                else{
                    lp->next = curr;
                    lp = lp->next;
                }
            }
            curr = curr->next;
        }
        sp->next = NULL;
        lp->next = NULL;
        pivotNode->next = NULL;

		return vector<ListNode*> {small->next, pivotNode, large->next};
    }

	int length(ListNode* node){
		if (node==NULL) return 0;
		ListNode* curr = node;
		int len = 0;
		while (curr != NULL){
			len++;
			curr = curr->next;
		}
		return len;
	}

	vector<ListNode*> mergeSortedLists(vector<ListNode*> leftSortedList, ListNode* pivotNode, vector<ListNode*> rightSortedList){
		ListNode* head = NULL, *tail = NULL;

		if (leftSortedList[0]!=NULL && rightSortedList[0]!=NULL){
			leftSortedList[1]->next = pivotNode;
			pivotNode->next = rightSortedList[0];
			head = leftSortedList[0];
			tail = rightSortedList[1];
		}

		else if (leftSortedList[0]!=NULL){
			head = leftSortedList[0];
			leftSortedList[1]->next = pivotNode;
			tail = pivotNode;
		}

		else if (rightSortedList[0]!=NULL){
			head = pivotNode;
			pivotNode->next = rightSortedList[0];
			tail = rightSortedList[1];
		}
		else{
			head = pivotNode;
			tail = pivotNode;
		}
		return vector<ListNode*> {head, tail};
	}

	vector<ListNode*> quickSort_(ListNode* head){
		if (head==NULL || head->next==NULL){
			return vector<ListNode*> {head, head};
		}
		int len = length(head);
		int pivotIdx = len/2;

		vector<ListNode*> segregatedLists = segregate(head, pivotIdx);
		vector<ListNode*> leftSortedList = quickSort_(segregatedLists[0]);
		vector<ListNode*> rightSortedList = quickSort_(segregatedLists[2]);

		return mergeSortedLists(leftSortedList, segregatedLists[1], rightSortedList);

	}

    ListNode* sortList(ListNode* head) {
        return quickSort_(head)[0];
    }
};