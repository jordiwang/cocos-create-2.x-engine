const fs = require('fs');
const path = require('path');


const ars = fs.readdirSync(__dirname).filter(x => x.endsWith('.a'));
const list = [];
for(let f of ars) {
console.log(`# import ${f}`)
  let t = f.split('.')[0].replace(/^lib/, '');
console.log(`
#======================================
include $(CLEAR_VARS)
LOCAL_MODULE := ${t}
LOCAL_MODULE_FILENAME := ${t}
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/tf/${f}
include $(PREBUILT_STATIC_LIBRARY)`
,'\n');
list.push(t);
}

// console.log(list.join(' \\\n'));
console.log(list.map(x=> `LOCAL_STATIC_LIBRARIES += ${x}`).join('\n'));
