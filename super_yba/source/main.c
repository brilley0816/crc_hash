/*****
 * main function
 * yanbrilley
 * 2023-08-23
 * version 1.0
 ****/
#include <stdio.h>

#include "yba_common.h"
#include "yba_crc.h"

#define LENGTH 8

const YBA_CHAR data[3][LENGTH] = 
{
  {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08},
  {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80},
  {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f}
};

typedef struct 
{
  CRC_Type crcType;
  YBA_UINT32 result[3];
} CRC_Test;

void main()
{
  YBA_UINT8 i = 0;
  YBA_UINT16 a = 0xff00;
  YBA_UINT32 b = 0x80000000;

  printf("num1 = %d\n", i);
  printf("num2 = %d\n", a);
  printf("num3 = %d\n", b);
  printf("num4 = 0x%x\n", b);

  CRC_Test crc32 = {{32, 0x4c11db7, 0xffffffff, 0, 0, 0x00000000},{0x14dbbdd8, 0x6509b4b6, 0xcb09d294}};
  
  for (i = 0; i < 3; i++) 
  {
    printf("%08x\t%08x\r\n", crc_check(crc32.crcType, data[i], LENGTH), crc32.result[i]);
  }
}

