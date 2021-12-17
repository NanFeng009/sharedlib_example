# -----------------------------------------------------------------------------
# Function : parent-dir
# Arguments: 1: path
# Returns  : Parent dir or path of $1, with final separator removed.
# -----------------------------------------------------------------------------
parent-dir = $(patsubst %/,%,$(dir $(1:%/=%)))

# -----------------------------------------------------------------------------
# Macro    : my-dir
# Returns  : the directory of the current Makefile
# Usage    : $(my-dir)
# -----------------------------------------------------------------------------
my-dir = $(call parent-dir,$(lastword $(MAKEFILE_LIST)))


ROOT_DIR              := $(call my-dir)

MKFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
ABS_ROOT_DIR := $(patsubst %/,%,$(dir $(MKFILE_PATH)))

ifdef DEBUG
    COMMON_FLAGS += -ggdb -DDEBUG -UNDEBUG
else
    COMMON_FLAGS += -O2 -UDEBUG -DNDEBUG
endif


COMMON_FLAGS += -ffunction-sections -fdata-sections

# turn on compiler warnings as much as possible
COMMON_FLAGS += -Wall -Wextra -Winit-self -Wpointer-arith -Wreturn-type \
        -Waddress -Wsequence-point -Wformat-security \
        -Wmissing-include-dirs -Wfloat-equal -Wundef -Wshadow \
        -Wcast-align -Wconversion -Wredundant-decls

# additional warnings flags for C
COMMON_FLAGS += -Wjump-misses-init -Wstrict-prototypes -Wunsuffixed-float-constants



# Enable the security flags
COMMON_LDFLAGS := -Wl,-z,relro,-z,now,-z,noexecstack

