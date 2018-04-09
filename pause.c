/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        Bitmap Converter for emWin V5.30.                           *
*        Compiled Jul  1 2015, 10:49:26                              *
*                                                                    *
*        (c) 1998 - 2015 Segger Microcontroller GmbH & Co. KG        *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: pause                                                 *
* Dimensions:  50 * 50                                               *
* NumColors:   256                                                   *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmpause;

/*********************************************************************
*
*       Palette
*
*  Description
*    The following are the entries of the palette table.
*    The entries are stored as a 32-bit values of which 24 bits are
*    actually used according to the following bit mask: 0xBBGGRR
*
*    The lower   8 bits represent the Red   component.
*    The middle  8 bits represent the Green component.
*    The highest 8 bits represent the Blue  component.
*/
static GUI_CONST_STORAGE GUI_COLOR _Colorspause[] = {
  0x1A9BFD, 0xFDFDFD, 0x16A3FD, 0x18A2FD,
  0x1D95FD, 0x12ABFD, 0x2192FD, 0x0EB1FE,
  0x248DFC, 0x8ED9FE, 0xFAFDFE, 0x85D9FD,
  0xB1E1FE, 0xC2E6FE, 0x0EAEFE, 0xA2DDFE,
  0xBEE4FE, 0xACE0FE, 0x2898FC, 0x54C8FD,
  0x81CAFE, 0x1BABFB, 0x09BAFE, 0x7DC5FD,
  0x10B1FD, 0x22A2FB, 0x22ABFA, 0x95DCFE,
  0xC8E8FE, 0xCAF1FD, 0xAEDCFE, 0xC5E1FE,
  0x30A5FA, 0x2BB3FB, 0x49C4FD, 0x61C1FE,
  0x96D9FE, 0x9ADAFE, 0x9BDDFE, 0x249CFC,
  0x06C1FD, 0xB9DDFE, 0xB6E4FE, 0xC7E8FE,
  0x54C3FE, 0x5BC3FE, 0x6AC2FE, 0x9FD4FE,
  0xA4D9FE, 0xA7DDFE, 0xB4DDFE, 0xA7E0FE,
  0xB8E1FE, 0xCAE5FE, 0x5ABAFE, 0x8CCCFE,
  0x60C9FD, 0x6DC9FC, 0x7CC8FD, 0x7DD1FC,
  0x82D2FC, 0x8DD2FD, 0xA9D9FE, 0xBEE2FE,
  0x359DFB, 0x40CBFD, 0x91CDFE, 0x85D3FC,
  0x94D1FE, 0x99D4FE, 0xA6D5FE, 0xC1E1FE,
  0x5AD8FF, 0x75C3FE, 0x76CCFD, 0x81C1FD,
  0x9AD1FE, 0xB2D9FE, 0xB6E1FE, 0x49BAFE,
  0x54BBFD, 0x68BCFE, 0x59C9FE, 0x72C0FE,
  0x73CBFD, 0x85D4FC, 0x92D6FE, 0x91D9FE,
  0xACD6FE, 0xC1DEFE, 0xD5F4FD, 0x298CFB,
  0x2995FC, 0x2A98FB, 0x75B9FD, 0x3DD4FD,
  0x7AC5FE, 0x7AC9FE, 0x81BDFD, 0x80C5FD,
  0xDAF5FD, 0x3592FA, 0x3094FC, 0x3899FB,
  0x32A2FB, 0x3BB5FC, 0x61BAFE, 0x3DC2FD,
  0x96CEFE, 0xB6DAFE, 0xDEF7FE, 0xE1F7FE,
  0x2E95FB, 0x2C95FC, 0x3996FA, 0x1BB1FB,
  0x22B3FB, 0x2BBBFF, 0x34B3FC, 0x43A9FD,
  0x49ACFD, 0x55A3FD, 0x52AEFD, 0x65B4FD,
  0x08C3FD, 0x41C2FE, 0x41D2FD, 0x45D8FF,
  0x50D8FF, 0x64C9FC, 0x7ACCFD, 0x65D8FE,
  0x6BD8FE, 0x70D9FE, 0x77DAFD, 0x79DAFD,
  0x72E0FD, 0x9CCBFD, 0x8DD6FE, 0x89DBFD,
  0x95E2FD, 0xE7F3FE, 0xEFF9FC, 0xF4FCFD,
  0xF9FAFA, 0x3292FA, 0x3193FC, 0x30A7FC,
  0x3EBAFD, 0x4CB2FE, 0x50B5FE, 0x66BFFE,
  0x4BD6FD, 0x4BD8FE, 0x6CC3FE, 0x6ECAFA,
  0x7CCCFE, 0x9AC8FC, 0x8BD2FD, 0x89D5FD,
  0xA8DDFE, 0x2991FC, 0x2A9EFC, 0x3493FC,
  0x3F96FC, 0x19BDFE, 0x2CA3FC, 0x2AAEFA,
  0x34A1FB, 0x36A5F9, 0x4F9FFB, 0x48ABFD,
  0x52A3FB, 0x55A4FB, 0x44B3FE, 0x40BCFE,
  0x56B1FE, 0x57B7FD, 0x59B2FE, 0x5DB2FD,
  0x58B6FD, 0x60B4FD, 0x6AB6FD, 0x6EB8FC,
  0x77B6FD, 0x79B7FD, 0x7ABAFD, 0x7DBBFD,
  0x13C9FD, 0x4DC8FF, 0x64CEFE, 0x75C5FE,
  0x70CBF9, 0x74CAFD, 0x73D3FD, 0x79E1FE,
  0x7EE1FE, 0x87C7FE, 0x85C9FE, 0x82D4FC,
  0x90D1FE, 0x9CDEFE, 0xA3CEFE, 0xA0D2FE,
  0xA0D6FE, 0xA8D6FE, 0xACD9FE, 0x82E1FE,
  0x89E1FE, 0x8DE1FE, 0x91E2FE, 0xA5E0FA,
  0xA8E1FA, 0xC6E4FE, 0x2991FB, 0x2D92FA,
  0x3195FB, 0x3496FB, 0x3298FB, 0x2DAFF7,
  0x39A5FD, 0x31ACFC, 0x39ABFD, 0x31BDFE,
  0x4A9CFB, 0x4A9CFC, 0x60BCFE, 0x0CC9FD,
  0x1CCCFD, 0x37C1FD, 0x26D1FE, 0x2DD1FE,
  0x33D2FE, 0x5DCBFE, 0x63CEFE, 0x6DCCF9,
  0x68CFFE, 0x71CCFC, 0x6DD0FD, 0x63DDFD,
  0x67DEFD, 0x6EDFFD, 0x79D0FC, 0x7AD6FE,
  0x7DD8FE, 0x8BCDFE, 0x99C8FB, 0x82D8FD,
  0x95D5FE, 0x9CD9FF, 0xA9DFF7, 0xA4DDFB,
  0x9CE0FD, 0xEAF4F9, 0xF2FBFD, 0xF9FCFB
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palpause = {
  256,  // Number of entries
  0,    // No transparency
  &_Colorspause[0]
};

static GUI_CONST_STORAGE unsigned char _acpause[] = {
  0x8D, 0x89, 0xAD, 0x72, 0x72, 0x67, 0x67, 0x40, 0x40, 0x40, 0x40, 0xA8, 0xA8, 0xA8, 0x68, 0x68, 0x20, 0x20, 0x20, 0x20, 0x20, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x20, 0x20, 0x20, 0xA9, 0xA9, 0x68, 0x68, 0x68, 0xA8, 0xA8, 0x40, 0x40, 0x40, 
        0x67, 0x67, 0x67, 0x72, 0x72, 0xAD, 0x89, 0x8D,
  0x9D, 0xA4, 0x79, 0xB8, 0x62, 0x62, 0x4B, 0x4B, 0x4B, 0x4B, 0x63, 0x17, 0x17, 0x17, 0x3A, 0x17, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A, 0x17, 0x17, 0x17, 0x17, 0x17, 0x63, 0x4B, 0x4B, 
        0x4B, 0x4B, 0x62, 0x62, 0xB8, 0x79, 0xA4, 0x9D,
  0xAA, 0x79, 0xCA, 0x1F, 0x35, 0x35, 0x35, 0x35, 0x35, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x35, 
        0x35, 0x35, 0x35, 0x35, 0x1F, 0xCA, 0x79, 0xAA,
  0x65, 0xB9, 0x59, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0xD5, 0xD5, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0xD5, 0xD5, 0xD5, 
        0xD5, 0x1F, 0xD5, 0x1F, 0x1F, 0x59, 0xB9, 0x65,
  0x91, 0x62, 0x59, 0x59, 0x47, 0x47, 0x47, 0x47, 0x47, 0x3F, 0x3F, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x3F, 0x3F, 0x47, 
        0x47, 0x47, 0x47, 0x59, 0x59, 0x59, 0x62, 0x65,
  0x92, 0xBB, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x4E, 0x2A, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x29, 
        0x29, 0x29, 0x3F, 0x29, 0x29, 0x29, 0xBB, 0x91,
  0x92, 0xBA, 0x6D, 0x6D, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x4E, 0x0C, 0x0C, 0x0C, 0x32, 0x32, 
        0x32, 0x32, 0x6D, 0x32, 0x6D, 0x6D, 0xBA, 0x92,
  0x66, 0x5E, 0x4D, 0x4D, 0x4D, 0x4D, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 
        0x1E, 0x1E, 0x4D, 0x4D, 0x4D, 0x4D, 0x5E, 0x66,
  0x66, 0x5E, 0x58, 0x58, 0x58, 0x58, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0xA0, 0x31, 0x31, 0x31, 0x31, 0x31, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0xA0, 0xA0, 0x3E, 0x3E, 0x3E, 
        0x3E, 0xCE, 0xCE, 0x58, 0x58, 0x58, 0x5E, 0x66,
  0x66, 0x5E, 0xCD, 0x46, 0x46, 0x46, 0x46, 0x46, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x30, 0x30, 0x30, 0x30, 0x30, 
        0x30, 0xCD, 0x46, 0x46, 0x46, 0xCD, 0x5E, 0xD8,
  0xDA, 0xB7, 0xCB, 0x2F, 0x2F, 0x2F, 0x2F, 0xCC, 0xCC, 0x2F, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x26, 0xC9, 0xC9, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0xF9, 0x2F, 0x2F, 
        0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0xCB, 0xB7, 0xD9,
  0x70, 0xB6, 0x4C, 0x4C, 0x4C, 0x4C, 0x45, 0x45, 0x45, 0x45, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x45, 0x45, 0x45, 
        0x45, 0x45, 0x4C, 0x4C, 0x4C, 0x4C, 0xB6, 0x70,
  0x71, 0x7B, 0x6C, 0x6C, 0x44, 0x44, 0x44, 0x44, 0x44, 0xF8, 0x56, 0x56, 0x56, 0x56, 0x57, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x57, 0x57, 0x56, 0x56, 0x56, 0x56, 0x44, 
        0x44, 0x44, 0x44, 0x6C, 0x6C, 0x6C, 0x7B, 0x71,
  0x71, 0x7B, 0x42, 0x42, 0x42, 0x42, 0x42, 0xC8, 0xC8, 0x3D, 0x3D, 0x3D, 0x8A, 0x8A, 0x09, 0x09, 0x09, 0x8A, 0x09, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x8A, 0x3D, 0x3D, 0x3D, 0x3D, 
        0x3D, 0xC8, 0x42, 0x42, 0x42, 0x42, 0x7B, 0x71,
  0x5D, 0xB5, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x3D, 0x9E, 0x43, 0x43, 0x55, 0x55, 0x55, 0x55, 0x09, 0x09, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x55, 0x9F, 0x55, 0x55, 0x43, 0x43, 0x9E, 0x9E, 
        0xF5, 0x37, 0x37, 0x37, 0x37, 0x37, 0xB5, 0x5D,
  0x5D, 0xB3, 0xC5, 0xC6, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x3C, 0x3C, 0x3C, 0x3C, 0x3B, 0xD3, 0xFD, 0x8E, 0x8E, 0x8E, 0x8F, 0x64, 0x8C, 0x87, 0x87, 0x87, 0x87, 0x8C, 0x64, 0x8F, 0x8F, 0x8F, 0xFE, 0x8E, 0xD4, 0x43, 0x43, 0x43, 0x43, 0x3C, 0x14, 0x14, 
        0x14, 0x14, 0x14, 0x14, 0xC6, 0xC5, 0xB3, 0x5D,
  0x5D, 0xB2, 0x63, 0x63, 0x14, 0x14, 0x14, 0x9C, 0x9C, 0x9C, 0x3B, 0x3B, 0x3B, 0x3B, 0x3C, 0xFA, 0x90, 0x01, 0x01, 0x01, 0x01, 0x6F, 0x8C, 0x86, 0x86, 0x86, 0x86, 0x8C, 0x6F, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xD4, 0x9F, 0xC7, 0x3C, 0x3C, 0x9C, 0x9C, 0x14, 
        0x14, 0x14, 0x14, 0x14, 0x63, 0x63, 0xB2, 0x5D,
  0x5D, 0xB0, 0x60, 0x60, 0x60, 0x61, 0x61, 0x61, 0x4A, 0x4A, 0x4A, 0x4A, 0xF2, 0x3B, 0x3C, 0xFB, 0x01, 0x01, 0x01, 0x01, 0x01, 0x6F, 0xD2, 0x85, 0x85, 0x85, 0x85, 0xD2, 0x6F, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xD4, 0x57, 0x9F, 0x3C, 0x3B, 0x4A, 0x4A, 0x4A, 
        0x61, 0x61, 0x61, 0x60, 0x60, 0x60, 0xB0, 0x5D,
  0x12, 0x7A, 0x49, 0x49, 0x49, 0x49, 0xBF, 0xC1, 0x54, 0x54, 0x54, 0x54, 0x4A, 0x3B, 0x3B, 0x25, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x6E, 0xD1, 0x84, 0x84, 0x84, 0x84, 0xD1, 0x6F, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFC, 0xC7, 0x43, 0x3B, 0x4A, 0x54, 0x54, 0x54, 
        0xC1, 0xBF, 0x49, 0x49, 0x49, 0x49, 0x7A, 0x12,
  0x12, 0x7A, 0x53, 0x53, 0x49, 0x9A, 0x9A, 0x39, 0x39, 0x39, 0x39, 0x9B, 0xC0, 0xC0, 0xEE, 0x1B, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x6E, 0xD0, 0x83, 0x83, 0x83, 0x83, 0xD0, 0x6E, 0x01, 0x01, 0x01, 0x01, 0x90, 0x57, 0xED, 0xF2, 0xED, 0x39, 0x39, 0x39, 0x39, 
        0x39, 0x9A, 0x53, 0x49, 0x53, 0x53, 0x7A, 0x12,
  0x12, 0x78, 0x51, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x81, 0x81, 0x39, 0xC0, 0x81, 0xEA, 0x57, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x6E, 0xCF, 0x48, 0x48, 0x48, 0x48, 0xCF, 0x6E, 0x01, 0x01, 0x01, 0x01, 0x0A, 0x24, 0xEB, 0xBE, 0xBE, 0x81, 0x81, 0x81, 0x2E, 
        0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x51, 0x78, 0x12,
  0x12, 0x78, 0x51, 0x51, 0x97, 0x97, 0x23, 0x23, 0x23, 0x23, 0x38, 0x38, 0x38, 0xE9, 0xE9, 0x8B, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x64, 0xC4, 0x48, 0x48, 0x48, 0x48, 0xC4, 0x64, 0x01, 0x01, 0x01, 0x01, 0x0A, 0x8B, 0x38, 0x38, 0x38, 0x38, 0x38, 0x23, 0x23, 
        0x23, 0x23, 0x97, 0x51, 0x51, 0x51, 0x78, 0x12,
  0x12, 0xAB, 0x6A, 0x6A, 0x6A, 0x23, 0x23, 0x23, 0x2D, 0x23, 0x2D, 0x2D, 0x52, 0x52, 0x52, 0x8B, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x64, 0xC3, 0x80, 0x80, 0x80, 0x80, 0xC3, 0x64, 0x01, 0x01, 0x01, 0x01, 0x0A, 0x8B, 0x52, 0x52, 0x52, 0x2D, 0x2D, 0x23, 0x2D, 
        0x23, 0x23, 0x23, 0xE2, 0x6A, 0x6A, 0xAB, 0x12,
  0x5D, 0x77, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x2D, 0x2D, 0x2C, 0x2C, 0x13, 0x13, 0x13, 0x0B, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x5A, 0x88, 0x99, 0x99, 0x99, 0x99, 0x88, 0x5A, 0x01, 0x01, 0x01, 0x01, 0x0A, 0x0B, 0x13, 0x13, 0x13, 0x2C, 0x2C, 0x2C, 0x2D, 
        0x2D, 0x36, 0x36, 0x36, 0x36, 0x36, 0x77, 0x5D,
  0x12, 0x77, 0xB4, 0xB1, 0x96, 0xAE, 0x69, 0x69, 0x76, 0x21, 0x21, 0x21, 0x75, 0xDF, 0xE5, 0xC2, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x5A, 0x88, 0x7F, 0x7F, 0x7F, 0x7F, 0x88, 0x5A, 0x01, 0x01, 0x01, 0x01, 0x0A, 0xF7, 0xBD, 0xBD, 0x13, 0x2C, 0x2C, 0x2C, 0x50, 
        0x50, 0x50, 0xB1, 0xB1, 0xB1, 0xB4, 0x77, 0x12,
  0x06, 0xA2, 0xA2, 0x00, 0x03, 0x03, 0x03, 0x02, 0x05, 0x05, 0x05, 0x18, 0x18, 0x07, 0x07, 0x13, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x5A, 0xF0, 0x5F, 0x5F, 0x5F, 0x7E, 0xF1, 0x5A, 0x01, 0x01, 0x01, 0x01, 0x0A, 0xF4, 0x22, 0x22, 0x22, 0x22, 0x22, 0x4F, 0x4F, 
        0x50, 0x50, 0x96, 0x96, 0x96, 0x95, 0xDC, 0x12,
  0x04, 0x04, 0x00, 0x00, 0x03, 0x03, 0x03, 0x02, 0x05, 0x05, 0x05, 0x0E, 0x07, 0x07, 0x07, 0x13, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x1D, 0x98, 0xE4, 0xE6, 0xE7, 0xE8, 0xEF, 0x5A, 0x01, 0x01, 0x01, 0x01, 0x0A, 0xF3, 0x7D, 0x7D, 0x7D, 0x7D, 0x4F, 0x4F, 0x4F, 
        0x4F, 0x4F, 0xAE, 0xAE, 0xDE, 0xA6, 0x04, 0x04,
  0x06, 0x04, 0x00, 0x00, 0x19, 0x03, 0x02, 0x02, 0x02, 0x05, 0x05, 0x0E, 0x07, 0x07, 0x07, 0x13, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x1D, 0x5F, 0x7C, 0xE3, 0xBC, 0xBC, 0x98, 0x1D, 0x01, 0x01, 0x01, 0x01, 0x0A, 0xC2, 0x6B, 0x6B, 0x7D, 0xAF, 0xAF, 0x94, 0x69, 
        0x69, 0x76, 0xDD, 0xA6, 0x27, 0x00, 0x04, 0x04,
  0x06, 0x04, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x05, 0x05, 0x0E, 0x07, 0x07, 0x07, 0x13, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x1D, 0x5F, 0x28, 0x7C, 0x7C, 0x7C, 0x7E, 0x1D, 0x01, 0x01, 0x01, 0x01, 0x0A, 0xEC, 0x75, 0x75, 0x75, 0x21, 0x21, 0x74, 0x1A, 
        0x1A, 0x03, 0x03, 0x03, 0x00, 0x00, 0x04, 0x04,
  0x06, 0x04, 0x00, 0x00, 0x00, 0x03, 0x03, 0x02, 0x02, 0x05, 0x05, 0x05, 0x07, 0x07, 0x07, 0x13, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x1D, 0x7E, 0x7C, 0x28, 0x28, 0x28, 0x7E, 0x1D, 0x01, 0x01, 0x01, 0x01, 0x0A, 0x13, 0x18, 0x18, 0x18, 0x05, 0x05, 0x05, 0x02, 
        0x02, 0x03, 0x03, 0x00, 0x00, 0x00, 0x04, 0x04,
  0x06, 0x04, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x02, 0x05, 0x05, 0x05, 0x07, 0x07, 0x07, 0x13, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x1D, 0x7E, 0x7C, 0x28, 0x28, 0x28, 0x7E, 0x1D, 0x01, 0x01, 0x01, 0x01, 0x0A, 0x13, 0x07, 0x07, 0x07, 0x05, 0x05, 0x05, 0x02, 
        0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x06, 0x06,
  0x12, 0x06, 0x04, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x05, 0x05, 0x05, 0x0E, 0x07, 0x07, 0x13, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x1D, 0x41, 0x28, 0x28, 0x28, 0x28, 0x41, 0x1D, 0x01, 0x01, 0x01, 0x01, 0x0A, 0x13, 0x07, 0x07, 0x0E, 0x05, 0x05, 0x05, 0x03, 
        0x03, 0x03, 0x00, 0x00, 0x00, 0x04, 0x04, 0x12,
  0x12, 0x04, 0x04, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x05, 0x05, 0x0E, 0x0E, 0x07, 0x13, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x1D, 0x41, 0x16, 0x16, 0x16, 0x16, 0x41, 0x1D, 0x01, 0x01, 0x01, 0x01, 0x0A, 0x13, 0x07, 0x0E, 0x0E, 0x05, 0x05, 0x02, 0x03, 
        0x02, 0x03, 0x00, 0x00, 0x00, 0x04, 0x04, 0x06,
  0x06, 0x04, 0x04, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x05, 0x05, 0x0E, 0x18, 0x13, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x1D, 0x41, 0x16, 0x16, 0x16, 0x16, 0x41, 0x1D, 0x01, 0x01, 0x01, 0x01, 0x0A, 0x13, 0x07, 0x0E, 0x05, 0x05, 0x05, 0x02, 0x02, 
        0x02, 0x03, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04,
  0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x03, 0x03, 0x02, 0x02, 0x02, 0x05, 0x05, 0x0E, 0x18, 0x13, 0x0A, 0x01, 0x01, 0x01, 0x01, 0x1D, 0x41, 0x16, 0x16, 0x16, 0x16, 0x41, 0x1D, 0x01, 0x01, 0x01, 0x01, 0x0A, 0x13, 0x0E, 0x0E, 0x05, 0x15, 0x02, 0x02, 0x02, 
        0x03, 0x03, 0x00, 0x00, 0x00, 0x04, 0x04, 0x06,
  0x06, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x05, 0x05, 0x05, 0x74, 0x21, 0x13, 0xBD, 0x22, 0x22, 0x22, 0x6B, 0xA5, 0x16, 0x16, 0x16, 0x16, 0xA5, 0x6B, 0x22, 0x22, 0x22, 0x22, 0x22, 0x74, 0x0E, 0x15, 0x21, 0x1A, 0x02, 0x02, 0x02, 
        0x03, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x06,
  0x06, 0x06, 0x04, 0x04, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x15, 0x74, 0x1A, 0x73, 0x73, 0x73, 0x18, 0x07, 0x07, 0x07, 0x07, 0x16, 0x07, 0x07, 0x16, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0E, 0x0E, 0x15, 0x21, 0x21, 0x15, 0x02, 0x02, 0x02, 
        0x03, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x06,
  0x06, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x02, 0x03, 0x1A, 0xA7, 0x69, 0x21, 0x15, 0x73, 0x18, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0E, 0x73, 0xA7, 0xDB, 0x1A, 0x02, 0x02, 0x02, 0x03, 
        0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x06, 0x06,
  0x06, 0x06, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x02, 0x03, 0x1A, 0xA7, 0x94, 0x76, 0x21, 0x74, 0x18, 0x18, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x18, 0x0E, 0x0E, 0x73, 0x21, 0xA7, 0x1A, 0x15, 0x02, 0x02, 0x02, 0x03, 
        0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x06, 0x06,
  0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x1A, 0x15, 0x1A, 0xAF, 0x76, 0x15, 0x0E, 0x0E, 0x0E, 0x07, 0x07, 0x07, 0x18, 0x18, 0x07, 0x07, 0x0E, 0x0E, 0x0E, 0x0E, 0x05, 0x15, 0xDB, 0x1A, 0x02, 0x02, 0x02, 0x02, 0x03, 0x00, 
        0x00, 0x00, 0x04, 0x04, 0x04, 0x06, 0x06, 0x06,
  0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x15, 0x1A, 0x1A, 0xA7, 0x05, 0x05, 0x05, 0x0E, 0x0E, 0x0E, 0x07, 0x18, 0x18, 0x07, 0x18, 0x07, 0x0E, 0x0E, 0x0E, 0x05, 0x1A, 0x1A, 0x15, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x00, 
        0x00, 0x00, 0x04, 0x04, 0x04, 0x06, 0x06, 0x08,
  0x08, 0x06, 0x06, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x15, 0x1A, 0x02, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x0E, 0x0E, 0x0E, 0x0E, 0x05, 0x05, 0x05, 0x05, 0x05, 0x1A, 0x1A, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x00, 0x00, 
        0x00, 0x00, 0x04, 0x04, 0x04, 0x06, 0x06, 0x08,
  0x08, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x00, 0x00, 
        0x00, 0x04, 0x04, 0x04, 0x06, 0x06, 0x06, 0x08,
  0x08, 0x08, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x15, 0x15, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x15, 0x15, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 
        0x04, 0x04, 0x04, 0x06, 0x06, 0x06, 0x08, 0x08,
  0x5B, 0x08, 0x08, 0x06, 0x06, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x15, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x15, 0x15, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 
        0x04, 0x04, 0x04, 0x06, 0x06, 0x08, 0x08, 0x5B,
  0x5B, 0x5B, 0x08, 0x06, 0x06, 0x06, 0x04, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 
        0x06, 0x06, 0x06, 0x06, 0x06, 0x08, 0x5B, 0x5B,
  0x5B, 0x08, 0x08, 0x08, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x02, 0x02, 0x03, 0x03, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 
        0x04, 0x06, 0x06, 0x06, 0x08, 0x08, 0x08, 0x5B,
  0xE0, 0x08, 0x08, 0x08, 0x08, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 
        0x06, 0x06, 0x06, 0xA1, 0x08, 0x08, 0x08, 0xE1,
  0xF6, 0xA3, 0x08, 0x5B, 0xA1, 0x06, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x19, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x06, 
        0x06, 0x06, 0x08, 0xD6, 0x5B, 0x08, 0xA3, 0x9D,
  0x8D, 0x89, 0xAC, 0x65, 0x91, 0x70, 0x71, 0x5C, 0x12, 0x12, 0x12, 0x12, 0x12, 0x27, 0x27, 0x27, 0x27, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x27, 0x27, 0x27, 0x27, 0x12, 0x12, 0x12, 0x12, 0x5C, 
        0x71, 0x71, 0x70, 0xD7, 0x65, 0xAC, 0x89, 0x8D
};

GUI_CONST_STORAGE GUI_BITMAP bmpause = {
  50, // xSize
  50, // ySize
  50, // BytesPerLine
  8, // BitsPerPixel
  _acpause,  // Pointer to picture data (indices)
  &_Palpause   // Pointer to palette
};

/*************************** End of file ****************************/
