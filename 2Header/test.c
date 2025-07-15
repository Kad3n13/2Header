#include <stdio.h>
#include "2h.h"

// Helper macros for test results
#define TEST_PASS 1
#define TEST_FAIL 0

// Test a signed char variable against min and max limits
int test_signed_char_limits(void) {
    char min_val = SC_M;
    char max_val = SC_MX;

    if (min_val != -128) {
        printf("[FAIL] Signed char min expected -128, got %d\n", min_val);
        return TEST_FAIL;
    }
    if (max_val != 127) {
        printf("[FAIL] Signed char max expected 127, got %d\n", max_val);
        return TEST_FAIL;
    }

    // Test overflow (signed overflow is undefined, so just test boundary)
    char just_above_max = max_val;
    just_above_max++;
    // just_above_max may wrap, so we only print it to inspect
    printf("[INFO] Signed char max + 1 = %d (may overflow undefined behavior)\n", just_above_max);

    return TEST_PASS;
}

// Test unsigned char max value
int test_unsigned_char_limit(void) {
    unsigned char max_val = US_CX;
    if (max_val != 255) {
        printf("[FAIL] Unsigned char max expected 255, got %u\n", max_val);
        return TEST_FAIL;
    }

    unsigned char overflow_val = max_val + 1;
    if (overflow_val != 0) {
        printf("[FAIL] Unsigned char overflow expected 0, got %u\n", overflow_val);
        return TEST_FAIL;
    }
    return TEST_PASS;
}

// Test char min and max (signed or unsigned depending on platform)
int test_char_limits(void) {
    char min_val = C_M;
    char max_val = C_MX;

    printf("[INFO] char min: %d, max: %d\n", min_val, max_val);

    // These limits depend on signedness; we accept only these two possibilities
    if (!((min_val == SC_M && max_val == SC_MX) || (min_val == 0 && max_val == US_CX))) {
        printf("[FAIL] char limits inconsistent with signedness\n");
        return TEST_FAIL;
    }
    return TEST_PASS;
}

// Test MB_LEN_MAX
int test_mb_len_max(void) {
    if (MB_LM < 1 || MB_LM > 32) {
        printf("[FAIL] MB_LEN_MAX out of reasonable range (1-32): %d\n", MB_LM);
        return TEST_FAIL;
    }
    return TEST_PASS;
}

// Test short limits and overflow wraparound for unsigned short
int test_short_limits(void) {
    short min_val = SH_M;
    short max_val = SH_MX;
    unsigned short umax_val = USH_MX;

    if (min_val != -32768) {
        printf("[FAIL] short min expected -32768, got %d\n", min_val);
        return TEST_FAIL;
    }
    if (max_val != 32767) {
        printf("[FAIL] short max expected 32767, got %d\n", max_val);
        return TEST_FAIL;
    }
    if (umax_val != 65535) {
        printf("[FAIL] unsigned short max expected 65535, got %u\n", umax_val);
        return TEST_FAIL;
    }

    unsigned short overflow_val = umax_val + 1;
    if (overflow_val != 0) {
        printf("[FAIL] unsigned short overflow expected 0, got %u\n", overflow_val);
        return TEST_FAIL;
    }
    return TEST_PASS;
}

// Test int limits and unsigned overflow
int test_int_limits(void) {
    int min_val = I_M;
    int max_val = I_MX;
    unsigned int umax_val = UI_MX;

    if (min_val != -2147483648) {
        printf("[FAIL] int min expected -2147483648, got %d\n", min_val);
        return TEST_FAIL;
    }
    if (max_val != 2147483647) {
        printf("[FAIL] int max expected 2147483647, got %d\n", max_val);
        return TEST_FAIL;
    }
    if (umax_val != 4294967295U) {
        printf("[FAIL] unsigned int max expected 4294967295, got %u\n", umax_val);
        return TEST_FAIL;
    }

    unsigned int overflow_val = umax_val + 1;
    if (overflow_val != 0) {
        printf("[FAIL] unsigned int overflow expected 0, got %u\n", overflow_val);
        return TEST_FAIL;
    }
    return TEST_PASS;
}

// Test long limits and unsigned long overflow
int test_long_limits(void) {
    long min_val = L_M;
    long max_val = L_MX;
    unsigned long umax_val = UL_MX;

    if (min_val != (-9223372036854775807L - 1)) {
        printf("[FAIL] long min expected %ld, got %ld\n", (-9223372036854775807L - 1), min_val);
        return TEST_FAIL;
    }
    if (max_val != 9223372036854775807L) {
        printf("[FAIL] long max expected %ld, got %ld\n", 9223372036854775807L, max_val);
        return TEST_FAIL;
    }
    if (umax_val != 18446744073709551615UL) {
        printf("[FAIL] unsigned long max expected %lu, got %lu\n", 18446744073709551615UL, umax_val);
        return TEST_FAIL;
    }

    unsigned long overflow_val = umax_val + 1;
    if (overflow_val != 0) {
        printf("[FAIL] unsigned long overflow expected 0, got %lu\n", overflow_val);
        return TEST_FAIL;
    }
    return TEST_PASS;
}

int main(void) {
    init_char_limits();

    int total = 0, passed = 0;

    #define RUN_TEST(test) do { \
        total++; \
        printf("Running %s...\n", #test); \
        if(test()) { \
            printf("[PASS] %s\n\n", #test); \
            passed++; \
        } else { \
            printf("[FAIL] %s\n\n", #test); \
        } \
    } while(0)

    RUN_TEST(test_signed_char_limits);
    RUN_TEST(test_unsigned_char_limit);
    RUN_TEST(test_char_limits);
    RUN_TEST(test_mb_len_max);
    RUN_TEST(test_short_limits);
    RUN_TEST(test_int_limits);
    RUN_TEST(test_long_limits);

    printf("Tests passed: %d/%d\n", passed, total);
    return (passed == total) ? 0 : 1;
}

