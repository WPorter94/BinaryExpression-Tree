//Copyright 2021
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
#include "Expression_Tree.h"
#include "Binary_Tree.h"
#include "BTNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Expression_Tree.h"

class newCxxTest : public CxxTest::TestSuite {
public:

	void test1() {
        Expression_Tree the_tree;
        string filename = "test.txt";
        ifstream inputFile;
        // Open the file
        inputFile.open(filename.c_str());
        the_tree.read_expression_tree(inputFile);
        double v = the_tree.evaluate();
        TS_ASSERT_EQUALS(v, 5);
	}
    void test2_BinTree_lSubtree() {
        Binary_Tree<std::string> BT;
        TS_ASSERT_THROWS_ANYTHING(BT.get_left_subtree());

    }
    void test3_BinTree_rSubtree() {
        Binary_Tree<std::string> BT;
        TS_ASSERT_THROWS_ANYTHING(BT.get_right_subtree());
    }
    void test4_BinTree_data() {
        Binary_Tree<std::string> BT;
        TS_ASSERT_THROWS_ANYTHING(BT.get_data());
    }
    void test5_BinTree_null() {
        Binary_Tree<std::string> BT;
        int tester = BT.is_null();
        TS_ASSERT_EQUALS(tester,1);
    }
    void test6_BinTree_leaf() {
        Binary_Tree<std::string> BT;
        int tester = BT.is_leaf();
        TS_ASSERT_EQUALS(tester, 1);
    }
    void test7_BinTree_tostring_null() {
        Binary_Tree<std::string> BT;
        string tester = BT.to_string();
        TS_ASSERT_EQUALS(tester, "NULL\n");
    }
    
    void test8_BinTree_tostring_true() {
        std::string data1 = "left";
        std::string data2 = "right";
        std::string data3 = "stuff";


        Binary_Tree<std::string> left(data1, Binary_Tree<std::string>(), Binary_Tree<std::string>());
        Binary_Tree<std::string> right(data2, Binary_Tree<std::string>(), Binary_Tree<std::string>());
        Binary_Tree<std::string> BT3(data3,left,right);
        string tester = BT3.to_string();
        TS_ASSERT_EQUALS(tester, "stuff\nleft\nNULL\nNULL\nright\nNULL\nNULL\n");
    }


};
#endif /*NEWCXXTEST_H*/
