#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/wait.h>

#define TEST_PASS 0
#define TEST_FAIL 1

static int tests_run = 0;
static int tests_passed = 0;
static int tests_failed = 0;

void test_fibonacci_with_zero_terms(void) {
    printf("Running: test_fibonacci_with_zero_terms\n");

    int pipefd_in[2];
    int pipefd_out[2];

    if (pipe(pipefd_in) == -1 || pipe(pipefd_out) == -1) {
        perror("pipe");
        tests_failed++;
        return;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        tests_failed++;
        return;
    }

    if (pid == 0) {
        close(pipefd_in[1]);
        close(pipefd_out[0]);

        dup2(pipefd_in[0], STDIN_FILENO);
        dup2(pipefd_out[1], STDOUT_FILENO);

        close(pipefd_in[0]);
        close(pipefd_out[1]);

        execlp("./main", "main", (char *)NULL);
        perror("execlp");
        exit(1);
    } else {
        close(pipefd_in[0]);
        close(pipefd_out[1]);

        const char *input = "0\n";
        write(pipefd_in[1], input, strlen(input));
        close(pipefd_in[1]);

        char buffer[1024] = {0};
        read(pipefd_out[0], buffer, sizeof(buffer) - 1);
        close(pipefd_out[0]);

        wait(NULL);

        if (strstr(buffer, "Enter number of terms:") != NULL &&
            strstr(buffer, "Fibonacci Series:") != NULL) {
            tests_passed++;
            printf("  PASS\n");
        } else {
            tests_failed++;
            printf("  FAIL\n");
        }
    }

    tests_run++;
}

void test_fibonacci_with_one_term(void) {
    printf("Running: test_fibonacci_with_one_term\n");

    int pipefd_in[2];
    int pipefd_out[2];

    if (pipe(pipefd_in) == -1 || pipe(pipefd_out) == -1) {
        perror("pipe");
        tests_failed++;
        return;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        tests_failed++;
        return;
    }

    if (pid == 0) {
        close(pipefd_in[1]);
        close(pipefd_out[0]);

        dup2(pipefd_in[0], STDIN_FILENO);
        dup2(pipefd_out[1], STDOUT_FILENO);

        close(pipefd_in[0]);
        close(pipefd_out[1]);

        execlp("./main", "main", (char *)NULL);
        perror("execlp");
        exit(1);
    } else {
        close(pipefd_in[0]);
        close(pipefd_out[1]);

        const char *input = "1\n";
        write(pipefd_in[1], input, strlen(input));
        close(pipefd_in[1]);

        char buffer[1024] = {0};
        read(pipefd_out[0], buffer, sizeof(buffer) - 1);
        close(pipefd_out[0]);

        wait(NULL);

        if (strstr(buffer, "0 ") != NULL) {
            tests_passed++;
            printf("  PASS\n");
        } else {
            tests_failed++;
            printf("  FAIL\n");
        }
    }

    tests_run++;
}

void test_fibonacci_with_two_terms(void) {
    printf("Running: test_fibonacci_with_two_terms\n");

    int pipefd_in[2];
    int pipefd_out[2];

    if (pipe(pipefd_in) == -1 || pipe(pipefd_out) == -1) {
        perror("pipe");
        tests_failed++;
        return;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        tests_failed++;
        return;
    }

    if (pid == 0) {
        close(pipefd_in[1]);
        close(pipefd_out[0]);

        dup2(pipefd_in[0], STDIN_FILENO);
        dup2(pipefd_out[1], STDOUT_FILENO);

        close(pipefd_in[0]);
        close(pipefd_out[1]);

        execlp("./main", "main", (char *)NULL);
        perror("execlp");
        exit(1);
    } else {
        close(pipefd_in[0]);
        close(pipefd_out[1]);

        const char *input = "2\n";
        write(pipefd_in[1], input, strlen(input));
        close(pipefd_in[1]);

        char buffer[1024] = {0};
        read(pipefd_out[0], buffer, sizeof(buffer) - 1);
        close(pipefd_out[0]);

        wait(NULL);

        if (strstr(buffer, "0 ") != NULL && strstr(buffer, "1 ") != NULL) {
            tests_passed++;
            printf("  PASS\n");
        } else {
            tests_failed++;
            printf("  FAIL\n");
        }
    }

    tests_run++;
}

void test_fibonacci_with_five_terms(void) {
    printf("Running: test_fibonacci_with_five_terms\n");

    int pipefd_in[2];
    int pipefd_out[2];

    if (pipe(pipefd_in) == -1 || pipe(pipefd_out) == -1) {
        perror("pipe");
        tests_failed++;
        return;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        tests_failed++;
        return;
    }

    if (pid == 0) {
        close(pipefd_in[1]);
        close(pipefd_out[0]);

        dup2(pipefd_in[0], STDIN_FILENO);
        dup2(pipefd_out[1], STDOUT_FILENO);

        close(pipefd_in[0]);
        close(pipefd_out[1]);

        execlp("./main", "main", (char *)NULL);
        perror("execlp");
        exit(1);
    } else {
        close(pipefd_in[0]);
        close(pipefd_out[1]);

        const char *input = "5\n";
        write(pipefd_in[1], input, strlen(input));
        close(pipefd_in[1]);

        char buffer[1024] = {0};
        read(pipefd_out[0], buffer, sizeof(buffer) - 1);
        close(pipefd_out[0]);

        wait(NULL);

        if (strstr(buffer, "0 ") != NULL &&
            strstr(buffer, "1 ") != NULL &&
            strstr(buffer, "2 ") != NULL &&
            strstr(buffer, "3 ") != NULL) {
            tests_passed++;
            printf("  PASS\n");
        } else {
            tests_failed++;
            printf("  FAIL\n");
        }
    }

    tests_run++;
}

int main(void) {
    printf("=== Running Fibonacci Series Tests ===\n\n");

    test_fibonacci_with_zero_terms();
    test_fibonacci_with_one_term();
    test_fibonacci_with_two_terms();
    test_fibonacci_with_five_terms();

    printf("\n=== Test Summary ===\n");
    printf("Tests run: %d\n", tests_run);
    printf("Tests passed: %d\n", tests_passed);
    printf("Tests failed: %d\n", tests_failed);

    return tests_failed > 0 ? TEST_FAIL : TEST_PASS;
}
