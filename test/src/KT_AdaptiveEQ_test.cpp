#include "KT_AdaptiveEQ_test.h"

int KT_AdaptiveEQTest::test_main() {

    KT_ERROR ret = KT_ERROR::NO_ERROR;
    std::cerr << "Initiating KT Init Test " << std::endl;
    ret = KT_AdaptiveEQ_test.KT_AdaptiveEQ_init();
    // You can handle any error cases if needed
    // For example, print an error message if ret is not NO_ERROR
    if (ret != KT_ERROR::NO_ERROR) {
        // Handle the error accordingly, e.g., print an error message
        std::cerr << "Error occurred at Delay test Init: " << static_cast<int>(ret) << std::endl;   // Demonstrates how to print return
        goto end;
    }

    std::cerr << std::endl << "Initiating KT Set Test " << std::endl;
    //et = KT_AdaptiveEQ_test.KT_AdaptiveEQ_set();
    if (ret != KT_ERROR::NO_ERROR) {
        // Handle the error accordingly, e.g., print an error message
        std::cerr << "Error occurred at Delay test Set: " << static_cast<int>(ret) << std::endl;
        goto end;
    }

    std::cerr << std::endl << "Initiating KT Get Test " << std::endl;
    ret = KT_AdaptiveEQ_test.KT_AdaptiveEQ_get();
    if (ret != KT_ERROR::NO_ERROR) {
        // Handle the error accordingly, e.g., print an error message
        std::cerr << "Error occurred at Delay test Set: " << static_cast<int>(ret) << std::endl;
        goto end;
    }

    std::cerr << std::endl << "Initiating KT Process Test " << std::endl;
    ret = KT_AdaptiveEQ_test.KT_AdaptiveEQ_process();
    if (ret != KT_ERROR::NO_ERROR) {
        // Handle the error accordingly, e.g., print an error message
        std::cerr << "Error occurred at Delay test Process: " << static_cast<int>(ret) << std::endl;
        goto end;
    }

end:
    return static_cast<int>(ret); // Return the error code as an int
}

int main() {
    KT_AdaptiveEQTest KT_AdaptiveEQTest;
    int ret = KT_AdaptiveEQTest.test_main();
    return ret;  // Call the class method main()
}



/*
    To Do:
            - Work out how to pass arguments to test script.
            - qdd qrgument to test shell script, each number specifies a test case, or no number indicates all test cases.
*/