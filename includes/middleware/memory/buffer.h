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

#ifndef __BUFFER_H_
#define __BUFFER_H_

#ifdef __cplusplus
extern "C" {
#endif

    #include "buffer_base.h"
    #include "rf_host_device.h"

    #define BUFFER_API_BASE                                     ((buffer_api_t *)RFHDEV_API_BASE_GET(BUFFER_API_BASE_ID))

    #define buffer_get_read_pos( p_buffer )                     BUFFER_API_BASE->get_read_pos_fn( p_buffer )
    #define buffer_get_write_pos( p_buffer )                    BUFFER_API_BASE->get_write_pos_fn( p_buffer )
    #define buffer_get_loadsize( p_buffer )                     BUFFER_API_BASE->get_loadsize_fn( p_buffer )
    #define buffer_get_freesize( p_buffer )                     BUFFER_API_BASE->get_freesize_fn( p_buffer )
    #define buffer_get_max_loadsize( p_buffer )                 BUFFER_API_BASE->get_max_loadsize_fn( p_buffer )

    #define buffer_update_read_pos( p_buffer, len )             BUFFER_API_BASE->update_read_pos_fn( p_buffer, len )

    #define buffer_get( p_buffer, p_data, len )                 BUFFER_API_BASE->get_fn( p_buffer, p_data, len )
    #define buffer_get_from_position( p_buffer, from_position, p_data, len ) BUFFER_API_BASE->get_from_position_fn( p_buffer, from_position, p_data, len )

    #define buffer_calc_new_pos( p_buffer, old_pos, offset )    BUFFER_API_BASE->calc_new_pos_fn( p_buffer, old_pos, offset )

#ifdef __cplusplus
}
#endif

#endif /* __BUFFER_H_ */
