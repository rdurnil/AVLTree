//----------------------------------------------------------------------
// Name: Rie Durnil
// File: hw8_test.cpp
// Date: Fall 2020
// Desc: Unit tests for AVL tree collection implementation
//----------------------------------------------------------------------


#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "array_list.h"
#include "avl_collection.h"


using namespace std;


// Helper function to print out a key-value collection
template<typename K,typename V>
void print(const Collection<K,V>& kv_list)
{
  cout << "{";
  ArrayList<K> the_keys;
  kv_list.keys(the_keys);
  for (size_t i = 0; i < the_keys.size(); ++i) {
    K key;
    V val;
    the_keys.get(i, key);
    kv_list.find(key, val);
    cout << key << ": " << val;
    if (i < the_keys.size() - 1)
      cout << ", ";
  }
  cout << "}";
}

// Helper function to check membership in a list
template<typename T>
bool member(const T& member_val, const List<T>& list)
{
  for (int i = 0; i < list.size(); ++i) {
    T list_val;
    list.get(i, list_val);
    if (list_val == member_val)
      return true;
  }
  return false;
}


// Test 1: Check add and size
TEST(AVLCollectionTest, CorrectSize) {
  AVLCollection<string,int> c;
  ASSERT_EQ(0, c.size());
  c.add("b", 10);
  ASSERT_EQ(1, c.size());
  c.add("a", 20);
  ASSERT_EQ(2, c.size());
  c.add("c", 20);
  ASSERT_EQ(3, c.size());
}


// Test 2: Test add and find
TEST(AVLCollectionTest, SimpleFind) {
  AVLCollection<string,int> c;
  int v;
  ASSERT_EQ(false, c.find("b", v));
  c.add("b", 10);
  ASSERT_EQ(true, c.find("b", v));
  ASSERT_EQ(10, v);
  ASSERT_EQ(false, c.find("a", v));
  c.add("a", 20);
  ASSERT_EQ(true, c.find("a", v));
  ASSERT_EQ(20, v);
  ASSERT_EQ(false, c.find("c", v));
  c.add("c", 30);
  ASSERT_EQ(true, c.find("c", v));
  ASSERT_EQ(30, v);
}

// Test 3: Test add, size, and remove
TEST(AVLCollectionTest, SimpleRemove) {
  AVLCollection<string,int> c;
  c.add("b", 10);
  c.add("a", 20);
  c.add("c", 30);
  ASSERT_EQ(3, c.size());
  int v;
  // all three pairs in collection
  ASSERT_EQ(true, c.find("a", v));
  ASSERT_EQ(true, c.find("b", v));
  ASSERT_EQ(true, c.find("c", v));  
  // remove one
  c.remove("a");
  ASSERT_EQ(2, c.size());
  ASSERT_EQ(false, c.find("a", v));
  ASSERT_EQ(true, c.find("b", v));
  ASSERT_EQ(true, c.find("c", v));  
  // remove another
  c.remove("b");
  ASSERT_EQ(1, c.size());
  ASSERT_EQ(false, c.find("a", v));
  ASSERT_EQ(false, c.find("b", v));
  ASSERT_EQ(true, c.find("c", v));  
  // remove last one
  c.remove("c");
  ASSERT_EQ(0, c.size());
  ASSERT_EQ(false, c.find("a", v));
  ASSERT_EQ(false, c.find("b", v));
  ASSERT_EQ(false, c.find("c", v));  
}

// Test 4: Test add, size, and find range
TEST(AVLCollectionTest, SimpleRange) {
  AVLCollection<string,int> c;
  c.add("e", 50);
  c.add("c", 30);
  c.add("d", 40);
  c.add("f", 60);
  c.add("b", 20);
  // search for proper sublist of keys
  ArrayList<string> s1;
  c.find("c", "e", s1);
  ASSERT_EQ(3, s1.size());
  ASSERT_EQ(true, member(string("c"), s1));
  ASSERT_EQ(true, member(string("d"), s1));
  ASSERT_EQ(true, member(string("e"), s1));
  // search for overlapping prefix
  ArrayList<string> s2;
  c.find("a", "c", s2);
  ASSERT_EQ(2, s2.size());
  ASSERT_EQ(true, member(string("b"), s2));
  ASSERT_EQ(true, member(string("c"), s2));
  // search for overlapping suffix
  ArrayList<string> s3;
  c.find("e", "g", s3);
  ASSERT_EQ(2, s3.size());
  ASSERT_EQ(true, member(string("e"), s3));
  ASSERT_EQ(true, member(string("f"), s3));
  // search for empty sublist of keys
  ArrayList<string> s4;
  c.find("f", "b", s4);
  ASSERT_EQ(0, s4.size());
}



// Test 5: Test add and sort
TEST(AVLCollectionTest, SimpleSort) {
  AVLCollection<string,int> c;
  c.add("a", 10);
  c.add("e", 50);
  c.add("c", 30);
  c.add("b", 20);
  c.add("d", 40);
  ArrayList<string> sorted_keys;
  c.sort(sorted_keys);
  ASSERT_EQ(5, sorted_keys.size());
  // check if in sorted order
  for (size_t i = 1; i < sorted_keys.size(); ++i) {
    string k1;
    string k2;
    ASSERT_EQ(true, sorted_keys.get(i-1, k1));
    ASSERT_EQ(true, sorted_keys.get(i, k2));
    ASSERT_LT(k1, k2);
  }
}

// Test 6: copy and assignment operator
TEST(AVLCollectionTest, CopyAndAssignment) {
  AVLCollection<string,int> c1;
  c1.add("b", 20);
  c1.add("a", 10);
  c1.add("c", 30);
  AVLCollection<string,int> c2(c1);
  ASSERT_EQ(c1.size(), c2.size());
  c2.add("e", 50);
  ASSERT_NE(c1.size(), c2.size());
  c1 = c2;
  ASSERT_EQ(c1.size(), c2.size());
  c1 = c1;
  ASSERT_EQ(c1.size(), c2.size());
  AVLCollection<string,int> c3;
  c3.add("d", 40);
  c3 = c2 = c1;
  ASSERT_EQ(c3.size(), c2.size());
  ASSERT_EQ(c2.size(), c1.size());
  string keys[4] = {"a", "b", "c", "e"};
  for (int i = 0; i < c1.size(); ++i) {
    int v1, v2, v3;
    ASSERT_EQ(true, c1.find(keys[i], v1));
    ASSERT_EQ(true, c2.find(keys[i], v2));
    ASSERT_EQ(true, c3.find(keys[i], v3));
    ASSERT_EQ(v1, v2);
    ASSERT_EQ(v2, v3);
  }
}

// Test 7: remove of node with two children
TEST(AVLCollectionTest, RemoveNodeWithTwoChildren) {
  AVLCollection<string,int> c;
  c.add("b", 10);
  c.add("a", 20);
  c.add("d", 40);
  c.add("c", 30);
  c.add("e", 50);
  c.add("f", 60);
  ASSERT_EQ(6, c.size());
  // remove d (where right child has no left child)
  c.remove("d");
  ASSERT_EQ(5, c.size());
  ASSERT_EQ(3, c.height());
  // remove b (with right child having a left child)
  c.remove("b");
  ASSERT_EQ(4, c.size());
  ASSERT_EQ(3, c.height());
}

// Test 8: remove of node with two children, with left
TEST(AVLCollectionTest, RemoveNodeWithTwoChildrenWithLeft) {
  AVLCollection<string,int> c;
  c.add("b", 10);
  c.add("a", 20);
  c.add("d", 40);
  c.add("c", 30);
  c.add("e", 50);
  c.add("f", 60);
  ASSERT_EQ(6, c.size());
  // remove d
  c.remove("d");
  ASSERT_EQ(5, c.size());
  int v;
  ASSERT_EQ(true, c.find("f", v));
  ASSERT_EQ(60, v);
  ASSERT_EQ(3, c.height());
}

// Test 9: rebalance after add check
TEST(AVLCollectionTest, AddRebalanceCheck) {
  // left rotation
  AVLCollection<string,int> c1;
  c1.add("a", 10);
  c1.add("b", 20);
  c1.add("c", 30);
  ASSERT_EQ(2, c1.height());
  // right rotation
  AVLCollection<string,int> c2;
  c2.add("c", 30);
  c2.add("b", 20);
  c2.add("a", 10);
  ASSERT_EQ(2, c2.height());
  // left-right rotation
  AVLCollection<string,int> c3;
  c3.add("c", 30);
  c3.add("a", 10);
  c3.add("b", 20);
  ASSERT_EQ(2, c3.height());
  // right-left rotation
  AVLCollection<string,int> c4;
  c4.add("a", 10);
  c4.add("c", 30);
  c4.add("b", 20);
  ASSERT_EQ(2, c4.height());
  // right rotation
  AVLCollection<string,int> c5;
  c5.add("e", 50);
  c5.add("f", 60);
  c5.add("c", 30);
  c5.add("d", 40);
  c5.add("b", 20);
  c5.add("a", 10);
  ASSERT_EQ(3, c5.height());
  // right-left rotation
  AVLCollection<string,int> c6;
  c6.add("e", 50);
  c6.add("f", 60);
  c6.add("b", 20);
  c6.add("d", 40);
  c6.add("a", 10);
  c6.add("c", 30);
  ASSERT_EQ(3, c6.height());
  // right rotation
  AVLCollection<string,int> c7;
  c7.add("b", 20);
  c7.add("a", 10);
  c7.add("d", 40);
  c7.add("c", 30);
  c7.add("e", 50);
  c7.add("f", 60);
  ASSERT_EQ(3, c7.height());
  // left-right rotation
  AVLCollection<string,int> c8;
  c8.add("b", 20);
  c8.add("a", 10);
  c8.add("e", 50);
  c8.add("d", 40);
  c8.add("f", 60);
  c8.add("c", 30);
  ASSERT_EQ(3, c8.height());
}

// Test 10: rebalance after remove check
TEST(BasicListTest, RemoveRebalanceCheck) {
  // no children, rebalance
  AVLCollection<string,int> c1;
  c1.add("c", 30);
  c1.add("b", 20);
  c1.add("d", 40);
  c1.add("a", 10);
  ASSERT_EQ(3, c1.height());
  c1.remove("c");
  ASSERT_EQ(2, c1.height());
  // one child, rebalance
  AVLCollection<string,int> c2;
  c2.add("e", 50);
  c2.add("c", 30);
  c2.add("f", 60);
  c2.add("a", 10);
  c2.add("d", 40);
  c2.add("b", 20);
  c2.add("g", 70);
  ASSERT_EQ(4, c2.height());
  c2.remove("f");
  ASSERT_EQ(3, c2.height());
  // two children, rebalance
  AVLCollection<string,int> c3;
  c3.add("e", 50);
  c3.add("b", 20);
  c3.add("g", 70);
  c3.add("a", 10);
  c3.add("d", 40);
  c3.add("f", 60);
  c3.add("c", 30);
  ASSERT_EQ(4, c3.height());
  c3.remove("e");
  ASSERT_EQ(3, c3.height());
}


// TODO: Add at least 5 non-trival tests below for your AVL Collection
// class. Be sure for each test to provide comments describing the
// detailed purpose of each the test.

//Test 1: test keys
TEST(AVLCollectionTest, KeysTest) {
  AVLCollection<string, int> c;
  c.add("a", 1);
  c.add("b", 2);
  c.add("c", 3);
  ArrayList<string> k;
  c.keys(k);
  ASSERT_EQ(3, k.size());
  string h;
  int v;
  ASSERT_EQ(true, k.get(0, h));
  ASSERT_EQ(true, c.find(h, v));
  ASSERT_EQ(true, k.get(1, h));
  ASSERT_EQ(true, c.find(h, v));
  ASSERT_EQ(true, k.get(2, h));
  ASSERT_EQ(true, c.find(h, v));
}

//Test 2: Tests height and ensures that rebalance is occurring
TEST(AVLCollectionTest, HeightTest) {
  AVLCollection<string,int> c;
  c.add("a", 10);
  ASSERT_EQ(1, c.height());
  c.add("b", 4);
  c.add("c", 12);
  ASSERT_EQ(2, c.height());
  c.add("d", 73);
  c.add("e", 3);
  ASSERT_EQ(3, c.height());
  c.add("f", 5);
  ASSERT_EQ(3, c.height());
  c.add("g", 42);
  ASSERT_EQ(3, c.height());
  c.add("h", 2);
  ASSERT_EQ(4, c.height());
  c.remove("e");
  ASSERT_EQ(3, c.height());
  ASSERT_EQ(7, c.size());
}

//Test 3: Tests add and removing values that don't exist
TEST(AVLCollectionTest, CantRemove) {
  AVLCollection<string, int> c;
  c.remove("a");
  ASSERT_EQ(0, c.size());
  c.add("a", 2);
  c.add("b", 5);
  ASSERT_EQ(2, c.size());
  c.remove("c");
  ASSERT_EQ(2, c.size());
}

//Test 4: Tests remove, find, find range and sort on empty lists
TEST(AVLCollectionTest, EmptyLists) {
  AVLCollection<string, int> c;
  ASSERT_EQ(0, c.size());
  //test remove
  c.remove("a");
  ASSERT_EQ(0, c.size());
  //test find
  int v = -1;
  ASSERT_EQ(false, c.find("a", v));
  ASSERT_EQ(v, -1);
  //test find range
  ArrayList<string> k;
  c.find("a", "z", k);
  ASSERT_EQ(0, k.size());
  //test sort
  c.sort(k);
  ASSERT_EQ(0, k.size());
}

//Test 5: remove root
TEST(AVLCollectionTest, RemoveRoot) {
  AVLCollection<string,int> c;
  c.add("b", 4);
  c.add("a", 1);
  c.add("c", 7);
  c.add("d", 6);
  ASSERT_EQ(3, c.height());
  c.remove("b");
  ASSERT_EQ(2, c.height());
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

