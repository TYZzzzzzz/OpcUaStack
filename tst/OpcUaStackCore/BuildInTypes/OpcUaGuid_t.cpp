#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaGuid.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaGuid_)

BOOST_AUTO_TEST_CASE(OpcUaGuid_)
{
	std::cout << "OpcUaGuid_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaGuid_null)
{
	std::stringstream ss;
	OpcUaGuid value1, value2;

	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	std::string str = value2;
	BOOST_REQUIRE(str == "00000000-0000-0000-0000-000000000000");
}

BOOST_AUTO_TEST_CASE(OpcUaGuid_string)
{
	std::string str;
	std::stringstream ss;
	OpcUaGuid value1, value2;

	value1 = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	str = value2;
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");

	value1 = "12345678-9abc-def0-1234-56789abcdef0";
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	str = value2;
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
}

BOOST_AUTO_TEST_CASE(OpcUaGuid_binary)
{
	std::string str;
	std::stringstream ss;
	OpcUaGuid value1, value2;
	OpcUaByte data4[8] = { 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0 };

	value1.data1(0x12345678); 
	value1.data2(0x9ABC);
	value1.data3(0xDEF0);
	value1.data4(data4);
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	str = value2;
	// FIXME:
	//BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
}

BOOST_AUTO_TEST_SUITE_END()