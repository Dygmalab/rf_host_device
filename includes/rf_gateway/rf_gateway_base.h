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

#ifndef __RF_GATEWAY_BASE_H_
#define __RF_GATEWAY_BASE_H_

    #include "middleware.h"

    typedef enum
    {
        RFGW_PIPE_ID_1 = 1,
        RFGW_PIPE_ID_2,
        RFGW_PIPE_ID_3,
        RFGW_PIPE_ID_4,
        RFGW_PIPE_ID_5,
        RFGW_PIPE_ID_6,
        RFGW_PIPE_ID_7,
    } rfgw_pipe_id_t;

    typedef enum
    {
        RFGW_TX_POWER_N40_DBM = 0xD8,    /* -40 dBm Transmit Power */
        RFGW_TX_POWER_N20_DBM = 0xEC,    /* -20 dBm Transmit Power */
        RFGW_TX_POWER_N16_DBM = 0xF0,    /* -16 dBm Transmit Power */
        RFGW_TX_POWER_N12_DBM = 0xF4,    /* -12 dBm Transmit Power */
        RFGW_TX_POWER_N8_DBM = 0xF8,    /* -8 dBm Transmit Power */
        RFGW_TX_POWER_N4_DBM = 0xFC,    /* -4 dBm Transmit Power */
        RFGW_TX_POWER_0_DBM = 0x00,    /* 0 dBm Transmit Power (Default) */
        RFGW_TX_POWER_2_DBM = 0x02,    /* 2 dBm Transmit Power */
        RFGW_TX_POWER_3_DBM = 0x03,    /* 3 dBm Transmit Power */
        RFGW_TX_POWER_4_DBM = 0x04,    /* 4 dBm Transmit Power */
        RFGW_TX_POWER_5_DBM = 0x05,    /* 5 dBm Transmit Power */
        RFGW_TX_POWER_6_DBM = 0x06,    /* 6 dBm Transmit Power */
        RFGW_TX_POWER_7_DBM = 0x07,    /* 7 dBm Transmit Power */
        RFGW_TX_POWER_8_DBM = 0x08,    /* 8 dBm Transmit Power */
    } rfgw_tx_power_t;

/**********************************************************/
/*                        Handlers                        */
/**********************************************************/

    typedef void (* rfgw_pipe_connection_cb)( rfgw_pipe_id_t );
    typedef void (* rfgw_pipe_disconnection_cb)( rfgw_pipe_id_t );

    typedef result_t (* rfgw_init_host_fn)( void );

    typedef void (* rfgw_cb_pipe_connection_set_fn)( rfgw_pipe_connection_cb );
    typedef void (* rfgw_cb_pipe_disconnection_set_fn)( rfgw_pipe_disconnection_cb );

    typedef uint32_t (* rfgw_addr_suggest_fn)( void );

    typedef result_t (* rfgw_tx_power_set_fn)( rfgw_tx_power_t tx_power );
    typedef rfgw_tx_power_t (* rfgw_tx_power_get_fn)( void );
    typedef result_t (* rfgw_addr_set_fn)( uint32_t addr );
    typedef uint32_t (* rfgw_addr_get_fn)( void );

    typedef result_t (* rfgw_enable_fn)( void );
    typedef result_t (* rfgw_disable_fn)( void );

    typedef result_t (* rfgw_pipe_open_fn)( rfgw_pipe_id_t pipe_id );
    typedef result_t (* rfgw_pipe_send_fn)( rfgw_pipe_id_t pipe_id, uint8_t * p_data, uint16_t data_len );
    typedef result_t (* rfgw_pipe_recv_fn)( rfgw_pipe_id_t pipe_id, uint8_t * p_data, uint16_t data_len );
    typedef result_t (* rfgw_pipe_recv_buffer_get_fn)( rfgw_pipe_id_t pipe_id, buffer_t ** pp_buffer_recv );
    typedef result_t (* rfgw_pipe_get_send_freesize_fn)( rfgw_pipe_id_t pipe_id, uint16_t * p_freesize );
    typedef result_t (* rfgw_pipe_get_recv_loadsize_fn)( rfgw_pipe_id_t pipe_id, uint16_t * p_loadsize );

    typedef void (* rfgw_api_poll_fn)( void );

    typedef struct
    {
        char mark[16];
        rfgw_init_host_fn init_host_fn;

        rfgw_cb_pipe_connection_set_fn cb_pipe_connection_set_fn;
        rfgw_cb_pipe_disconnection_set_fn cb_pipe_disconnection_set_fn;

        rfgw_addr_suggest_fn addr_suggest_fn;

        rfgw_tx_power_set_fn tx_power_set_fn;
        rfgw_tx_power_get_fn tx_power_get_fn;
        rfgw_addr_set_fn addr_set_fn;
        rfgw_addr_get_fn addr_get_fn;

        rfgw_enable_fn enable_fn;
        rfgw_disable_fn disable_fn;

        rfgw_pipe_open_fn pipe_open_fn;
        rfgw_pipe_send_fn pipe_send_fn;
        rfgw_pipe_recv_fn pipe_recv_fn;
        rfgw_pipe_recv_buffer_get_fn pipe_recv_buffer_get_fn;
        rfgw_pipe_get_send_freesize_fn pipe_get_send_freesize_fn;
        rfgw_pipe_get_recv_loadsize_fn pipe_get_recv_loadsize_fn;

        rfgw_api_poll_fn poll_fn;
    } rfgw_api_t;

#endif /* __RF_GATEWAY_BASE_H_ */
