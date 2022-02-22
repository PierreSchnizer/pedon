#define BOOST_TEST_MODULE combination
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <thor_scsi/core/drift.h>
#include <thor_scsi/core/machine.h>
#include <string>
#include <ostream>

namespace tse = thor_scsi::elements;
namespace tsc = thor_scsi::core;


BOOST_AUTO_TEST_CASE(test01_register_drift)
{
  tsc::Machine::registerElement<tse::DriftType>("drift");
}

static const std::string drift_txt(
  "a_drift : drift, L=0.1;\n"
  "mini_cell : LINE = (a_drift);\n");

BOOST_AUTO_TEST_CASE(test02_initalise_drift)
{

  // be aware must be already registered ...
  // tsc::Machine::registerElement<tse::DriftType>("drift");

  GLPSParser parse;
  /*
  std::cout << "Testing drift: " <<std::endl
	    << "---------------------" << std::endl
	    << drift_txt
	    << "---------------------" << std::endl;
  */
  Config *C = parse.parse_byte(drift_txt);

  auto machine = tsc::Machine(*C);
  /*
  std::cout << "Machine " << std::endl
	    << "---------------------" << std::endl
	    << machine
	    << "---------------------" << std::endl;
  */

  // proper checks required here
  auto cell = machine.find("a_drift");
  BOOST_TEST(cell != nullptr);

  auto drift = dynamic_cast<tse::DriftType*>(cell);
  BOOST_TEST(drift !=  nullptr);

  const double length_check = drift->getLength();
  // std::cout << "Drift length: " <<  length_check << std::endl;

  BOOST_CHECK_CLOSE(length_check, 0.1, 1e-6);

  // std::cout << drift->name << std::endl;
  BOOST_CHECK_EQUAL(drift->name, "a_drift");

}

BOOST_AUTO_TEST_CASE(test03_locate_wrong_drift)
{
  GLPSParser parse;
  Config *C = parse.parse_byte(drift_txt);

  auto machine = tsc::Machine(*C);
  auto cell = machine.find("undefined_drift");
  BOOST_CHECK_EQUAL(cell, nullptr);
}

static const std::string drift_elem_dbl_txt(
  "a_drift : drift, L=0.1;\n"
  "mini_cell : LINE = (a_drift, a_drift);\n");
/**
 *  Should this fail? two times the same drift ...
 *
 *  Or an acceptable flaw
 */
BOOST_AUTO_TEST_CASE(test04_double_drift)
{
  GLPSParser parse;
  Config *C = parse.parse_byte(drift_elem_dbl_txt);

  auto machine = tsc::Machine(*C);
  std::cout << "Machine" << std::endl
	    << machine
	    << std::endl;
  auto cell = machine.find("a_drift");
  std::cout << "cell " << cell->name <<std::endl;
}
