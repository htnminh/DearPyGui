#include "mvSameLine.h"
#include "mvItemRegistry.h"
#include "mvPyObject.h"

namespace Marvel {

	void mvSameLine::InsertParser(std::map<std::string, mvPythonParser>* parsers)
	{

		mvPythonParser parser(mvPyDataType::UUID, "Places a widget on the same line as the previous widget. Can also be used for horizontal spacing.", { "Widgets" });
		mvAppItem::AddCommonArgs(parser, (CommonParserArgs)(
			MV_PARSER_ARG_ID |
			MV_PARSER_ARG_PARENT |
			MV_PARSER_ARG_BEFORE |
			MV_PARSER_ARG_SHOW)
		);

		parser.addArg<mvPyDataType::Float>("xoffset", mvArgType::KEYWORD_ARG, "0.0", "Offset from containing window.");
		parser.addArg<mvPyDataType::Float>("spacing", mvArgType::KEYWORD_ARG, "-1.0", "Offset from previous widget.");

		parser.finalize();

		parsers->insert({ s_command, parser });
	}


	mvSameLine::mvSameLine(mvUUID uuid)
		: mvAppItem(uuid)
	{
	}

	void mvSameLine::applySpecificTemplate(mvAppItem* item)
	{
		auto titem = static_cast<mvSameLine*>(item);
		_xoffset = titem->_xoffset;
		_spacing = titem->_spacing;
	}

	void mvSameLine::draw(ImDrawList* drawlist, float x, float y)
	{
		ImGui::SameLine(_xoffset, _spacing);
	}

	void mvSameLine::handleSpecificKeywordArgs(PyObject* dict)
	{
		if (dict == nullptr)
			return;

		if (PyObject* item = PyDict_GetItemString(dict, "xoffset")) _xoffset = ToFloat(item);
		if (PyObject* item = PyDict_GetItemString(dict, "spacing")) _spacing = ToFloat(item);

	}

	void mvSameLine::getSpecificConfiguration(PyObject* dict)
	{
		if (dict == nullptr)
			return;

		PyDict_SetItemString(dict, "xoffset", mvPyObject(ToPyFloat(_xoffset)));
		PyDict_SetItemString(dict, "spacing", mvPyObject(ToPyFloat(_spacing)));
	}

}