/*
    DataTypeClass: MonitoredItemNotification

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/MonitoredItemNotification.h"

namespace OpcUaStackCore
{
    
    MonitoredItemNotification::MonitoredItemNotification(void)
    : Object()
    , ExtensionObjectBase()
    , clientHandle_()
    , value_()
    {
    }
    
    MonitoredItemNotification::~MonitoredItemNotification(void)
    {
    }
    
    OpcUaIntegerId&
    MonitoredItemNotification::clientHandle(void)
    {
        return clientHandle_;
    }
    
    OpcUaDataValue&
    MonitoredItemNotification::value(void)
    {
        return value_;
    }
    
    bool
    MonitoredItemNotification::operator==(const MonitoredItemNotification& value)
    {
        MonitoredItemNotification* dst = const_cast<MonitoredItemNotification*>(&value);
        if (clientHandle_ != dst->clientHandle()) return false;
        if (value_ != dst->value()) return false;
        return true;
    }
    
    bool
    MonitoredItemNotification::operator!=(const MonitoredItemNotification& value)
    {
        return !this->operator==(value);
    }
    
    void
    MonitoredItemNotification::copyTo(MonitoredItemNotification& value)
    {
        value.clientHandle_ = clientHandle_;
        value_.copyTo(value.value());
    }
    
    MonitoredItemNotification&
    MonitoredItemNotification::operator=(const MonitoredItemNotification& value)
    {
        const_cast<MonitoredItemNotification*>(&value)->copyTo(*this);
        return *this;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    MonitoredItemNotification::factory(void)
    {
    	return constructSPtr<MonitoredItemNotification>();
    }
    
    std::string
    MonitoredItemNotification::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    MonitoredItemNotification::typeName(void)
    {
    	return "MonitoredItemNotification";
    }
    
    OpcUaNodeId
    MonitoredItemNotification::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)806,0);
    }
    
    OpcUaNodeId
    MonitoredItemNotification::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)808, 0);
    }
    
    OpcUaNodeId
    MonitoredItemNotification::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)807, 0);
    }
    
    OpcUaNodeId
    MonitoredItemNotification::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15346, 0);
    }
    
    void
    MonitoredItemNotification::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,clientHandle_);
        value_.opcUaBinaryEncode(os);
    }
    
    void
    MonitoredItemNotification::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,clientHandle_);
        value_.opcUaBinaryDecode(is);
    }
    
    bool
    MonitoredItemNotification::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    MonitoredItemNotification::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    MonitoredItemNotification::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    MonitoredItemNotification::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, clientHandle_)) return false;
        pt.push_back(std::make_pair("ClientHandle", elementTree));
    
        elementTree.clear();
        if (!value_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Value", elementTree));
    
        return true;
    }
    
    bool
    MonitoredItemNotification::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    MonitoredItemNotification::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("ClientHandle");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, clientHandle_)) return false;
    
        tree = pt.get_child_optional("Value");
        if (!tree) return false;
        if (!value_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    MonitoredItemNotification::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    MonitoredItemNotification::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    MonitoredItemNotification::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    MonitoredItemNotification::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    MonitoredItemNotification::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	MonitoredItemNotification* dst = dynamic_cast<MonitoredItemNotification*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    MonitoredItemNotification::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	MonitoredItemNotification* dst = dynamic_cast<MonitoredItemNotification*>(&extensionObjectBase);
    	return *const_cast<MonitoredItemNotification*>(this) == *dst;
    }
    
    void
    MonitoredItemNotification::out(std::ostream& os)
    {
        os << "ClientHandle=" << clientHandle_;
        os << ", Value="; value_.out(os);
    }

}
