#include <iostream>
#include "nanogui/common.h"
#include "nanogui/formhelper.h"
#include "nanogui/layout.h"
#include "nanogui/screen.h"
#include "nanogui/window.h"

using namespace nanogui;

class AheadFork {
    ref<Screen> mScreen;
    public:
        void main_loop() {
            mScreen = new Screen({400,500}, "aheadfork"/*, 4, 1*/);

            auto window = new Window(mScreen);

//            auto group = window->add<GroupLayout>();

            mScreen->set_visible(true);
            nanogui::mainloop();
        }

        AheadFork() {
            nanogui::init();
        }

        ~AheadFork() {
            nanogui::shutdown();
        }
};

