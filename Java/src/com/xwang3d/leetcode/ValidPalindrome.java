package com.xwang3d.leetcode;

/**
 * Created by Fish on 12/15/14.
 */
public class ValidPalindrome {
    public boolean isPalindrome(String s) {
        StringBuilder reversed = new StringBuilder();
        StringBuilder original = new StringBuilder();

        for (int i = 0; i < s.length(); ++i)
        {
            char c = s.charAt(i);
            if (Character.isLetterOrDigit(c))
                original.append(c);

            c = s.charAt(s.length() - i - 1);
            if (Character.isLetterOrDigit(c))
                reversed.append(c);
        }

        return (original.toString().compareToIgnoreCase(reversed.toString()) == 0);

    }
}
