package com.xwang3d.leetcode;

/**
 * Created by Fish on 2/8/15.
 */
public class ReverseNodesInKGroup {

    public ListNode reverseKGroup(ListNode head, int k) {

        if (head == null)
            return null;

        ListNode current = head;

        while (current.next != null)
        {
            int i = k;
            while (i > 0)
            {

            }
        }
    }

    private boolean isListLongerOrEqualToSize(ListNode head, int length) {

        if (length < 0)
            throw new IllegalArgumentException("Can't compare size with negative number");

        if (length == 0)
            return (head != null);

        if (head == null)
            return false;

        int size = 1;

        ListNode current = head;

        while (current.next != null)
        {
            current = current.next;
            if (++size > length)
                return true;
        }

        return false;
    }

    /**
     * Reverse the linked list
     * @param head
     * @param minLength the minimal length for the linked list to be reversed. If the linked list is less than the
     *                  minLength, the original list is returned.
     * @return the head of the new linked list.
     */
    private ListNode reverse(ListNode head, int minLength) {

        if (head == null || head.next == null)
            return head;

        ListNode current = head;
        ListNode prev = null;
        ListNode next = current.next;

        int size = 0;

        while (next != null)
        {
            ++size;
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        if (size < minLength)
        {
            return reverse(current, 0);
        }
        else
        {
            return current;
        }
    }
}
