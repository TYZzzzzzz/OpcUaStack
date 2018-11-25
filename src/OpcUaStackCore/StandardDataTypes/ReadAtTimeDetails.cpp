/*
    DataTypeClass: ReadAtTimeDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ReadAtTimeDetails.h"

namespace OpcUaStackCore
{
    
    ReadAtTimeDetails::ReadAtTimeDetails(void)
    : HistoryReadDetails()
    , reqTimes_()
    , useSimpleBounds_()
    {
    }
    
    ReadAtTimeDetails::~ReadAtTimeDetails(void)
    {
    }
    
    OpcUaUtcTimeArray&
    ReadAtTimeDetails::reqTimes(void)
    {
        return reqTimes_;
    }
    
    OpcUaBoolean&
    ReadAtTimeDetails::useSimpleBounds(void)
    {
        return useSimpleBounds_;
    }
    
    bool
    ReadAtTimeDetails::operator==(const ReadAtTimeDetails& value)
    {
        ReadAtTimeDetails* dst = const_cast<ReadAtTimeDetails*>(&value);
        if (reqTimes_ != dst->reqTimes()) return false;
        if (useSimpleBounds_ != dst->useSimpleBounds()) return false;
        return true;
    }
    
    bool
    ReadAtTimeDetails::operator!=(const ReadAtTimeDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    ReadAtTimeDetails::copyTo(ReadAtTimeDetails& value)
    {
        reqTimes_.copyTo(value.reqTimes());
        value.useSimpleBounds_ = useSimpleBounds_;
    }
    
    ReadAtTimeDetails&
    ReadAtTimeDetails::operator=(const ReadAtTimeDetails& value)
    {
        const_cast<ReadAtTimeDetails*>(&value)->copyTo(*this);
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
    ReadAtTimeDetails::factory(void)
    {
    	return constructSPtr<ReadAtTimeDetails>();
    }
    
    std::string
    ReadAtTimeDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ReadAtTimeDetails::typeName(void)
    {
    	return "ReadAtTimeDetails";
    }
    
    OpcUaNodeId
    ReadAtTimeDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)653,0);
    }
    
    OpcUaNodeId
    ReadAtTimeDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)655, 0);
    }
    
    OpcUaNodeId
    ReadAtTimeDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)654, 0);
    }
    
    OpcUaNodeId
    ReadAtTimeDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15269, 0);
    }
    
    void
    ReadAtTimeDetails::opcUaBinaryEncode(std::ostream& os) const
    {
        HistoryReadDetails::opcUaBinaryEncode(os);
        reqTimes_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,useSimpleBounds_);
    }
    
    void
    ReadAtTimeDetails::opcUaBinaryDecode(std::istream& is)
    {
        HistoryReadDetails::opcUaBinaryDecode(is);
        reqTimes_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,useSimpleBounds_);
    }
    
    bool
    ReadAtTimeDetails::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ReadAtTimeDetails::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ReadAtTimeDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ReadAtTimeDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!reqTimes_.xmlEncode(elementTree, "UtcTime", xmlns)) return false;
        pt.push_back(std::make_pair("ReqTimes", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, useSimpleBounds_)) return false;
        pt.push_back(std::make_pair("UseSimpleBounds", elementTree));
    
        return true;
    }
    
    bool
    ReadAtTimeDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ReadAtTimeDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("ReqTimes");
        if (!tree) return false;
        if (!reqTimes_.xmlDecode(*tree, "UtcTime", xmlns)) return false;
    
        tree = pt.get_child_optional("UseSimpleBounds");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, useSimpleBounds_)) return false;
    
        return true;
    }
    
    bool
    ReadAtTimeDetails::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    ReadAtTimeDetails::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    ReadAtTimeDetails::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    ReadAtTimeDetails::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    ReadAtTimeDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ReadAtTimeDetails* dst = dynamic_cast<ReadAtTimeDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ReadAtTimeDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ReadAtTimeDetails* dst = dynamic_cast<ReadAtTimeDetails*>(&extensionObjectBase);
    	return *const_cast<ReadAtTimeDetails*>(this) == *dst;
    }
    
    void
    ReadAtTimeDetails::out(std::ostream& os)
    {
        os << "ReqTimes="; reqTimes_.out(os);
        os << ", UseSimpleBounds=" << useSimpleBounds_;
    }

}
