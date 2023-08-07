/**
 * crc.h
 * yanbrilley
 * 2023-08-06
***/

#ifndef __CRC_H__
#define __CRC_H__

#include <stdio.h>
#include "common.h"

typedef struct 
{
  uint8 width;
  uint32 poly;
  uint32 init;
  uint8 refIn;
  uint8 refOut;
  uint32 xorOut;
} CRC_Type;

uint32 crc_check(CRC_Type crcType, const uint8 *buffer, uint32 length);


#endif
