#include "gtest.h"
#include "tstack.h"


TEST(tstack, push_and_peek) 
{
    Stack<int> s;
    s.push(10);
    ASSERT_EQ(s.peek(), 10);
    s.push(20);
    ASSERT_EQ(s.peek(), 20);
}

TEST(tstack, pop) 
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.pop();
    ASSERT_EQ(s.peek(), 10);
    s.pop();
    ASSERT_TRUE(s.empty());
}

TEST(tstack, empty_and_size) 
{
    Stack<int> s;
    ASSERT_TRUE(s.empty());
    ASSERT_EQ(s.get_size(), 0);
    s.push(10);
    ASSERT_FALSE(s.empty());
    ASSERT_EQ(s.get_size(), 1);
}

TEST(tstack, clear) 
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.clear();
    ASSERT_TRUE(s.empty());
    ASSERT_EQ(s.get_size(), 0);
}

TEST(tstack, peek_empty_exception) 
{
    Stack<int> s;
    ASSERT_ANY_THROW(s.peek());
}

TEST(tstack, pop_empty_exception) 
{
    Stack<int> s;
    ASSERT_ANY_THROW(s.pop());
}

TEST(tstack, push_multiple_elements) 
{
    Stack<std::string> s;
    s.push("one");
    s.push("two");
    s.push("three");
    ASSERT_EQ(s.get_size(), 3);
    ASSERT_EQ(s.peek(), "three");
}

TEST(tstack, pop_multiple_elements) 
{
    Stack<double> s;
    s.push(1.1);
    s.push(2.2);
    s.push(3.3);
    s.pop();
    ASSERT_EQ(s.peek(), 2.2);
    s.pop();
    ASSERT_EQ(s.peek(), 1.1);
}

TEST(tstack, large_number_of_elements) 
{
    Stack<int> s;
    for (int i = 0; i < 1000; ++i) {
        s.push(i);
    }
    ASSERT_EQ(s.get_size(), 1000);
    for (int i = 999; i >= 0; --i) {
        ASSERT_EQ(s.peek(), i);
        s.pop();
    }
    ASSERT_TRUE(s.empty());
}

TEST(tstack, string_data) 
{
    Stack<std::string> s;
    s.push("hello");
    s.push("world");
    ASSERT_EQ(s.peek(), "world");
}

TEST(tstack, assignment_operator) 
{
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    Stack<int> s2;
    s2 = s1; 
    ASSERT_EQ(s2.get_size(), 2);
    ASSERT_EQ(s2.peek(), 2);

    s1.pop();  
    ASSERT_EQ(s1.get_size(), 1);
    ASSERT_EQ(s2.get_size(), 2);
}

TEST(tstack, self_assignment_operator)
{
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1 = s1;
    ASSERT_EQ(s1.get_size(), 2);
    ASSERT_EQ(s1.peek(), 2);
}

TEST(tstack, copy_constructor) 
{
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    Stack<int> s2 = s1; 
    ASSERT_EQ(s2.get_size(), 2);
    ASSERT_EQ(s1.peek(), 2);
    ASSERT_EQ(s2.peek(), 2);

    s1.pop();
    ASSERT_EQ(s1.get_size(), 1);
    ASSERT_EQ(s2.get_size(), 2);
}