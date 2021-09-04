#include "unity.h"
#include "lms.h"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

Lib lms_t, lms_t1;

void test_getdata(void) 
{
  Lib new_lms = {"book_name", "author_name", "0000", "500", "30"};
  TEST_ASSERT_EQUAL(0, getdata(&new_lms));
}

void test_modify(void) 
{
  Lib new_lms = {"book_name", "author_name", "0000", "500", "30"};
  Lib new_lms_1 = {"book_name", "author_name", "1111", "500", "30"};
  TEST_ASSERT_EQUAL(0, getdata(&new_lms));
  TEST_ASSERT_EQUAL(0, modify(new_lms.bookname, &new_lms1));
}

void test_display(void)
{
  TEST_ASSERT_EQUAL(1,booklist(1)>0);
}

int main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_getdata);
  RUN_TEST(test_modify);
  RUN_TEST(test_display);

  /* Close the Unity Test Framework */
  return UNITY_END();
}
