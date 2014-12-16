package com.xwang3d.leetcode;

/**
 * Created by Fish on 12/15/14.
 */
public class CompareVersionNumbers {
    public int compareVersion(String version1, String version2) {
        String[] components1 = version1.split("\\.");
        String[] components2 = version2.split("\\.");

        int size1 = components1.length;
        int size2 = components2.length;
        int min = Math.min(size1, size2);

        for (int i = 0; i < min; ++i) {
            int v1 = Integer.parseInt(components1[i]);
            int v2 = Integer.parseInt(components2[i]);
            if (v1 == v2)
                continue;

            return (v1 > v2) ? 1 : -1;
        }

        if (size1 == size2)
            return 0;

        if (size1 > size2)
        {
            for (int i = size2; i < size1; ++i)
            {
                if (Integer.parseInt(components1[i]) != 0)
                    return 1;
            }
            return 0;
        }
        else
        {
            for (int i = size1; i < size2; ++i)
            {
                if (Integer.parseInt(components2[i]) != 0)
                    return -1;
            }
            return 0;
        }
    }
}
