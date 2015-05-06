curdir := $(shell pwd)

lowercase = $(shell echo $1 | tr A-Z a-z)

sys_name := $(shell uname -s)
sys_name_lower := $(call lowercase,${sys_name})
sys_machine := $(shell uname -m)
sys_fullname := ${sys_name_lower}-${sys_machine}

v8_base_url := https://github.com/phantasien/v8/releases/download
v8_version := 3.27.7

ndk_bin := ${ANDROID_NDK_ROOT}/toolchains/arm-linux-androideabi-4.8/prebuilt/${sys_fullname}/bin
ndk_base_url := http://dl.google.com/android/ndk


all: deps jni-build
	@ant debug

jni-build: v8-arm
	@V8_HOME=${curdir}/deps/v8 ndk-build

deps: deps/v8

deps/v8: 
	@mkdir -p deps
	@git clone --depth=1 https://github.com/phantasien/v8 deps/v8
	@make -C deps/v8 builddeps

v8-arm:
	@make -C deps/v8 android_arm.release -j8
	@make  CC=${ndk_bin}/arm-linux-androideabi-gcc \
	       CXX={ndk_bin}/arm-linux-androideabi-g++ \
	       AR=${ndk_bin}/arm-linux-androideabi-ar \
	       RANLIB=${ndk_bin}/arm-linux-androideabi-ranlib \
	       android_arm.release library=shared snapshot=on i18nsupport=off werror=no -j8
