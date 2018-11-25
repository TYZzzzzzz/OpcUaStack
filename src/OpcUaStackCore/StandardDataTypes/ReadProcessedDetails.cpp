/*
    DataTypeClass: ReadProcessedDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ReadProcessedDetails.h"

namespace OpcUaStackCore
{
    
    ReadProcessedDetails::ReadProcessedDetails(void)
    : HistoryReadDetails()
    , startTime_()
    , endTime_()
    , processingInterval_()
    , aggregateType_()
    , aggregateConfiguration_()
    {
    }
    
    ReadProcessedDetails::~ReadProcessedDetails(void)
    {
    }
    
    OpcUaUtcTime&
    ReadProcessedDetails::startTime(void)
    {
        return startTime_;
    }
    
    OpcUaUtcTime&
    ReadProcessedDetails::endTime(void)
    {
        return endTime_;
    }
    
    OpcUaDuration&
    ReadProcessedDetails::processingInterval(void)
    {
        return processingInterval_;
    }
    
    OpcUaNodeIdArray&
    ReadProcessedDetails::aggregateType(void)
    {
        return aggregateType_;
    }
    
    AggregateConfiguration&
    ReadProcessedDetails::aggregateConfiguration(void)
    {
        return aggregateConfiguration_;
    }
    
    bool
    ReadProcessedDetails::operator==(const ReadProcessedDetails& value)
    {
        ReadProcessedDetails* dst = const_cast<ReadProcessedDetails*>(&value);
        if (startTime_ != dst->startTime()) return false;
        if (endTime_ != dst->endTime()) return false;
        if (processingInterval_ != dst->processingInterval()) return false;
        if (aggregateType_ != dst->aggregateType()) return false;
        if (aggregateConfiguration_ != dst->aggregateConfiguration()) return false;
        return true;
    }
    
    bool
    ReadProcessedDetails::operator!=(const ReadProcessedDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    ReadProcessedDetails::copyTo(ReadProcessedDetails& value)
    {
        startTime_.copyTo(value.startTime());
        endTime_.copyTo(value.endTime());
        value.processingInterval_ = processingInterval_;
        aggregateType_.copyTo(value.aggregateType());
        aggregateConfiguration_.copyTo(value.aggregateConfiguration());
    }
    
    ReadProcessedDetails&
    ReadProcessedDetails::operator=(const ReadProcessedDetails& value)
    {
        const_cast<ReadProcessedDetails*>(&value)->copyTo(*this);
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
    ReadProcessedDetails::factory(void)
    {
    	return constructSPtr<ReadProcessedDetails>();
    }
    
    std::string
    ReadProcessedDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ReadProcessedDetails::typeName(void)
    {
    	return "ReadProcessedDetails";
    }
    
    OpcUaNodeId
    ReadProcessedDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)650,0);
    }
    
    OpcUaNodeId
    ReadProcessedDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)652, 0);
    }
    
    OpcUaNodeId
    ReadProcessedDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)651, 0);
    }
    
    OpcUaNodeId
    ReadProcessedDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15264, 0);
    }
    
    void
    ReadProcessedDetails::opcUaBinaryEncode(std::ostream& os) const
    {
        HistoryReadDetails::opcUaBinaryEncode(os);
        startTime_.opcUaBinaryEncode(os);
        endTime_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,processingInterval_);
        aggregateType_.opcUaBinaryEncode(os);
        aggregateConfiguration_.opcUaBinaryEncode(os);
    }
    
    void
    ReadProcessedDetails::opcUaBinaryDecode(std::istream& is)
    {
        HistoryReadDetails::opcUaBinaryDecode(is);
        startTime_.opcUaBinaryDecode(is);
        endTime_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,processingInterval_);
        aggregateType_.opcUaBinaryDecode(is);
        aggregateConfiguration_.opcUaBinaryDecode(is);
    }
    
    bool
    ReadProcessedDetails::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ReadProcessedDetails::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ReadProcessedDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ReadProcessedDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!startTime_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!endTime_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("EndTime", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, processingInterval_)) return false;
        pt.push_back(std::make_pair("ProcessingInterval", elementTree));
    
        elementTree.clear();
        if (!aggregateType_.xmlEncode(elementTree, "NodeId", xmlns)) return false;
        pt.push_back(std::make_pair("AggregateType", elementTree));
    
        elementTree.clear();
        if (!aggregateConfiguration_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("AggregateConfiguration", elementTree));
    
        return true;
    }
    
    bool
    ReadProcessedDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ReadProcessedDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("StartTime");
        if (!tree) return false;
        if (!startTime_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("EndTime");
        if (!tree) return false;
        if (!endTime_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ProcessingInterval");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, processingInterval_)) return false;
    
        tree = pt.get_child_optional("AggregateType");
        if (!tree) return false;
        if (!aggregateType_.xmlDecode(*tree, "NodeId", xmlns)) return false;
    
        tree = pt.get_child_optional("AggregateConfiguration");
        if (!tree) return false;
        if (!aggregateConfiguration_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    ReadProcessedDetails::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    ReadProcessedDetails::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    ReadProcessedDetails::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    ReadProcessedDetails::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    ReadProcessedDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ReadProcessedDetails* dst = dynamic_cast<ReadProcessedDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ReadProcessedDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ReadProcessedDetails* dst = dynamic_cast<ReadProcessedDetails*>(&extensionObjectBase);
    	return *const_cast<ReadProcessedDetails*>(this) == *dst;
    }
    
    void
    ReadProcessedDetails::out(std::ostream& os)
    {
        os << "StartTime="; startTime_.out(os);
        os << ", EndTime="; endTime_.out(os);
        os << ", ProcessingInterval=" << processingInterval_;
        os << ", AggregateType="; aggregateType_.out(os);
        os << ", AggregateConfiguration="; aggregateConfiguration_.out(os);
    }

}
