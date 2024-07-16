#!/system/bin/sh
HERE="$(cd "$(dirname "$0")" && pwd)"
export ASAN_OPTIONS=log_to_syslog=true,allow_user_segv_handler=1,halt_on_error=true
ASAN_LIB=$(ls $HERE/libclang_rt.asan-*-android.so)
echo "--------------------------------------------------------------------------------"
echo "--- asan run app : $@ "
echo "--------------------------------------------------------------------------------"
if [ -f "$HERE/libc++_shared.so" ]; then
    # Workaround for https://github.com/android-ndk/ndk/issues/988.
    export LD_PRELOAD="$ASAN_LIB $HERE/libc++_shared.so"
else
    export LD_PRELOAD="$ASAN_LIB"
fi
#"$@"
exec "$@"

##!/system/bin/sh
#LD_HWASAN=1 exec "$@"

##!/system/bin/sh
#exec "$@"
