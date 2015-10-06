package com.xwang3d.leetcode;

import java.util.List;

public class Main {

    public static void main(String[] args) {
	// write your code here
        printLists(new PascalsTriangle().generate(2));


    }

    static void printList(List<Integer> list)
    {
        for (Object l : list) {
            System.out.print(String.format("%s ", l.toString()));
        }
        System.out.println("");
    }

    static void printLists(List<List<Integer>> lists)
    {
        for (List<Integer> list : lists) {
            printList(list);
        }
        System.out.println("");
    }
}
