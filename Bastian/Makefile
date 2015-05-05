curdir := $(shell pwd)

lowercase = $(shell echo $1 | tr A-Z a-z)

sys_name := $(shell uname -s)
sys_name_lower := $(call lowercase,${sys_name})
sys_machine := $(shell uname -m)
sys_fullname := ${sys_name_lower}-${sys_machine}

v8_base_url := https://github.com/phantasien/v8/releases/download
v8_version := 3.27.7


all: deps jni-build
	@ant release

jni-build:
	@V8_HOME=${curdir}/deps/v8 ndk-build

deps: deps/v8

deps/v8: deps/v8.tar.bz2
	@tar -C deps -jxf deps/v8.tar.bz2
	@mv deps/v8-${v8_version}-${sys_fullname} deps/v8

deps/v8.tar.bz2:
	@mkdir -p deps
	@echo ${sys_name}
	@curl -L ${v8_base_url}/${v8_version}/v8-${v8_version}-${sys_fullname}.tar.bz2 > deps/v8.tar.bz2
