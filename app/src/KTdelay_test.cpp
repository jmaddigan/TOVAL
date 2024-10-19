#include "KTdelay_test.h"

int KTdelayTest::test_main() {

    KT_ERROR ret = KT_ERROR::KT_NO_ERROR;
    ret = KTdelay_test.KT_Delay_init();
    // You can handle any error cases if needed
    // For example, print an error message if ret is not NO_ERROR
    if (ret != KT_ERROR::KT_NO_ERROR) {
        // Handle the error accordingly, e.g., print an error message
        std::cerr << "Error occurred at Delay test Init: " << static_cast<int>(ret) << std::endl;
        goto end;
    }

    ret = KTdelay_test.KT_Delay_set();
    if (ret != KT_ERROR::KT_NO_ERROR) {
        // Handle the error accordingly, e.g., print an error message
        std::cerr << "Error occurred at Delay test Set: " << static_cast<int>(ret) << std::endl;
        goto end;
    }

    ret = KTdelay_test.KT_Delay_get();
    if (ret != KT_ERROR::KT_NO_ERROR) {
        // Handle the error accordingly, e.g., print an error message
        std::cerr << "Error occurred at Delay test Set: " << static_cast<int>(ret) << std::endl;
        goto end;
    }

    ret = KTdelay_test.KT_Delay_process();
    if (ret != KT_ERROR::KT_NO_ERROR) {
        // Handle the error accordingly, e.g., print an error message
        std::cerr << "Error occurred at Delay test Process: " << static_cast<int>(ret) << std::endl;
        goto end;
    }

end:
    return static_cast<int>(ret); // Return the error code as an int
}

int main() {
    KTdelayTest delayTest;
    int ret = delayTest.test_main();
    return ret;  // Call the class method main()
}
