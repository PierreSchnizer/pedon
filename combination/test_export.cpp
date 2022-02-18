#define BOOST_TEST_MODULE config
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <flame/core/config.h>
#include <ostream>


/**
 * If this test segfaults: check if this code has been compiled with
 * "-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC)" which flame is typically
 * not compiled with as it depends on boost
 *
 * Debugging could show that C.set works on rather strange strings ...
 */
BOOST_AUTO_TEST_CASE(config_getset)
{
    Config C;

    C.set<double>("hello", 42);
    // std::cout << "C =" << C << std::endl;

    BOOST_CHECK_CLOSE(C.get<double>("hello"), 42, 1e-7);

}
