#pragma once

#include "mvAppItem.h"
#include "mvItemRegistry.h"

namespace Marvel {

	MV_REGISTER_WIDGET(mvDrawLayer, MV_ITEM_DESC_CONTAINER, StorageValueTypes::None, 2);
	class mvDrawLayer : public mvAppItem
	{
	public:

		static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

		MV_APPLY_WIDGET_REGISTRATION(mvAppItemType::mvDrawLayer, add_draw_layer)
		MV_NO_COMMANDS
		MV_NO_CONSTANTS

		MV_START_PARENTS
			MV_ADD_PARENT(mvAppItemType::mvTemplateRegistry),
			MV_ADD_PARENT(mvAppItemType::mvStage),
			MV_ADD_PARENT(mvAppItemType::mvDrawlist),
			MV_ADD_PARENT(mvAppItemType::mvDrawLayer),
			MV_ADD_PARENT(mvAppItemType::mvWindowAppItem),
			MV_ADD_PARENT(mvAppItemType::mvPlot),
			MV_ADD_PARENT(mvAppItemType::mvViewportDrawlist)
		MV_END_PARENTS

		MV_START_CHILDREN
			MV_ADD_CHILD(mvAppItemType::mvDrawLine),
			MV_ADD_CHILD(mvAppItemType::mvDrawArrow),
			MV_ADD_CHILD(mvAppItemType::mvDrawTriangle),
			MV_ADD_CHILD(mvAppItemType::mvDrawCircle),
			MV_ADD_CHILD(mvAppItemType::mvDrawEllipse),
			MV_ADD_CHILD(mvAppItemType::mvDrawBezierCubic),
			MV_ADD_CHILD(mvAppItemType::mvDrawBezierQuadratic),
			MV_ADD_CHILD(mvAppItemType::mvDrawQuad),
			MV_ADD_CHILD(mvAppItemType::mvDrawRect),
			MV_ADD_CHILD(mvAppItemType::mvDrawText),
			MV_ADD_CHILD(mvAppItemType::mvDrawPolygon),
			MV_ADD_CHILD(mvAppItemType::mvDrawPolyline),
			MV_ADD_CHILD(mvAppItemType::mvDrawImage)
		MV_END_CHILDREN

	public:

		mvDrawLayer(mvUUID uuid);

		void draw(ImDrawList* drawlist, float x, float y) override;

	};

}
