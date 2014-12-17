package com.xwang3d.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Fish on 12/15/14.
 */
public class PascalsTriangle {
    public List<Integer> getRow(int rowIndex) {
        if (rowIndex < 0)
            return null;

        List<Integer> result = new ArrayList<Integer>();
        if (rowIndex == 0) {
            result.add(1);
            return result;
        }

        List<Integer> previousRow = this.getRow(rowIndex - 1);
        result.add(previousRow.get(0));
        for (int i = 1; i < previousRow.size(); ++i)
        {
            result.add(previousRow.get(i - 1) + previousRow.get(i));
        }
        result.add(previousRow.get(previousRow.size() - 1));

        return result;
    }

    public List<List<Integer>> generate(int numRows) {

        List<List<Integer>> results = new ArrayList<List<Integer>>();
        if (numRows <= 0)
            return results;

        // First row [1]
        results.add(new ArrayList<Integer>());
        results.get(0).add(1);

        for (int i = 1; i < numRows; ++i)
        {
            List<Integer> prev = results.get(i - 1);
            List<Integer> result = new ArrayList<Integer>();
            result.add(prev.get(0));
            for (int j = 1; j < i ; ++j)
            {
                result.add(prev.get(j - 1) + prev.get(j));
            }
            result.add(prev.get(i - 1));
            results.add(result);
        }

        return results;
    }
}
