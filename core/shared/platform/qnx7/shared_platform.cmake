# Copyright (C) 2020 Quux Oy. All rights reserved.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

set (PLATFORM_SHARED_DIR ${CMAKE_CURRENT_LIST_DIR})

# Note: definition must not be empty, or silly qnx asm choces on it
add_definitions(-DBH_PLATFORM_QNX7=1)

# Problem: empty libiwasm_EXPORTS gets added to definitions without trailing =, which silly qnx
#          asm chokes on
#add_definitions(-Dlibiwasm_EXPORTS=)

# Problem: this is defined somewhere else, can't define it here. TODO: etsi missä ja mistä...
#add_definitions(-Diwasm_EXPORTS=)


include_directories(${PLATFORM_SHARED_DIR})
include_directories(${PLATFORM_SHARED_DIR}/../include)

include (${CMAKE_CURRENT_LIST_DIR}/../common/posix/platform_api_posix.cmake)

file (GLOB_RECURSE source_all ${PLATFORM_SHARED_DIR}/*.c)

set (PLATFORM_SHARED_SOURCE ${source_all} ${PLATFORM_COMMON_POSIX_SOURCE})

file (GLOB header ${PLATFORM_SHARED_DIR}/../include/*.h)
LIST (APPEND RUNTIME_LIB_HEADER_LIST ${header})
