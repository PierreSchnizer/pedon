#define BOOST_TEST_MODULE combination
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <flame/core/base.h>
#include <thor_scsi/core/drift.h>

namespace tse = thor_scsi::elements;

BOOST_AUTO_TEST_CASE(combine_drift)
{
	Machine::registerElement<tse::DriftType>("MomentMatrix", "drift");

}
