#include <gtest.h>
#include "queue.h"
#include <vector>

TEST(Queue, can_create_empty_queue)
{
    Queue<int> a(3);
    
    EXPECT_TRUE(a.empty());
}
TEST(Queue, can_copy_queue)
{
    Queue<int> a(3);
    a.push(1);
    a.push(2);
    a.push(3);

    Queue<int> b(a);

    EXPECT_EQ(a.size(), b.size());
    EXPECT_EQ(b, a);
}
TEST(Queue, can_assign_queue_with_equal_size)
{
    Queue<int> a(3);
    a.push(1);
    a.push(2);
    a.push(3);
    
    Queue<int> b(3);
    b = a;

    EXPECT_EQ(a, b);
}
TEST(Queue, can_assign_queue_with_diff_size)
{
    Queue<int> a(3);
    a.push(1);
    a.push(2);
    a.push(3);

    Queue<int> b(10);
    b = a;

    EXPECT_EQ(a, b);
}
TEST(Queue, can_get_first_elem)
{
    Queue<int> a(2);

    a.push(1);
    a.push(2);
    a.pop();
    a.push(3);

    EXPECT_EQ(2, a.get_first());
}
TEST(Queue, can_get_last_elem)
{
    Queue<int> a(2);

    a.push(1);
    a.push(2);
    a.pop();
    a.push(3);

    EXPECT_EQ(3, a.get_last());
}
TEST(Queue, can_push_elem_into_empty_queue)
{
    Queue<int> a(2);

    a.push(2);

    EXPECT_EQ(a.size(), 1);
    EXPECT_EQ(a.get_first(), 2);
    EXPECT_EQ(a.get_last(), 2);
}
TEST(Queue, can_push_elem_into_begin_of_buffer)
{
    Queue<int> a(2);

    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.pop();
    a.push(5);

    EXPECT_EQ(a.get_last(), 5);
    EXPECT_EQ(a.get_first(), 2);
}
TEST(Queue, can_pop_elem)
{
    Queue<int> a(3);

    a.push(3);
    a.pop();

    EXPECT_TRUE(a.empty());
}
TEST(Queue, throws_if_pop_when_size_equal_to_zero)
{
    Queue<int> a(0);

    ASSERT_ANY_THROW(a.pop());
}
TEST(Queue, can_correctly_pop_from_the_end_of_the_buffer)
{
    Queue<int> a(1);
    a.push(2);
    a.push(3);
    a.pop();
    a.push(4);
    a.pop();

    EXPECT_EQ(a.get_first(), 4);
}
TEST(Queue, can_resize_when_capacity_is_full)
{
    Queue<int> a(1);
    a.push(1);
    a.push(2);
    a.push(3);

    EXPECT_EQ(a.get_capacity(), 4);
}
TEST(Queue, return_true_if_queue_is_empty)
{
    Queue<int> a(3);

    EXPECT_TRUE(a.empty());
}
TEST(Queue, return_true_if_queue_is_full)
{
    Queue<int> a(1);
    
    a.push(2);
    a.push(3);

    EXPECT_TRUE(a.full());
}
TEST(Queue, comparison_operator_work_correctly)
{
    Queue<int> a(1);
    Queue<int> b(1);

    a = b;

    EXPECT_TRUE(a == b);
}
TEST(Queue, can_clear_queue)
{
    Queue<int> a(3);

    a.push(1);
    a.push(2);
    a.push(3);
    a.clear();

    EXPECT_TRUE(a.empty());
}
TEST(Queue, return_size)
{
    Queue<int> a(2);

    a.push(1);
    a.push(2);

    EXPECT_EQ(a.size(), 2);
}
