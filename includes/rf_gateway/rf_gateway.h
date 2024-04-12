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

#ifndef __RF_GATEWAY_H_
#define __RF_GATEWAY_H_

#ifdef __cplusplus
extern "C" {
#endif

    #include "rf_host_device.h"
    #include "rf_gateway_base.h"

    #define RFGW_API_BASE               ((rfgw_api_t *)RFHDEV_API_BASE_GET(RFGW_API_BASE_ID))

    #define rfgw_host_init()                                        RFGW_API_BASE->init_host_fn()

    #define rfgw_cb_pipe_connection_set(pipe_connection_cb)         RFGW_API_BASE->cb_pipe_connection_set_fn(pipe_connection_cb)
    #define rfgw_cb_pipe_disconnection_set(pipe_disconnection_cb)   RFGW_API_BASE->cb_pipe_disconnection_set_fn(pipe_disconnection_cb)

    #define rfgw_addr_suggest()                                     RFGW_API_BASE->addr_suggest_fn()

    #define rfgw_tx_power_set(tx_power)                             RFGW_API_BASE->tx_power_set_fn(tx_power)
    #define rfgw_tx_power_get()                                     RFGW_API_BASE->tx_power_get_fn()
    #define rfgw_addr_set(addr)                                     RFGW_API_BASE->addr_set_fn(addr)
    #define rfgw_addr_get()                                         RFGW_API_BASE->addr_get_fn()

    #define rfgw_enable()                                           RFGW_API_BASE->enable_fn()
    #define rfgw_disable()                                          RFGW_API_BASE->disable_fn()

    #define rfgw_pipe_open( pipe_id )                               RFGW_API_BASE->pipe_open_fn( pipe_id )
    #define rfgw_pipe_send( pipe_id, p_data, data_len )             RFGW_API_BASE->pipe_send_fn( pipe_id, p_data, data_len )
    #define rfgw_pipe_recv( pipe_id, p_data, data_len )             RFGW_API_BASE->pipe_recv_fn( pipe_id, p_data, data_len )
    #define rfgw_pipe_recv_buffer_get( pipe_id, pp_buffer_recv )    RFGW_API_BASE->pipe_recv_buffer_get_fn( pipe_id, pp_buffer_recv )
    #define rfgw_pipe_get_send_freesize( pipe_id, p_freesize )      RFGW_API_BASE->pipe_get_send_freesize_fn( pipe_id, p_freesize )
    #define rfgw_pipe_get_recv_loadsize( pipe_id, p_loadsize )      RFGW_API_BASE->pipe_get_recv_loadsize_fn( pipe_id, p_loadsize )

    #define rfgw_poll()                 RFGW_API_BASE->poll_fn()

#ifdef __cplusplus
}
#endif

#endif /* __RF_GATEWAY_H_ */
