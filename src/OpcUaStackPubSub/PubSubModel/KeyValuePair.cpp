/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Aleksey Timin (atimin@gmail.com)
 */

#include <OpcUaStackPubSub/PubSubModel/KeyValuePair.h>

namespace OpcUaStackPubSub
{

	KeyValuePair::KeyValuePair(void)
	{
	}

	KeyValuePair::~KeyValuePair(void)
	{
	}

	void
	KeyValuePair::key(const OpcUaQualifiedName& key)
	{
		key_ = key;
	}

	const OpcUaQualifiedName&
	KeyValuePair::key(void)
	{
		return key_;
	}

	void
	KeyValuePair::value(const OpcUaVariant& value)
	{
		value_ = value;
	}

	const OpcUaVariant&
	KeyValuePair::value(void)
	{
		return value_;
	}

	KeyValuePair&
	KeyValuePair::operator=(const KeyValuePair& value)
	{
		key_ = const_cast<KeyValuePair&>(value).key();
		value_ = const_cast<KeyValuePair&>(value).value();
		return *this;
	}

}
