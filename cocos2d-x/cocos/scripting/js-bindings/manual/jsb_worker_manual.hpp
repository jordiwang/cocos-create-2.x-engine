//
//  jsb_worker_manual.hpp
//  libcocos2d iOS
//
//  Created by admin on 2024/5/14.
//

#pragma once

#include <stdio.h>

namespace se {
    class Object;
    class ScriptEngine;
}

bool register_web_worker(se::ScriptEngine *inst, se::Object *ns);

bool register_web_worker_thread(se::ScriptEngine *inst, se::Object *ns);

