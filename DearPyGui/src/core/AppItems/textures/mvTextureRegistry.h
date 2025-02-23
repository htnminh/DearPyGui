#pragma once

#include "mvItemRegistry.h"
#include "mvModule_DearPyGui.h"
#include "cpp.hint"

namespace Marvel {

    MV_REGISTER_WIDGET(mvTextureRegistry, MV_ITEM_DESC_ROOT | MV_ITEM_DESC_CONTAINER,
        StorageValueTypes::None, 1);
    class mvTextureRegistry : public mvAppItem
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

        MV_APPLY_WIDGET_REGISTRATION(mvAppItemType::mvTextureRegistry, add_texture_registry)
		MV_NO_COMMANDS
		MV_DEFAULT_PARENTS
		MV_NO_CONSTANTS

        MV_START_CHILDREN
            MV_ADD_CHILD(mvAppItemType::mvStaticTexture),
            MV_ADD_CHILD(mvAppItemType::mvDynamicTexture),
            MV_ADD_CHILD(mvAppItemType::mvRawTexture)
        MV_END_CHILDREN

    public:

        mvTextureRegistry(mvUUID uuid);

        void draw(ImDrawList* drawlist, float x, float y) override;
        void onChildRemoved(mvRef<mvAppItem> item) override;
        void onChildrenRemoved() override;

    private:

        void show_debugger();

    private:

        int _selection = -1;
    };

}
