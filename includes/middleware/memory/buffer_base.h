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

#ifndef __BUFFER_BASE_H_
#define __BUFFER_BASE_H_

    #include "middleware.h"

    /**********************************************************/
    /*                         Types                          */
    /**********************************************************/

    typedef struct buffer buffer_t;

    /**********************************************************/
    /*                        Handlers                        */
    /**********************************************************/

    typedef uint16_t (* buffer_get_read_pos_fn)( buffer_t * p_buffer );
    typedef uint16_t (* buffer_get_write_pos_fn)( buffer_t * p_buffer );
    typedef uint16_t (* buffer_get_loadsize_fn)( buffer_t * p_buffer );
    typedef uint16_t (* buffer_get_freesize_fn)( buffer_t * p_buffer );
    typedef uint16_t (* buffer_get_max_loadsize_fn)( buffer_t * p_buffer );

    typedef void (* buffer_update_read_pos_fn)( buffer_t * p_buffer, int16_t len );

    typedef result_t (* buffer_get_fn)( buffer_t * p_buffer, uint8_t * p_data, uint16_t len );
    typedef result_t (* buffer_get_from_position_fn)( buffer_t * p_buffer, uint16_t from_position, uint8_t * p_data, uint16_t len );

    typedef uint16_t (* buffer_calc_new_pos_fn)( const buffer_t * p_buffer, uint16_t old_pos, int16_t offset );

    typedef struct
    {
        char mark[16];

        buffer_get_read_pos_fn get_read_pos_fn;
        buffer_get_write_pos_fn get_write_pos_fn;
        buffer_get_loadsize_fn get_loadsize_fn;
        buffer_get_freesize_fn get_freesize_fn;
        buffer_get_max_loadsize_fn get_max_loadsize_fn;

        buffer_update_read_pos_fn update_read_pos_fn;

        buffer_get_fn get_fn;
        buffer_get_from_position_fn get_from_position_fn;

        buffer_calc_new_pos_fn calc_new_pos_fn;
    } buffer_api_t;

#endif /* __BUFFER_BASE_H_ */
