/* Copyright 2015, Daniel Cohen
 * Copyright 2015, Esteban Volentini
 * Copyright 2015, Matias Giori
 * Copyright 2015, Franco Salinas
 * Copyright 2015, Pablo Alcorta
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief This file implements functions to format
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * DC           Daniel Cohen
 * EV           Esteban Volentini
 * MG           Matias Giori
 * FS           Franco Salinas
 * PA           Pablo Alcorta
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20151019 v0.0.1  PA  first initial version
 */
/*==================[inclusions]=============================================*/
#include "ciaaLibs_format.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

void ciaaLibs_SetByte(uint8_t *config_buffer,uint8_t ptr, uint32_t value)
{
   config_buffer[ptr]= value;
}

void ciaaLibs_SetUint16(uint8_t *config_buffer,uint8_t ptr, uint32_t value)
{
   config_buffer[ptr]=value >> 8;
   config_buffer[ptr+1]=value;
}

void ciaaLibs_SetUint24(uint8_t *config_buffer,uint8_t ptr, uint32_t value)
{
   config_buffer[ptr]=value >> 16;
   config_buffer[ptr+1]=value >> 8;
   config_buffer[ptr+2]=value;
}

void ciaaLibs_SetUint32(uint8_t *config_buffer,uint8_t ptr, uint32_t value)
{
   config_buffer[ptr]=value >> 24;
   config_buffer[ptr+1]=value >> 16;
   config_buffer[ptr+2]=value >> 8;
   config_buffer[ptr+3]=value;
}

/*==================[external functions definition]==========================*/

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

