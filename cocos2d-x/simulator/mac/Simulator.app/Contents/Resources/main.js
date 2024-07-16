(function () {

    function boot () {
        window.__quick_compile_project__.destPath = '/Users/zeweiwang/Documents/block_joureny/temp/quick-scripts/dst/';

        cc.assetManager.init({
            importBase: '/Users/zeweiwang/Documents/block_joureny/library/imports/',
            nativeBase: '/Users/zeweiwang/Documents/block_joureny/library/imports/'
        });

        var onStart = function () {
            cc.view.resizeWithBrowserSize(true);

            // init assets

            // load stashed scene, unlike the standard loading process, here we do some hack to reduce the engine size.
            cc.assetManager.loadAny({url: 'preview-scene.json', __isNative__: false }, null,
                function (err, sceneAsset) {
                    if (err) {
                        cc.error(err.message, err.stack);
                        return;
                    }
                    var scene = sceneAsset.scene;
                    scene._name = sceneAsset._name;
                    // HACK: Change key to uuid from url
                    cc.assetManager.dependUtil._depends.add(scene._id, cc.assetManager.dependUtil._depends.get('preview-scene.json'));
                    // scene._id = ??;   stashed scene dont have uuid...
                    cc.director.runSceneImmediate(scene, function () {
                        // play game
                        cc.game.resume();
                    });
                }
            );

            // purge
            //noinspection JSUndeclaredVariable
            _CCSettings = undefined;
        };

        var option = {
            debugMode: cc.debug.DebugMode.INFO,
            showFPS: true,
            frameRate: 60,
            groupList: _CCSettings.groupList,
            collisionMatrix: _CCSettings.collisionMatrix,
        };

        var RESOURCES = cc.AssetManager.BuiltinBundleName.RESOURCES;
        var INTERNAL = cc.AssetManager.BuiltinBundleName.INTERNAL;
        var MAIN = cc.AssetManager.BuiltinBundleName.MAIN;
        var bundleRoot = [INTERNAL];
        _CCSettings.hasResourcesBundle && bundleRoot.push(RESOURCES);

        var count = 0;
        function cb (err) {
            if (err) return console.error(err);
            count++;
            if (count === bundleRoot.length + 1) {
                cc.assetManager.loadBundle(MAIN, function (err) {
                    if (!err) cc.game.run(option, onStart);
                });
            }
        }
        
        cc.assetManager.loadScript(_CCSettings.jsList.map(function (x) { return '/Users/zeweiwang/Documents/block_joureny/' + x; }), cb);

        for (var i = 0; i < bundleRoot.length; i++) {
            cc.assetManager.loadBundle(bundleRoot[i], cb);
        }
        
    }

    require('/Users/zeweiwang/Documents/block_joureny/temp/quick-scripts/dst/' + '__quick_compile__.js');
    require('src/simulator-config.js');
    require('src/settings.js');
    require('src/cocos2d-jsb.js');
    require('jsb-adapter/jsb-engine.js');
    require('src/asset-record-pipe.js');

    boot();

})();
