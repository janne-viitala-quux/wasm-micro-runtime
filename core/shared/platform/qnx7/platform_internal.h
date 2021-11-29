/*
 * Copyright (C) 2020 Quux Oy  All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#ifndef _PLATFORM_INTERNAL_H
#define _PLATFORM_INTERNAL_H

#include <sys/platform.h>      // QNX -MUST COME FIRST!!
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdint.h> 
#include <string.h>            
#include <stdlib.h>            
#include <unistd.h>
#include <inttypes.h>          // PRIx64
#include <errno.h>
#include <pthread.h>           // including this does not declare pthread_t and others for vscode, wtf!
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <sys/mman.h>
#include <sys/time.h>


#ifdef __cplusplus
extern "C" {
#endif

#ifndef BH_PLATFORM_QNX7
#error "QNX7 not defined, build setup is corrupted".
#error "shared_plaform.cmake has not been included".
#endif

#ifndef bool
#define bool uint8_t
#endif

// we don't really need pthread, but (optional and not used) API using it is defined in platform_api_vmcore.h
typedef pthread_t korp_tid;
typedef pthread_mutex_t korp_mutex;
typedef pthread_cond_t korp_cond;
typedef pthread_t korp_thread;
#define BH_THREAD_DEFAULT_PRIORITY 0


#define madvise posix_madvise            // qnx mman.h
#define MADV_HUGEPAGE POSIX_MADV_NORMAL  // MADV_HUGEPAGE not in qnx

#ifdef __cplusplus
}
#endif

#endif /* end of _PLATFORM_INTERNAL_H */

