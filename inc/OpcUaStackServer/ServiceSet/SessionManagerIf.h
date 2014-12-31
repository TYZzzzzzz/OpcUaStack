#ifndef __OpcUaStackServer_SessionManagerIf_h__
#define __OpcUaStackServer_SessionManagerIf_h__

#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class SessionManagerIf
	{
	  public:
	    virtual void createSessionResponse(boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction) = 0;
		virtual void activateSessionResponse(boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction) = 0;
		virtual void send(OpcUaNodeId& opcUaNodeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction) = 0;
	};

};

#endif