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

#ifndef __RF_HOST_DEVICE_BASE_H_
#define __RF_HOST_DEVICE_BASE_H_

#ifdef __cplusplus
extern "C" {
#endif

    #include "middleware.h"
    #include "nrfx_ppi.h"

    typedef void (* rfhdev_clock_hfclk_start_cb)( void );
    typedef void (* rfhdev_clock_hfclk_stop_cb)( void );
    typedef nrfx_err_t (* rfhdev_ppi_channel_alloc_cb)( nrf_ppi_channel_t * p_channel );

    /*
     * Request the MCU should not go to sleep in this iteration and follow immediately with the next one.
     */
    typedef void (* rfhdev_sleep_postpone_cb)( void );

    typedef uint32_t (* rfhdev_millis_request_cb)( void );

    typedef struct
    {
        rfhdev_clock_hfclk_start_cb clock_hfclk_start_cb;
        rfhdev_clock_hfclk_stop_cb clock_hfclk_stop_cb;
        rfhdev_ppi_channel_alloc_cb ppi_channel_alloc_cb;

        rfhdev_sleep_postpone_cb sleep_postpone_cb;

        rfhdev_millis_request_cb millis_request_cb;
    } rfhdev_config_t;

    typedef result_t (* rfhdev_init_fn)( const rfhdev_config_t * p_config );

    typedef struct
    {
        char mark[16];
        rfhdev_init_fn init_fn;
    } rfhdev_api_t;

#ifdef __cplusplus
}
#endif

#endif /* __RF_HOST_DEVICE_BASE_H_ */
