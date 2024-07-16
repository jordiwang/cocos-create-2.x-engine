#pragma once
#include "base/ccConfig.h"
#if USE_PARTICLE > 0

namespace se {
    class Class;
    class Object;
    class ScriptEngine;
}

extern se::Object* __jsb_cocos2d_ParticleSimulator_proto;
extern se::Class* __jsb_cocos2d_ParticleSimulator_class;

bool js_register_cocos2d_ParticleSimulator(se::ScriptEngine *inst, se::Object* obj);
bool register_all_cocos2dx_particle(se::ScriptEngine*, se::Object* obj);

#endif //#if USE_PARTICLE > 0
