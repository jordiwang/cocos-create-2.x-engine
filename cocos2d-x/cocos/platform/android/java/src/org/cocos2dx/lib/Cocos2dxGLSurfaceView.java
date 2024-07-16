/****************************************************************************
Copyright (c) 2010-2013 cocos2d-x.org
Copyright (c) 2013-2016 Chukong Technologies Inc.
Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 ****************************************************************************/
package org.cocos2dx.lib;

import android.content.Context;
import android.os.Handler;
import android.util.AttributeSet;
import android.util.Log;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.SurfaceHolder;

public class Cocos2dxGLSurfaceView extends CocosGLViewPatched {
    // ===========================================================
    // Constants
    // ===========================================================

    private static final String TAG = Cocos2dxGLSurfaceView.class.getSimpleName();

    private final static int HANDLER_OPEN_IME_KEYBOARD = 2;
    private final static int HANDLER_CLOSE_IME_KEYBOARD = 3;

    // ===========================================================
    // Fields
    // ===========================================================

    // REFINE: Static handler -> Potential leak!
    private static Handler sHandler;
    private static Cocos2dxGLSurfaceView mCocos2dxGLSurfaceView;

    private Cocos2dxRenderer mCocos2dxRenderer;
    private boolean mStopHandleTouchAndKeyEvents = false;

    public static native void nativeOnSizeChanged(int width, int height);

    // ===========================================================
    // Constructors
    // ===========================================================

    public Cocos2dxGLSurfaceView(final Context context) {
        super(context);

        this.initView();
    }

    public Cocos2dxGLSurfaceView(final Context context, final AttributeSet attrs) {
        super(context, attrs);
        
        this.initView();
    }

    protected void initView() {
        this.setEGLContextClientVersion(2);
        this.setFocusableInTouchMode(true);

        Cocos2dxGLSurfaceView.mCocos2dxGLSurfaceView = this;
    }

    // ===========================================================
    // Getter & Setter
    // ===========================================================


       public static Cocos2dxGLSurfaceView getInstance() {
       return mCocos2dxGLSurfaceView;
       }

       public static void queueAccelerometer(final float x, final float y, final float z, final long timestamp) {
           mCocos2dxGLSurfaceView.queueEvent(new Runnable() {
            @Override
                public void run() {
                    Cocos2dxAccelerometer.onSensorChanged(x, y, z, timestamp);
            }
        });
    }

    public void setCocos2dxRenderer(final Cocos2dxRenderer renderer) {
        this.mCocos2dxRenderer = renderer;
        this.setRenderer(this.mCocos2dxRenderer);
    }

    private String getContentText() {
        return this.mCocos2dxRenderer.getContentText();
    }

    // ===========================================================
    // Methods for/from SuperClass/Interfaces
    // ===========================================================

    @Override
    public void onResume() {
        super.onResume();
        this.setRenderMode(RENDERMODE_CONTINUOUSLY);
        mCocos2dxRenderer.updateFrame();
        this.queueEvent(new Runnable() {
            @Override
            public void run() {
                Cocos2dxGLSurfaceView.this.mCocos2dxRenderer.handleOnResume();
            }
        });
        mCocos2dxRenderer.setPauseInMainThread(false);
    }

    @Override
    public void onPause() {
        mCocos2dxRenderer.updateFrame();
        this.queueEvent(new Runnable() {
            @Override
            public void run() {
                Cocos2dxGLSurfaceView.this.mCocos2dxRenderer.handleOnPause();
            }
        });
        this.setRenderMode(RENDERMODE_WHEN_DIRTY);
        mCocos2dxRenderer.setPauseInMainThread(true);
        //super.onPause();
    }

    @Override
    public boolean onTouchEvent(final MotionEvent pMotionEvent) {

        // these data are used in ACTION_MOVE and ACTION_CANCEL
        int pointerNumber = pMotionEvent.getPointerCount();
        int[] ids = new int[pointerNumber];
        float[] xs = new float[pointerNumber];
        float[] ys = new float[pointerNumber];

        for (int i = 0; i < pointerNumber; i++) {
            ids[i] = pMotionEvent.getPointerId(i);
            xs[i] = pMotionEvent.getX(i);
            ys[i] = pMotionEvent.getY(i);
        }

        mCocos2dxRenderer.updateFrame();

        switch (pMotionEvent.getAction() & MotionEvent.ACTION_MASK) {
            case MotionEvent.ACTION_POINTER_DOWN:
                if (mStopHandleTouchAndKeyEvents) {
                    Cocos2dxEditBox.complete();
                    return true;
                }

                int indexPointerDown = pMotionEvent.getAction() >> MotionEvent.ACTION_POINTER_INDEX_SHIFT;
                int idPointerDown = pMotionEvent.getPointerId(indexPointerDown);
                float xPointerDown = pMotionEvent.getX(indexPointerDown);
                float yPointerDown = pMotionEvent.getY(indexPointerDown);

                Cocos2dxGLSurfaceView.this.mCocos2dxRenderer.handleActionDownQueue(idPointerDown, xPointerDown, yPointerDown);
                break;

            case MotionEvent.ACTION_DOWN:
                if (mStopHandleTouchAndKeyEvents) {
                    Cocos2dxEditBox.complete();
                    return true;
                }

                // there are only one finger on the screen
                int idDown = pMotionEvent.getPointerId(0);
                float xDown = xs[0];
                float yDown = ys[0];

                Cocos2dxGLSurfaceView.this.mCocos2dxRenderer.handleActionDownQueue(idDown, xDown, yDown);
                break;

            case MotionEvent.ACTION_MOVE:
                Cocos2dxGLSurfaceView.this.mCocos2dxRenderer.handleActionMoveQueue(ids, xs, ys);
                break;

            case MotionEvent.ACTION_POINTER_UP:
                int indexPointUp = pMotionEvent.getAction() >> MotionEvent.ACTION_POINTER_INDEX_SHIFT;
                int idPointerUp = pMotionEvent.getPointerId(indexPointUp);
                float xPointerUp = pMotionEvent.getX(indexPointUp);
                float yPointerUp = pMotionEvent.getY(indexPointUp);

                Cocos2dxGLSurfaceView.this.mCocos2dxRenderer.handleActionUpQueue(idPointerUp, xPointerUp, yPointerUp);
                break;

            case MotionEvent.ACTION_UP:
                // there are only one finger on the screen
                int idUp = pMotionEvent.getPointerId(0);
                float xUp = xs[0];
                float yUp = ys[0];

                Cocos2dxGLSurfaceView.this.mCocos2dxRenderer.handleActionUpQueue(idUp, xUp, yUp);
                break;

            case MotionEvent.ACTION_CANCEL:
                Cocos2dxGLSurfaceView.this.mCocos2dxRenderer.handleActionCancelQueue(ids, xs, ys);
                break;
        }

        /*
        if (BuildConfig.DEBUG) {
            Cocos2dxGLSurfaceView.dumpMotionEvent(pMotionEvent);
        }
        */
        return true;
    }

    /*
     * This function is called before Cocos2dxRenderer.nativeInit(), so the
     * width and height is correct.
     */
    @Override
    protected void onSizeChanged(final int pNewSurfaceWidth, final int pNewSurfaceHeight, final int pOldSurfaceWidth, final int pOldSurfaceHeight) {
        if(!this.isInEditMode()) {
            this.mCocos2dxRenderer.setScreenWidthAndHeight(pNewSurfaceWidth, pNewSurfaceHeight);
            nativeOnSizeChanged(pNewSurfaceWidth, pNewSurfaceHeight);
        }
    }

    @Override
    public boolean onKeyDown(final int pKeyCode, final KeyEvent pKeyEvent) {

        mCocos2dxRenderer.updateFrame();

        switch (pKeyCode) {
            case KeyEvent.KEYCODE_BACK:
                Cocos2dxVideoHelper.mVideoHandler.sendEmptyMessage(Cocos2dxVideoHelper.KeyEventBack);
            case KeyEvent.KEYCODE_MENU:
            case KeyEvent.KEYCODE_DPAD_LEFT:
            case KeyEvent.KEYCODE_DPAD_RIGHT:
            case KeyEvent.KEYCODE_DPAD_UP:
            case KeyEvent.KEYCODE_DPAD_DOWN:
            case KeyEvent.KEYCODE_ENTER:
            case KeyEvent.KEYCODE_MEDIA_PLAY_PAUSE:
            case KeyEvent.KEYCODE_DPAD_CENTER:
                this.queueEvent(new Runnable() {
                    @Override
                    public void run() {
                        Cocos2dxGLSurfaceView.this.mCocos2dxRenderer.handleKeyDown(pKeyCode);
                    }
                });
                return true;
            default:
                return super.onKeyDown(pKeyCode, pKeyEvent);
        }
    }

    @Override
    public boolean onKeyUp(final int keyCode, KeyEvent event) {

        mCocos2dxRenderer.updateFrame();

        switch (keyCode) {
            case KeyEvent.KEYCODE_BACK:
            case KeyEvent.KEYCODE_MENU:
            case KeyEvent.KEYCODE_DPAD_LEFT:
            case KeyEvent.KEYCODE_DPAD_RIGHT:
            case KeyEvent.KEYCODE_DPAD_UP:
            case KeyEvent.KEYCODE_DPAD_DOWN:
            case KeyEvent.KEYCODE_ENTER:
            case KeyEvent.KEYCODE_MEDIA_PLAY_PAUSE:
            case KeyEvent.KEYCODE_DPAD_CENTER:
                this.queueEvent(new Runnable() {
                    @Override
                    public void run() {
                        Cocos2dxGLSurfaceView.this.mCocos2dxRenderer.handleKeyUp(keyCode);
                    }
                });
                return true;
            default:
                return super.onKeyUp(keyCode, event);
        }
    }

    // ===========================================================
    // Methods
    // ===========================================================

    public void setStopHandleTouchAndKeyEvents(boolean value) {
        mStopHandleTouchAndKeyEvents = value;
    }

    // ===========================================================
    // Inner and Anonymous Classes
    // ===========================================================

    private static void dumpMotionEvent(final MotionEvent event) {
        final String names[] = { "DOWN", "UP", "MOVE", "CANCEL", "OUTSIDE", "POINTER_DOWN", "POINTER_UP", "7?", "8?", "9?" };
        final StringBuilder sb = new StringBuilder();
        final int action = event.getAction();
        final int actionCode = action & MotionEvent.ACTION_MASK;
        sb.append("event ACTION_").append(names[actionCode]);
        if (actionCode == MotionEvent.ACTION_POINTER_DOWN || actionCode == MotionEvent.ACTION_POINTER_UP) {
            sb.append("(pid ").append(action >> MotionEvent.ACTION_POINTER_INDEX_SHIFT);
            sb.append(")");
        }
        sb.append("[");
        for (int i = 0; i < event.getPointerCount(); i++) {
            sb.append("#").append(i);
            sb.append("(pid ").append(event.getPointerId(i));
            sb.append(")=").append((int) event.getX(i));
            sb.append(",").append((int) event.getY(i));
            if (i + 1 < event.getPointerCount()) {
                sb.append(";");
            }
        }
        sb.append("]");
        Log.d(Cocos2dxGLSurfaceView.TAG, sb.toString());
    }
}
