/**
 * yba_crc.h
 * yanbrilley
 * 2023-08-06
***/

#ifndef __CRC_H__
#define __CRC_H__

typedef struct 
{
  YBA_UINT8 width;
  YBA_UINT32 poly;
  YBA_UINT32 init;
  YBA_UINT8 refIn;
  YBA_UINT8 refOut;
  YBA_UINT32 xorOut;
} CRC_Type;

YBA_UINT32 crc_check(CRC_Type crcType, const YBA_UINT8 *buffer, YBA_UINT32 length);


#endif
