/***
 * crc.c
 * yanbrilley
 * 2023-08-06
***/

#include <stdio.h>

#include "crc.h"

typedef enum 
{
  REF_4BIT = 4,
  REF_5BIT = 5,
  REF_6BIT = 6,
  REF_7BIT = 7,
  REF_8BIT = 8,
  REF_16BIT = 16,
  REF_32BIT = 32

} REFLECTED_MODE;

uint32 reflected_data(uint32 data, REFLECTED_MODE mode)
{
  data = ((data & 0xffff0000) >> 16) | ((data & 0x0000ffff) << 16);
  data = ((data & 0xff00ff00) >> 8) | ((data & 0x00ff00ff) << 8);
  data = ((data & 0xf0f0f0f0) >> 4) | ((data & 0x0f0f0f0f) << 4);
  data = ((data & 0xcccccccc) >> 2) | ((data & 0x33333333) << 2);
  data = ((data & 0xaaaaaaaa) >> 1) | ((data & 0x55555555) << 1);
  
  switch (mode)
  {
    case REF_32BIT:
      return data;
    case REF_16BIT:
      return (data >> 16) & 0xffff;
    case REF_8BIT:
      return (data >> 24) & 0xff;
    case REF_7BIT:
      return (data >> 25) & 0x7f;
    case REF_6BIT:
      return (data >> 26) & 0x3f;
    case REF_5BIT:
      return (data >> 27) & 0x1f;
    case REF_4BIT:
      return (data >> 28) & 0x0f;
  }
  return 0;
}

uint32 check_crc32(uint32 poly, uint32 init, uint8 refIn, uint8 refOut, uint32 xorOut, const uint8 *buffer, uint32 length)
{
  uint32 i = 0;
  uint32 crc = init;
  
  while (length > 0) 
  {
    if (refIn == 1)
    {
      crc ^= reflected_data(*buffer, REF_8BIT) << 24;
    }
    else
    {
      crc ^= (*buffer) << 24;
    }
    buffer++;
    for (i = 0; i < 8; i++)
    {
      if (crc & 0x80000000)
      {
        crc <<= 1;
        crc ^= poly;
      }
      else 
      {
        crc <<= 1;
      }
    }
    length--;
  }

  if (refOut == 1)
  {
    crc = reflected_data(crc, REF_32BIT);
  }
  
  return crc ^ xorOut;
}

uint32 crc_check(CRC_Type crcType, const uint8 *buffer, uint32 length)
{
  check_crc32(crcType.poly, crcType.init, crcType.refIn, crcType.refOut, crcType.xorOut, buffer, length);
}
