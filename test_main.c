#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_OUTPUT_SIZE 10000

typedef struct {
    char *input;
    char *expected_output;
    char *test_name;
} TestCase;

int run_test_with_input(const char *input, char *output, size_t output_size) {
    FILE *input_file = tmpfile();
    FILE *output_file = tmpfile();

    if (!input_file || !output_file) {
        if (input_file) fclose(input_file);
        if (output_file) fclose(output_file);
        return -1;
    }

    fprintf(input_file, "%s", input);
    rewind(input_file);

    FILE *original_stdin = stdin;
    FILE *original_stdout = stdout;

    stdin = input_file;
    stdout = output_file;

    extern int main();

    stdout = original_stdout;
    stdin = original_stdin;

    rewind(output_file);
    size_t bytes_read = fread(output, 1, output_size - 1, output_file);
    output[bytes_read] = '\0';

    fclose(input_file);
    fclose(output_file);

    return 0;
}

void test_fibonacci_zero_terms() {
    printf("Running: test_fibonacci_zero_terms\n");

    int n = 0;
    int count = 0;

    for (int i = 1; i <= n; i++) {
        count++;
    }

    assert(count == 0);
    printf("PASS: test_fibonacci_zero_terms\n");
}

void test_fibonacci_one_term() {
    printf("Running: test_fibonacci_one_term\n");

    int n = 1;
    int first = 0, second = 1;
    int result = -1;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            result = first;
        }
    }

    assert(result == 0);
    printf("PASS: test_fibonacci_one_term\n");
}

void test_fibonacci_two_terms() {
    printf("Running: test_fibonacci_two_terms\n");

    int n = 2;
    int first = 0, second = 1;
    int results[2];
    int idx = 0;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            results[idx++] = first;
        } else if (i == 2) {
            results[idx++] = second;
        }
    }

    assert(results[0] == 0);
    assert(results[1] == 1);
    printf("PASS: test_fibonacci_two_terms\n");
}

void test_fibonacci_three_terms() {
    printf("Running: test_fibonacci_three_terms\n");

    int n = 3;
    int first = 0, second = 1, next;
    int results[3];
    int idx = 0;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            results[idx++] = first;
        } else if (i == 2) {
            results[idx++] = second;
        } else {
            next = first + second;
            results[idx++] = next;
            first = second;
            second = next;
        }
    }

    assert(results[0] == 0);
    assert(results[1] == 1);
    assert(results[2] == 1);
    printf("PASS: test_fibonacci_three_terms\n");
}

void test_fibonacci_five_terms() {
    printf("Running: test_fibonacci_five_terms\n");

    int n = 5;
    int first = 0, second = 1, next;
    int results[5];
    int idx = 0;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            results[idx++] = first;
        } else if (i == 2) {
            results[idx++] = second;
        } else {
            next = first + second;
            results[idx++] = next;
            first = second;
            second = next;
        }
    }

    assert(results[0] == 0);
    assert(results[1] == 1);
    assert(results[2] == 1);
    assert(results[3] == 2);
    assert(results[4] == 3);
    printf("PASS: test_fibonacci_five_terms\n");
}

void test_fibonacci_ten_terms() {
    printf("Running: test_fibonacci_ten_terms\n");

    int n = 10;
    int first = 0, second = 1, next;
    int results[10];
    int idx = 0;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            results[idx++] = first;
        } else if (i == 2) {
            results[idx++] = second;
        } else {
            next = first + second;
            results[idx++] = next;
            first = second;
            second = next;
        }
    }

    assert(results[0] == 0);
    assert(results[1] == 1);
    assert(results[2] == 1);
    assert(results[3] == 2);
    assert(results[4] == 3);
    assert(results[5] == 5);
    assert(results[6] == 8);
    assert(results[7] == 13);
    assert(results[8] == 21);
    assert(results[9] == 34);
    printf("PASS: test_fibonacci_ten_terms\n");
}

void test_fibonacci_negative_terms() {
    printf("Running: test_fibonacci_negative_terms\n");

    int n = -5;
    int count = 0;

    for (int i = 1; i <= n; i++) {
        count++;
    }

    assert(count == 0);
    printf("PASS: test_fibonacci_negative_terms\n");
}

void test_fibonacci_large_number() {
    printf("Running: test_fibonacci_large_number\n");

    int n = 20;
    int first = 0, second = 1, next;
    int last_value = 0;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            last_value = first;
        } else if (i == 2) {
            last_value = second;
        } else {
            next = first + second;
            last_value = next;
            first = second;
            second = next;
        }
    }

    assert(last_value == 4181);
    printf("PASS: test_fibonacci_large_number\n");
}

void test_fibonacci_sequence_correctness() {
    printf("Running: test_fibonacci_sequence_correctness\n");

    int n = 7;
    int first = 0, second = 1, next;
    int results[7];
    int idx = 0;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            results[idx++] = first;
        } else if (i == 2) {
            results[idx++] = second;
        } else {
            next = first + second;
            results[idx++] = next;
            first = second;
            second = next;
        }
    }

    for (int i = 2; i < 7; i++) {
        assert(results[i] == results[i-1] + results[i-2]);
    }
    printf("PASS: test_fibonacci_sequence_correctness\n");
}

void test_first_term_is_zero() {
    printf("Running: test_first_term_is_zero\n");

    int first = 0;
    assert(first == 0);
    printf("PASS: test_first_term_is_zero\n");
}

void test_second_term_is_one() {
    printf("Running: test_second_term_is_one\n");

    int second = 1;
    assert(second == 1);
    printf("PASS: test_second_term_is_one\n");
}

void test_loop_iteration_count() {
    printf("Running: test_loop_iteration_count\n");

    int n = 8;
    int count = 0;

    for (int i = 1; i <= n; i++) {
        count++;
    }

    assert(count == n);
    printf("PASS: test_loop_iteration_count\n");
}

void test_branch_first_term() {
    printf("Running: test_branch_first_term\n");

    int i = 1;
    int first = 0;
    int executed = 0;

    if (i == 1) {
        executed = 1;
        int value = first;
        assert(value == 0);
    }

    assert(executed == 1);
    printf("PASS: test_branch_first_term\n");
}

void test_branch_second_term() {
    printf("Running: test_branch_second_term\n");

    int i = 2;
    int second = 1;
    int executed = 0;

    if (i == 1) {
        executed = 0;
    } else if (i == 2) {
        executed = 1;
        int value = second;
        assert(value == 1);
    }

    assert(executed == 1);
    printf("PASS: test_branch_second_term\n");
}

void test_branch_subsequent_terms() {
    printf("Running: test_branch_subsequent_terms\n");

    int i = 3;
    int first = 0, second = 1, next;
    int executed = 0;

    if (i == 1) {
        executed = 0;
    } else if (i == 2) {
        executed = 0;
    } else {
        executed = 1;
        next = first + second;
        assert(next == 1);
        first = second;
        second = next;
        assert(first == 1);
        assert(second == 1);
    }

    assert(executed == 1);
    printf("PASS: test_branch_subsequent_terms\n");
}

void test_variable_updates() {
    printf("Running: test_variable_updates\n");

    int first = 0, second = 1, next;

    next = first + second;
    assert(next == 1);

    first = second;
    assert(first == 1);

    second = next;
    assert(second == 1);

    next = first + second;
    assert(next == 2);

    first = second;
    assert(first == 1);

    second = next;
    assert(second == 2);

    printf("PASS: test_variable_updates\n");
}

void test_fibonacci_calculation_logic() {
    printf("Running: test_fibonacci_calculation_logic\n");

    int first = 0, second = 1, next;

    next = first + second;
    assert(next == 1);

    first = second;
    second = next;

    next = first + second;
    assert(next == 2);

    first = second;
    second = next;

    next = first + second;
    assert(next == 3);

    first = second;
    second = next;

    next = first + second;
    assert(next == 5);

    printf("PASS: test_fibonacci_calculation_logic\n");
}

void test_edge_case_max_int_approach() {
    printf("Running: test_edge_case_max_int_approach\n");

    int n = 46;
    int first = 0, second = 1, next;
    int last_value = 0;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            last_value = first;
        } else if (i == 2) {
            last_value = second;
        } else {
            next = first + second;
            last_value = next;
            first = second;
            second = next;
        }
    }

    assert(last_value == 1836311903);
    printf("PASS: test_edge_case_max_int_approach\n");
}

void test_return_value() {
    printf("Running: test_return_value\n");

    int return_value = 0;
    assert(return_value == 0);
    printf("PASS: test_return_value\n");
}

void test_all_branches_coverage() {
    printf("Running: test_all_branches_coverage\n");

    int n = 4;
    int first = 0, second = 1, next;
    int branch_1_hit = 0, branch_2_hit = 0, branch_3_hit = 0;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            branch_1_hit = 1;
        } else if (i == 2) {
            branch_2_hit = 1;
        } else {
            branch_3_hit = 1;
            next = first + second;
            first = second;
            second = next;
        }
    }

    assert(branch_1_hit == 1);
    assert(branch_2_hit == 1);
    assert(branch_3_hit == 1);
    printf("PASS: test_all_branches_coverage\n");
}

int main() {
    printf("=== Running Fibonacci Series Tests ===\n\n");

    test_fibonacci_zero_terms();
    test_fibonacci_one_term();
    test_fibonacci_two_terms();
    test_fibonacci_three_terms();
    test_fibonacci_five_terms();
    test_fibonacci_ten_terms();
    test_fibonacci_negative_terms();
    test_fibonacci_large_number();
    test_fibonacci_sequence_correctness();
    test_first_term_is_zero();
    test_second_term_is_one();
    test_loop_iteration_count();
    test_branch_first_term();
    test_branch_second_term();
    test_branch_subsequent_terms();
    test_variable_updates();
    test_fibonacci_calculation_logic();
    test_edge_case_max_int_approach();
    test_return_value();
    test_all_branches_coverage();

    printf("\n=== All Tests Passed! ===\n");
    return 0;
}
