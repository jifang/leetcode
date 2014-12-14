package com.xwang3d.leetcode;

/**
 * Created by Fish on 12/13/14.
 */
public class IntersectionOfTwoLinkedLists {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        ListNode a = headA;
        ListNode tailA = null;
        int lengthA = 0;

        while (a != null)
        {
            tailA = a;
            a = a.next;
            ++lengthA;
        }

        ListNode b = headB;
        ListNode tailB = null;
        int lengthB = 0;

        while (b != null)
        {
            tailB = b;
            b = b.next;
            ++lengthB;
        }

        // One of the list is empty
        if (tailA == null || tailB == null)
            return null;

        // No intersection
        if (tailA != tailB)
            return null;

        a = headA;
        b = headB;

        int diff = lengthA - lengthB;
        if (diff > 0)
        {
            while (diff > 0)
            {
                --diff;
                a = a.next;
            }
        }
        else if (diff < 0)
        {
            while (diff < 0)
            {
                ++diff;
                b = b.next;
            }
        }

        while (a != b)
        {
            a = a.next;
            b = b.next;
        }

        return a;
    }
}
