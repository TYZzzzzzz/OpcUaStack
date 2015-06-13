#ifndef __OpcUaStackServer_BaseNodeClass_h__
#define __OpcUaStackServer_BaseNodeClass_h__

#include <vector>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSetApplication/ForwardInfoSync.h"
#include "OpcUaStackServer/AddressSpaceModel/Attribute.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceType.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeBase.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceItemMap.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT BaseNodeClass
	: public AttributeBase
	{
	  public: 
		typedef boost::shared_ptr<BaseNodeClass> SPtr;
		typedef std::vector<BaseNodeClass::SPtr> Vec;
		typedef boost::weak_ptr<BaseNodeClass> WPtr;

		BaseNodeClass(void);
		BaseNodeClass(NodeClassType nodeClass);
		virtual ~BaseNodeClass(void);

		NodeIdAttribute& nodeId(void);
		NodeClassAttribute& nodeClass(void);
		BrowseNameAttribute& browseName(void);
		DisplayNameAttribute& displayName(void);
		DescriptionAttribute& description(void);
		WriteMaskAttribute& writeMask(void);
		UserWriteMaskAttribute& userWriteMask(void);

		Attribute* nodeIdAttribute(void); 
		Attribute* nodeClassAttribute(void); 
		Attribute* browseNameAttribute(void); 
		Attribute* displayNameAttribute(void); 
		Attribute* descriptionAttribute(void); 
		Attribute* writeMaskAttribute(void); 
		Attribute* userWriteMaskAttribute(void); 

		ReferenceItemMap& referenceItemMap(void);

		void copyTo(BaseNodeClass::SPtr baseNodeClass);
		void copyTo(BaseNodeClass& baseNodeClass);
		virtual BaseNodeClass::SPtr clone(void) = 0;

		void forwardInfoSync(ForwardInfoSync::SPtr forwardInfo);
		ForwardInfoSync::SPtr forwardInfoSync(void);

	  private:
		NodeIdAttribute nodeId_;
		NodeClassAttribute nodeClass_;
		BrowseNameAttribute browseName_;
		DisplayNameAttribute displayName_;
		DescriptionAttribute description_;
		WriteMaskAttribute writeMask_;
		UserWriteMaskAttribute userWriteMask_;

		ReferenceItemMap referenceItemMap_;

		ForwardInfoSync::SPtr forwardInfoSync_;
	};

}

#endif
