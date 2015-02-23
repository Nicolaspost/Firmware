/* Copyright 2014, Daniel Cohen
 * Copyright 2014, Esteban Volentini
 * Copyright 2014, Matias Giori
 * Copyright 2014, Franco Salinas
 * Copyright 2015, Mariano Cerdeiro
 * All rights reserved.
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

/** \brief CIAA Flash Posix Driver
 **
 ** Simulated Flash Driver for Posix for testing proposes
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Drivers CIAA Drivers
 ** @{ */
/** \addtogroup Flash Flash Drivers
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * DC           Daniel Cohen
 * EV           Esteban Volentini
 * MG           Matias Giori
 * FS           Franco Salinas
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20150201 v0.0.2 MaCe first implementation of flash simulation
 * 20141006 v0.0.1 EV   first initial version
 */

/*==================[inclusions]=============================================*/
#include "ciaaDriverFlash.h"
#include "ciaaDriverFlash_Internal.h"
#include "ciaaBlockDevices.h"

/*==================[macros and definitions]=================================*/
/** \brief Pointer to Devices */
typedef struct  {
   ciaaDevices_deviceType * const * const devices;
   uint8_t countOfDevices;
} ciaaDriverConstType;

#if (0)
typedef struct {
   int32_t minRead;
   int32_t maxRead;
   int32_t minWrite;
   int32_t maxWrite;
   int32_t blockSize;
} ciaaDriverFlash_flashType;
#endif
/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/
void ciaaDriverFlash_fileInit(ciaaDevices_deviceType * device, uint8_t index);

/*==================[internal data definition]===============================*/
#ifdef CIAADRVFLASH_ENABLE_FUNCIONALITY

/* Constant with filename of storage file maped to Flash 0 */
static const char ciaaDriverFlash_name0[] = CIAADRVFLASH_FILENAME_0;

/* Constant with filename of storage file maped to Flash 1 */
//static const char ciaaDriverFlash_name1[] = CIAADRVFLASH_FILENAME_1;

/* Constant with filenames of flash storage files */
static const char * ciaaDriverFlash_fileNames[] = {
   ciaaDriverFlash_name0
};

#endif /* CIAADRVFLASH_ENABLE_FUNCIONALITY */

#if (0)
/** \brief Flash 0 */
static const ciaaDriverFlash_flashType ciaaDriverFlash_flash0 = {
   CIAADRVFLASH_BLOCK_SIZE_0,       /** <= minRead 512 bytes */
   0,                               /** <= maxRead 0 -> no limit */
   CIAADRVFLASH_BLOCK_SIZE_0,       /** <= minWrite 512 bytes */
   0,                               /** <= maxWrite 0 -> no limit */
   CIAADRVFLASH_BLOCK_SIZE_0        /** <= blockSize 512 bytes */
};
#endif

static ciaaDevices_deviceType ciaaDriverFlash_device0 = {
   "hd/0",                          /** <= driver name */
   ciaaDriverFlash_open,            /** <= open function */
   ciaaDriverFlash_close,           /** <= close function */
   ciaaDriverFlash_read,            /** <= read function */
   ciaaDriverFlash_write,           /** <= write function */
   ciaaDriverFlash_ioctl,           /** <= ioctl function */
   ciaaDriverFlash_seek,            /** <= seek function is not provided */
   NULL,                            /** <= upper layer */
   (void*)&ciaaDriverFlash_flash0,  /** <= layer */
   NULL                             /** <= NULL no lower layer */
};

static ciaaDevices_deviceType * const ciaaFlashDevices[] = {
   &ciaaDriverFlash_device0
};

static ciaaDriverConstType const ciaaDriverFlashConst = {
   ciaaFlashDevices,
   1
};

/*==================[external data definition]===============================*/
/** \brief Flash 0 */
ciaaDriverFlash_flashType ciaaDriverFlash_flash0;

/*==================[internal functions definition]==========================*/
#ifdef CIAADRVFLASH_ENABLE_FUNCIONALITY
/** \brief Initialize file name */
void ciaaDriverFlash_fileInit(ciaaDevices_deviceType * device, uint8_t index)
{
   ciaaDriverFlash_flashType * flash = device->layer;

   flash->deviceName = ciaaDriverFlash_fileNames[index];
}
#endif /* CIAADRVFLASH_ENABLE_FUNCIONALITY */

/*==================[external functions definition]==========================*/
extern ciaaDevices_deviceType * ciaaDriverFlash_open(char const * path, ciaaDevices_deviceType * device, uint8_t const oflag)
{
   return device;
}

extern int32_t ciaaDriverFlash_close(ciaaDevices_deviceType const * const device)
{
   return -1;
}

extern int32_t ciaaDriverFlash_ioctl(ciaaDevices_deviceType const * const device, int32_t const request, void * param)
{
   int32_t ret = -1;

   return ret;
}

extern ssize_t ciaaDriverFlash_read(ciaaDevices_deviceType const * const device, uint8_t* buffer, size_t size)
{
   int32_t ret = -1;

   return ret;
}

extern ssize_t ciaaDriverFlash_write(ciaaDevices_deviceType const * const device, uint8_t const * const buffer, size_t const size)
{
   int32_t ret = -1;

   return ret;
}

extern int32_t ciaaDriverFlash_seek(ciaaDevices_deviceType const * const device, int32_t const offset, uint8_t const whence)
{
   return -1;
}

void ciaaDriverFlash_init(void)
{
   uint8_t loopi;

   /* add uart driver to the list of devices */
   for(loopi = 0; loopi < ciaaDriverFlashConst.countOfDevices; loopi++) {
      /* add each device */
      ciaaBlockDevices_addDriver(ciaaDriverFlashConst.devices[loopi]);

#ifdef CIAADRVFLASH_ENABLE_FUNCIONALITY
      /* initialize file name */
      ciaaDriverFlash_fileInit(ciaaDriverFlashConst.devices[loopi], loopi);
#endif /* CIAADRVFLASH_ENABLE_FUNCIONALITY */
   }
}

/*==================[interrupt handlers]=====================================*/
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

