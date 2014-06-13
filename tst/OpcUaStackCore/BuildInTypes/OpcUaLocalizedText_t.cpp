#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaLocalizedText_)

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_)
{
	std::cout << "OpcUaLocalizedText_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_locale_no_text_no)
{
	std::stringstream ss;
	OpcUaLocalizedText value1, value2;
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.locale().exist() == false);
	BOOST_REQUIRE(value2.text().exist() == false);
}

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_locale_yes_text_no)
{
	std::stringstream ss;
	OpcUaLocalizedText value1, value2;
	
	value1.locale("locale");
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.locale().exist() == true);
	BOOST_REQUIRE(value2.text().exist() == false);
	BOOST_REQUIRE(value2.locale().value() == "locale");
}

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_locale_no_text_yes)
{
	std::stringstream ss;
	OpcUaLocalizedText value1, value2;
	
	value1.text("text");
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.locale().exist() == false);
	BOOST_REQUIRE(value2.text().exist() == true);
	BOOST_REQUIRE(value2.text().value() == "text");
}

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_locale_yes_text_yes)
{
	std::stringstream ss;
	OpcUaLocalizedText value1, value2;
	
	value1.locale("locale");
	value1.text("text");
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.locale().exist() == true);
	BOOST_REQUIRE(value2.text().exist() == true);
	BOOST_REQUIRE(value2.locale().value() == "locale");
	BOOST_REQUIRE(value2.text().value() == "text");
}

BOOST_AUTO_TEST_SUITE_END()