#define BOOST_TEST_MODULE combination
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

//#include <flame/core/base.h>
#include <thor_scsi/core/drift.h>
#include <thor_scsi/core/machine.h>

namespace tse = thor_scsi::elements;
namespace tsc = thor_scsi::core;

BOOST_AUTO_TEST_CASE(combine_drift)
{
  tsc::Machine::registerElement<tse::DriftType>("drift");

}
