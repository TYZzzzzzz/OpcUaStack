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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "BuildConfig.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/Generator/DataTypeGenerator.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DataTypeGenerator
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DataTypeGenerator::DataTypeGenerator(void)
	: informationModel_()
	, projectNamespace_("OpcUaStackCore")
	, parentProjectNamespace_("OpcUaStackCore")
	, sourceContent_("")
	, headerContent_("")
	{
	}

	DataTypeGenerator::~DataTypeGenerator(void)
	{
	}

	bool
	DataTypeGenerator::generate(const OpcUaNodeId& dataType)
	{
		// FIXME: todo

		// generate header and source
		return
			generateHeader() &&
			generateSource();
	}

	void
	DataTypeGenerator::informationModel(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
	}

	void
	DataTypeGenerator::projectNamespace(const std::string& projectNamespace)
	{
		projectNamespace_ = projectNamespace;
	}

	void
	DataTypeGenerator::parentProjectNamespace(const std::string& parentProjectNamespace)
	{
		parentProjectNamespace_ = parentProjectNamespace;
	}

	std::string&
	DataTypeGenerator::sourceContent(void)
	{
		return sourceContent_;
	}

	std::string&
	DataTypeGenerator::headerContent(void)
	{
		return headerContent_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// header
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	DataTypeGenerator::generateHeader(void)
	{
		return
			generateHeaderComments();
	}

	bool
	DataTypeGenerator::generateHeaderComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    DataTypeClass: " << "className" << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    DataTypeCodeGenerator Version:"  << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;
		ss << std::endl;
		ss << "    Autor: Kai Huebl (kai@huebl-sgh.de)" << std::endl;
		ss << "*/" << std::endl;

		headerContent_ += ss.str();
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// source
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	DataTypeGenerator::generateSource(void)
	{
		// FIXME: todo
		return true;
	}

}
