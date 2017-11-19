/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackPubSub/Network/NetworkMessage.h"

namespace OpcUaStackPubSub
{

	NetworkMessage::NetworkMessage(void)
	: networkMessageHeader_(constructSPtr<NetworkMessageHeader>())
	, dataSetPayloadHeader_(constructSPtr<DataSetPayloadHeader>())
	, dataSetPayload_(constructSPtr<DataSetPayload>())
	{
	}

	NetworkMessage::~NetworkMessage(void)
	{
	}

	void
	NetworkMessage::networkMessageHeader(NetworkMessageHeader::SPtr networkMessageHeader)
	{
		networkMessageHeader_ = networkMessageHeader;
	}

	NetworkMessageHeader::SPtr
	NetworkMessage::networkMessageHeader()
	{
		return networkMessageHeader_;
	}

	void
	NetworkMessage::dataSetPayloadHeader(DataSetPayloadHeader::SPtr dataSetPayloadHeader)
	{
		dataSetPayloadHeader_ = dataSetPayloadHeader;
	}

	DataSetPayloadHeader::SPtr
	NetworkMessage::dataSetPayloadHeader()
	{
		return dataSetPayloadHeader_;
	}

	void
	NetworkMessage::dataSetPayload(DataSetPayload::SPtr dataSetPayload)
	{
		dataSetPayload_ = dataSetPayload;
	}

	DataSetPayload::SPtr
	NetworkMessage::dataSetPayload()
	{
		return dataSetPayload_;
	}

	void NetworkMessage::opcUaBinaryEncode(std::ostream& os) const
	{
		//FIXME:
	}

	void NetworkMessage::opcUaBinaryDecode(std::istream& is)
	{
		//FIXME:
	}

}
