#define BOOST_TEST_MODULE config
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <flame/core/config.h>

BOOST_AUTO_TEST_CASE(config_getset)
{
    Config C;

    C.set<double>("hello", 42);

    BOOST_CHECK_CLOSE(C.get<double>("hello"), 42, 1e-7);

}
