PROJ_NAME = LMS

TEST_PROJ_NAME = Test_$(PROJ_NAME)

BUILD_DIR = ./Build

ifdef OS
	RM = del /q
	FixPath = $(subst /,\,$1)
	EXEC = exe
else
   ifeq ($(shell uname), Linux)
			RM = rm -rf
			FixPath = $1
			EXEC = out
   endif
endif 

# Makefile will not run target command if the name with file already exists. To override, use .PHONY
.PHONY : all test coverage run clean doc

SRC = src/lms.cpp\

INC =  -Iinc\
-Iunity


TEST_SRC = test/LMS_Test.c\
unity/unity.c 


all:$(BUILD_DIR)
	gcc main.c $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))


run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

coverage:${PROJECT_NAME}
	gcc -fprofile-arcs -ftest-coverage main.c $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	gcov -a main.c $(SRC) $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	$(RM) *.gcno
	$(RM) *.gcov
	$(RM) *.gcda

test:$(BUILD_DIR)
	gcc $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

	
valgrind:
	valgrind $(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC)
	
cppcheck:
	cppcheck --enable=all $(CPPCHECK_INC) *.c

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	$(RM) *.$(EXEC)
	$(RM) *.gcno
	$(RM) *.gcov
	$(RM) *.gcda
	$(RM) *.bin
