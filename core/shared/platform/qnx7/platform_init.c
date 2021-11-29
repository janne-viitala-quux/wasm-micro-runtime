/*
 * Copyright (C) 2019 Intel Corporation.  All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#include "platform_api_vmcore.h"

int
bh_platform_init()
{
    return 0;
}

void
bh_platform_destroy()
{
}

int
os_printf(const char *format, ...)
{
    int ret = 0;
    va_list ap;

    va_start(ap, format);
    ret += vprintf(format, ap);
    va_end(ap);

    return ret;
}

int
os_vprintf(const char *format, va_list ap)
{
    return vprintf(format, ap);
}

/*
ssize_t
preadv (int fd, const struct iovec *vector, int count, off_t offset)
{
  return 0; //TODO: implement preadv, return SYSCALL_CANCEL (preadv, fd, vector, count, LO_HI_LONG (offset));
}
*/