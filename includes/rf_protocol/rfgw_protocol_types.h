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

#ifndef __RFGW_PROTOCOL_TYPES_H_
#define __RFGW_PROTOCOL_TYPES_H_

#include "middleware.h"

/**************** Typedefs ****************/

typedef uint16_t            rfgwp_pkt_type_t;
typedef uint16_t            rfgwp_pkt_len_t;

//typedef uint16_t            rfgwp_param_id_t;
typedef uint8_t             rfgwp_param_len_t;
typedef rfgwp_param_len_t   rfgwp_param_data_len_t;

typedef uint16_t            rfgwp_status_code_t;
typedef uint8_t             rfgwp_rf_device_type_t;
typedef uint32_t            rfgwp_rf_addr_t;
typedef uint8_t             rfgwp_rf_tx_power_t;

typedef uint16_t            rfgwp_bat_level_t;
typedef uint8_t             rfgwp_chg_status_t;

typedef uint16_t            rfgwp_tester_5va_adc_t;
typedef uint16_t            rfgwp_tester_5va_mv_t;

#endif /* __RFGW_PROTOCOL_TYPES_H_ */
