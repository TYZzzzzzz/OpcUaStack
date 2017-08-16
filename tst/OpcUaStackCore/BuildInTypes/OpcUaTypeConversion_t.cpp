#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaTypeConversion_)

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_)
{
	std::cout << "OpcUaTypeConversion_t" << std::endl;
}

//
// I => implicit
// E => explicit
//

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// Boolean
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Boolean_Byte_I)
{
	OpcUaBoolean value1;
	OpcUaByte value2;

	value1 = false;
	value2 = value1;
	BOOST_REQUIRE(value2 == 0);

	value1 = true;
	value2 = value1;
	BOOST_REQUIRE(value2 == 1);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// Byte
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Byte_Boolean_E)
{
	OpcUaByte value1;
	OpcUaBoolean value2;

	value1 = 0;
	value2 = value1;
	BOOST_REQUIRE(value2 == false);

	value1 = 1;
	value2 = value1;
	BOOST_REQUIRE(value2 == true);
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Bool)
{
	OpcUaTypeConversion converter;
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();
	value1->set<OpcUaBoolean>(true);

	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();

	BOOST_REQUIRE_EQUAL(11, converter.precedenceRank(OpcUaBuildInType_OpcUaBoolean));
	// bool -> bool
	BOOST_REQUIRE_EQUAL('-', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaBoolean));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaBoolean, value2));
	BOOST_REQUIRE(value2->get<OpcUaBoolean>());

	// bool -> byte
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaByte));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaByte, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaByte>());

	// bool -> byteString
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaByteString));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaByteString, value2));

	// bool -> dateTime
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaDateTime));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaDateTime, value2));

	// bool -> double
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaDouble));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaDouble, value2));
	BOOST_REQUIRE_EQUAL(1.0, value2->get<OpcUaDouble>());

	// bool -> expandedNode
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaExpandedNodeId));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaExpandedNodeId, value2));

	// bool -> float
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaFloat));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaFloat, value2));
	BOOST_REQUIRE_EQUAL(1.0f, value2->get<OpcUaFloat>());

	// bool -> guid
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaGuid));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaGuid, value2));

	// bool -> int16
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaInt16));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt16, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaInt16>());

	// bool -> int32
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaInt32));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt32, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaInt32>());

	// bool -> int64
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaInt64));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt64, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaInt64>());

	// bool -> nodeId
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaNodeId));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaNodeId, value2));

	// bool -> sbyte
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaSByte));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaSByte>());

	// bool -> statusCode
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaStatusCode));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaStatusCode, value2));

	// bool -> string
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaString));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaString, value2));
	BOOST_REQUIRE_EQUAL(OpcUaString("1"), *value2->getSPtr<OpcUaString>());

	// bool -> localizedText
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaLocalizedText));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaLocalizedText, value2));

	// bool -> qualifiedName
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaQualifiedName));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaQualifiedName, value2));

	// bool -> uint16
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaUInt16));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt16, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaUInt16>());

	// bool -> uint32
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaUInt32));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt32, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaUInt32>());

	// bool -> int64
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaUInt64));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt64, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaUInt64>());

	// bool -> xmlElement
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaXmlElement));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaXmlElement, value2));
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Byte)
{
	OpcUaTypeConversion converter;
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();
	value1->set<OpcUaByte>(128);

	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();

	BOOST_REQUIRE_EQUAL(10, converter.precedenceRank(OpcUaBuildInType_OpcUaByte));

	// byte -> bool
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaBoolean));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaBoolean, value2));
	BOOST_REQUIRE_EQUAL(true, value2->get<OpcUaBoolean>());

	// byte -> byte
	BOOST_REQUIRE_EQUAL('-', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaByte));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaByte, value2));
	BOOST_REQUIRE_EQUAL(128, value2->get<OpcUaByte>());

	// byte -> byteString
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaByteString));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaByteString, value2));

	// byte -> dateTime
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaDateTime));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaDateTime, value2));

	// byte -> double
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaDouble));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaDouble, value2));
	BOOST_REQUIRE_EQUAL(128.0f, value2->get<OpcUaDouble>());

	// byte -> expandedNode
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaExpandedNodeId));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaExpandedNodeId, value2));

	// byte -> float
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaFloat));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaFloat, value2));
	BOOST_REQUIRE_EQUAL(128.0f, value2->get<OpcUaFloat>());

	// byte -> guid
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaGuid));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaGuid, value2));

	// byte -> int16
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaInt16));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt16, value2));
	BOOST_REQUIRE_EQUAL(128, value2->get<OpcUaInt16>());

	// byte -> int32
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaInt32));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt32, value2));
	BOOST_REQUIRE_EQUAL(128, value2->get<OpcUaInt32>());

	// byte -> int64
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaInt64));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt64, value2));
	BOOST_REQUIRE_EQUAL(128, value2->get<OpcUaInt64>());

	// byte -> nodeId
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaNodeId));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaNodeId, value2));

	// byte -> sbyte
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaSByte));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));
	BOOST_REQUIRE_EQUAL(-128, (int16_t) value2->get<OpcUaSByte>());

	// byte -> statusCode
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaStatusCode));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaStatusCode, value2));

	// byte -> string
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaString));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaString, value2));
	BOOST_REQUIRE_EQUAL(OpcUaString("128"), *value2->getSPtr<OpcUaString>());

	// byte -> localizedText
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaLocalizedText));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaLocalizedText, value2));

	// byte -> qualifiedName
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaQualifiedName));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaQualifiedName, value2));

	// byte -> int16
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaUInt16));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt16, value2));
	BOOST_REQUIRE_EQUAL(128, value2->get<OpcUaUInt16>());

	// byte -> int32
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaUInt32));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt32, value2));
	BOOST_REQUIRE_EQUAL(128, value2->get<OpcUaUInt32>());

	// byte -> int64
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaUInt64));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt64, value2));
	BOOST_REQUIRE_EQUAL(128, value2->get<OpcUaUInt64>());

	// byte -> xmlElement
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByte, OpcUaBuildInType_OpcUaXmlElement));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaXmlElement, value2));
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_ByteString)
{
	OpcUaTypeConversion converter;
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();
	const std::string guidString = "\x01\x02\x03\x04\x11\x12\x21\x22\x31\x32\x33\x34\x35\x36\x37\x38";

	OpcUaByteString::SPtr byteString = constructSPtr<OpcUaByteString>(guidString);

	value1->variant(byteString);

	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();

	BOOST_REQUIRE_EQUAL(18, converter.precedenceRank(OpcUaBuildInType_OpcUaByteString));

	// byteString -> bool
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaBoolean));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaBoolean, value2));

	// byteString -> byte
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaByte));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaByte, value2));

	// byteString -> byteString
	BOOST_REQUIRE_EQUAL('-', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaByteString));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaByteString, value2));
	BOOST_REQUIRE_EQUAL(guidString, value2->getSPtr<OpcUaByteString>()->toString());

	// byteString -> dateTime
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaDateTime));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaDateTime, value2));

	// byteString -> double
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaDouble));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaDouble, value2));

	// byteString -> expandedNodeId
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaExpandedNodeId));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaExpandedNodeId, value2));

	// byteString -> float
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaFloat));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaFloat, value2));

	// byteString -> Guid
	OpcUaGuid guid;
	guid.value("01020304-1112-2122-3132-333435363738");
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaGuid));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaGuid, value2));
	BOOST_REQUIRE_EQUAL(guid, *value2->getSPtr<OpcUaGuid>());

	// byteString -> int16
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaInt16));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt16, value2));

	// byteString -> int32
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaInt32));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt32, value2));

	// byteString -> int64
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaInt64));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt64, value2));

	// byteString -> nodeId
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaNodeId));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaNodeId, value2));

	// byteString -> sbyte
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaSByte));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));

	// byteString -> sbyte
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaSByte));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));

	// byteString -> statusCode
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaStatusCode));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaStatusCode, value2));

	// byteString -> string
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaString));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaString, value2));

	// byteString -> localizedText
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaLocalizedText));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaLocalizedText, value2));

	// byteString -> qualifiedName
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaQualifiedName));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaQualifiedName, value2));

	// byteString -> uint16
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaUInt16));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt16, value2));

	// byteString -> uint32
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaUInt32));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt32, value2));

	// byteString -> uint64
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaUInt64));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt64, value2));

	// byteString -> xmlElement
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaByteString, OpcUaBuildInType_OpcUaXmlElement));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaXmlElement, value2));

	// byteString -> Guid wrong format
	byteString = constructSPtr<OpcUaByteString>("\x01\x02\x03\x04\x11\x12\x21\x22\x31\x32\x33\x34\x35\x36\x37\x38\x39");
	value1->variant(byteString);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaGuid, value2));

	byteString = constructSPtr<OpcUaByteString>("\x01\x02\x03\x04\x11\x12\x21\x22\x31\x32\x33\x34\x35\x36\x37");
	value1->variant(byteString);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaGuid, value2));
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_DateTime)
{
	OpcUaTypeConversion converter;

	OpcUaDateTime dt;
	dt.fromISOString("20020131T100001.123456");

	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();
	value1->variant(dt);

	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();

	BOOST_REQUIRE_EQUAL(19, converter.precedenceRank(OpcUaBuildInType_OpcUaDateTime));

	// dateTime -> bool
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaBoolean));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaBoolean, value2));

	// dateTime -> byte
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaByte));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaByte, value2));

	// dateTime -> byteString
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaByteString));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaByteString, value2));

	// dateTime -> dateTime
	BOOST_REQUIRE_EQUAL('-', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaDateTime));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaDateTime, value2));
	BOOST_REQUIRE_EQUAL(dt, value2->get<OpcUaDateTime>());

	// dateTime -> double
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaDouble));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaDouble, value2));

	// dateTime -> expandedNodeId
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaExpandedNodeId));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaExpandedNodeId, value2));

	// dateTime -> float
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaFloat));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaFloat, value2));

	// dateTime -> guid
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaGuid));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaGuid, value2));

	// dateTime -> int16
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaInt16));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt16, value2));

	// dateTime -> int32
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaInt32));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt32, value2));

	// dateTime -> int64
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaInt64));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt64, value2));

	// dateTime -> nodeId
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaNodeId));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaNodeId, value2));

	// dateTime -> sbyte
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaSByte));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));

	// dateTime -> sbyte
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaSByte));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));

	// dateTime -> statusCode
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaStatusCode));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaStatusCode, value2));

	// dateTime -> string
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaString));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaString, value2));
	BOOST_REQUIRE_EQUAL("20020131T100001.123456", value2->getSPtr<OpcUaString>()->toStdString());

	// dateTime -> localizedTest
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaLocalizedText));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaLocalizedText, value2));

	// dateTime -> qualifiedName
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaQualifiedName));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaQualifiedName, value2));

	// dateTime -> uint16
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaUInt16));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt16, value2));

	// dateTime -> uint32
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaUInt32));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt32, value2));

	// dateTime -> uint64
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaUInt64));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt64, value2));

	// dateTime -> xmlElement
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDateTime, OpcUaBuildInType_OpcUaXmlElement));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaXmlElement, value2));
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Double)
{
	OpcUaTypeConversion converter;

	OpcUaDouble doubleValue = 24.5;

	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();
	value1->variant(doubleValue);

	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();

	BOOST_REQUIRE_EQUAL(0, converter.precedenceRank(OpcUaBuildInType_OpcUaDouble));

	// double -> bool
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaBoolean));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaBoolean, value2));
	BOOST_REQUIRE_EQUAL(true, value2->get<OpcUaBoolean>());

	// double -> byte
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaByte));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaByte, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaByte>());

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaByte>::max() + 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaByte, value2));

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaByte>::min() - 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaByte, value2));

	// double -> byteString
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaByteString));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaByteString, value2));

	// double -> dateTime
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaDateTime));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaDateTime, value2));

	// double -> double
	value1->variant(doubleValue);
	BOOST_REQUIRE_EQUAL('-', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaDouble));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaDouble, value2));
	BOOST_REQUIRE_EQUAL(doubleValue, value2->get<OpcUaDouble>());

	// double -> expandedNodeId
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaExpandedNodeId));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaExpandedNodeId, value2));

	// double -> float
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaFloat));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaFloat, value2));
	BOOST_REQUIRE_EQUAL(doubleValue, value2->get<OpcUaFloat>());

	// double -> guid
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaGuid));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaGuid, value2));

	// double -> int16
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaInt16));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt16, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaInt16>());

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaInt16>::max() + 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt16, value2));

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaInt16>::min() - 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt16, value2));

	// double -> int32
	value1->variant(doubleValue);
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaInt32));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt32, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaInt32>());

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaInt32>::max() + 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt32, value2));

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaInt32>::min() - 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt32, value2));

	// double -> int64
	value1->variant(doubleValue);
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaInt64));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt64, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaInt64>());

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaInt64>::max() + 10000);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt64, value2));

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaInt64>::min() - 10000);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt64, value2));

	// double -> nodeId
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaNodeId));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaNodeId, value2));

	// double -> sbyte
	value1->variant(doubleValue);
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaSByte));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaSByte>());

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaSByte>::max() + 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaSByte>::min() - 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));

	// double -> statusCode
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaStatusCode));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaStatusCode, value2));

	// double -> string
	value1->variant(doubleValue);
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaString));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaString, value2));
	BOOST_REQUIRE_EQUAL("24.5", value2->getSPtr<OpcUaString>()->toStdString());

	// double -> localizedTest
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaLocalizedText));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaLocalizedText, value2));

	// double -> qualifiedName
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaQualifiedName));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaQualifiedName, value2));

	// double -> int16
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaUInt16));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt16, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaUInt16>());

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaUInt16>::max() + 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt16, value2));

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaUInt16>::min() - 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt16, value2));

	// double -> int32
	value1->variant(doubleValue);
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaUInt32));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt32, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaUInt32>());

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaUInt32>::max() + 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt32, value2));

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaUInt32>::min() - 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt32, value2));

	// double -> int64
	value1->variant(doubleValue);
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaUInt64));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt64, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaUInt64>());

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaUInt64>::max() + 10000);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt64, value2));

	value1->set<OpcUaDouble>((OpcUaDouble)std::numeric_limits<OpcUaUInt64>::min() - 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt64, value2));

	// double -> xmlElement
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaXmlElement));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaXmlElement, value2));
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_OpcUaExpandedNodeId)
{
	OpcUaTypeConversion converter;

	OpcUaExpandedNodeId::SPtr expandedNodeId = constructSPtr<OpcUaExpandedNodeId>();

	expandedNodeId->nodeId<OpcUaUInt32>(1000);
	expandedNodeId->namespaceUri("uri://test.namespace.org");
	expandedNodeId->serverIndex(1);


	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();
	value1->variant(expandedNodeId);

	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();

	BOOST_REQUIRE_EQUAL(14, converter.precedenceRank(OpcUaBuildInType_OpcUaExpandedNodeId));

	// expandedNodeId -> bool
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaBoolean));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaBoolean, value2));

	// expandedNodeId -> byte
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaByte));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaByte, value2));

	// expandedNodeId -> byteString
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaByteString));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaByteString, value2));

	// expandedNodeId -> dateTime
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaDateTime));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaDateTime, value2));

	// expandedNodeId -> double
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaDouble));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaDouble, value2));

	// expandedNodeId -> expandedNodeId
	BOOST_REQUIRE_EQUAL('-', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaExpandedNodeId));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaExpandedNodeId, value2));
	BOOST_REQUIRE_EQUAL(*expandedNodeId, *value2->getSPtr<OpcUaExpandedNodeId>());

	// expandedNodeId -> float
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaFloat));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaFloat, value2));

	// expandedNodeId -> Guid
	OpcUaGuid guid;
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaGuid));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaGuid, value2));

	// expandedNodeId -> int16
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaInt16));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt16, value2));

	// expandedNodeId -> int32
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaInt32));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt32, value2));

	// expandedNodeId -> int64
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaInt64));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt64, value2));

	// expandedNodeId -> nodeId
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaNodeId));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaNodeId, value2));
	BOOST_REQUIRE_EQUAL(OpcUaNodeId(1000,0), *value2->getSPtr<OpcUaNodeId>());

	// expandedNodeId -> sbyte
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaSByte));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));

	// expandedNodeId -> sbyte
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaSByte));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));

	// expandedNodeId -> statusCode
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaStatusCode));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaStatusCode, value2));

	// expandedNodeId -> string
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaString));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaString, value2));
	BOOST_REQUIRE_EQUAL("svr=1;nsu=uri://test.namespace.org;i=1000", value2->getSPtr<OpcUaString>()->toStdString());

	// expandedNodeId -> localizedText
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaLocalizedText));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaLocalizedText, value2));

	// expandedNodeId -> qualifiedName
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaQualifiedName));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaQualifiedName, value2));

	// expandedNodeId -> uint16
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaUInt16));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt16, value2));

	// expandedNodeId -> uint32
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaUInt32));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt32, value2));

	// expandedNodeId -> uint64
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaUInt64));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt64, value2));

	// expandedNodeId -> xmlElement
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaExpandedNodeId, OpcUaBuildInType_OpcUaXmlElement));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaXmlElement, value2));
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Float)
{
	OpcUaTypeConversion converter;

	OpcUaFloat floatValue = 24.5f;

	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();
	value1->variant(floatValue);

	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();

	BOOST_REQUIRE_EQUAL(1, converter.precedenceRank(OpcUaBuildInType_OpcUaFloat));

	// float -> bool
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaBoolean));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaBoolean, value2));
	BOOST_REQUIRE_EQUAL(true, value2->get<OpcUaBoolean>());

	// float -> byte
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaByte));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaByte, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaByte>());

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaByte>::max() + 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaByte, value2));

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaByte>::min() - 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaByte, value2));

	// float -> byteString
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaByteString));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaByteString, value2));

	// float -> dateTime
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaDateTime));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaDateTime, value2));

	// float -> double
	value1->variant(floatValue);
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaDouble));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaDouble, value2));
	BOOST_REQUIRE_EQUAL(floatValue, value2->get<OpcUaDouble>());

	// float -> expandedNodeId
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaExpandedNodeId));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaExpandedNodeId, value2));

	// float -> float
	BOOST_REQUIRE_EQUAL('-', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaFloat));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaFloat, value2));
	BOOST_REQUIRE_EQUAL(floatValue, value2->get<OpcUaFloat>());

	// float -> guid
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaGuid));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaGuid, value2));

	// float -> int16
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaInt16));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt16, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaInt16>());

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaInt16>::max() + 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt16, value2));

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaInt16>::min() - 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt16, value2));

	// float -> int32
	value1->variant(floatValue);
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaInt32));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt32, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaInt32>());

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaInt32>::max() + 1000);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt32, value2));

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaInt32>::min() - 1000);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt32, value2));

	// float -> int64
	value1->variant(floatValue);
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaInt64));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt64, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaInt64>());

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaInt64>::max() + 1e12);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt64, value2));

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaInt64>::min() - 1e12);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaInt64, value2));

	// float -> nodeId
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaNodeId));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaNodeId, value2));

	// float -> sbyte
	value1->variant(floatValue);
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaSByte));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaSByte>());

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaSByte>::max() + 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaSByte>::min() - 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));

	// float -> statusCode
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaStatusCode));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaStatusCode, value2));

	// float -> string
	value1->variant(floatValue);
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaString));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaString, value2));
	BOOST_REQUIRE_EQUAL("24.5", value2->getSPtr<OpcUaString>()->toStdString());

	// float -> localizedTest
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaLocalizedText));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaLocalizedText, value2));

	// float -> qualifiedName
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaQualifiedName));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaQualifiedName, value2));

	// float -> int16
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaUInt16));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt16, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaUInt16>());

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaUInt16>::max() + 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt16, value2));

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaUInt16>::min() - 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt16, value2));

	// float -> int32
	value1->variant(floatValue);
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaUInt32));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt32, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaUInt32>());

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaUInt32>::max() + 1000);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt32, value2));

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaUInt32>::min() - 1000);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt32, value2));

	// float -> int64
	value1->variant(floatValue);
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaFloat, OpcUaBuildInType_OpcUaUInt64));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt64, value2));
	BOOST_REQUIRE_EQUAL(25, value2->get<OpcUaUInt64>());

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaUInt64>::max() + 1e13);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt64, value2));

	value1->set<OpcUaFloat>((OpcUaFloat)std::numeric_limits<OpcUaUInt64>::min() - 1);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaUInt64, value2));

	// double -> xmlElement
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaDouble, OpcUaBuildInType_OpcUaXmlElement));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaXmlElement, value2));
}

BOOST_AUTO_TEST_SUITE_END()


