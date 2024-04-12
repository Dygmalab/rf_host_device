/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2024 JayLabs s.r.o.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __RF_HOST_DEVICE_H_
#define __RF_HOST_DEVICE_H_

#ifdef __cplusplus
extern "C" {
#endif

    #define RFHDEV_API_BASE_ADDRESS       0x00027200
    #define RFHDEV_API_BASE_GET(api_id)   (((uint32_t *)RFHDEV_API_BASE_ADDRESS)[api_id])

    #define RFHDEV_API_BASE_ID          0
    #define BUFFER_API_BASE_ID          1
    #define CRC32_API_BASE_ID           2
    #define RFGW_API_BASE_ID            3

    #include "middleware.h"
    #include "rf_host_device/rf_host_device_base.h"
    #include "rf_gateway/rf_gateway.h"

    /**********************************************************/
    /*                          API                           */
    /**********************************************************/

    #define RFHDEV_API_BASE               ((rfhdev_api_t *)RFHDEV_API_BASE_GET(RFHDEV_API_BASE_ID))

    #define rfhdev_init( p_config )       RFHDEV_API_BASE->init_fn( p_config )

#ifdef __cplusplus
}
#endif

#endif /* __RF_HOST_DEVICE_H_ */
