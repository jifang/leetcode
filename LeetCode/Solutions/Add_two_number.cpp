class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	
		ListNode *pL1 = l1;
		ListNode *pL2 = l2;
		ListNode *pLRest = NULL;
		ListNode *pPrev = NULL;
		ListNode *pHead = NULL;
		
		int carry = 0;
		
		do
		{			
			if (pL1 == NULL)
			{
				pLRest = pL2;
				break;
			}
			
			if (pL2 == NULL)
			{
				pLRest = pL1;
				break;
			}
			
			ListNode *pNew = new ListNode(carry);
			pNew->val += pL1->val + pL2->val;
			
			if (pNew->val >= 10)
			{
				pNew->val -= 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			
			if (pPrev)
				pPrev->next = pNew;
			
			pPrev = pNew;
			pL1 = pL1->next;
			pL2 = pL2->next;
			
			if (!pHead)
				pHead = pNew;
			
		} while (true);
        
		while (pLRest != NULL)
		{
			ListNode *pNew = new ListNode(carry);
			pNew->val += pLRest->val;
			
			if (pNew->val >= 10)
			{
				pNew->val -= 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			
			if (pPrev)
				pPrev->next = pNew;
			
			pPrev = pNew;
			pLRest = pLRest->next;
		}
		
       	if (carry)
		{
			ListNode *pNew = new ListNode(1);
			pPrev->next = pNew;
		}
		return pHead;
    }
};