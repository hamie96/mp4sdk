/***************************************************************************

		font_ascii.h

		ʹ�����õ�ACII�ֿ���ʾ.

		TIME LIST:
		CREATE	Rainy	2009-06-05 22:44:50

		Copyright (c)  Yu.liang <lzysoft@126.com> 2007-2009
		All rights reserved.
***************************************************************************/
#ifndef _font_ascii_h_
#define _font_ascii_h_

#ifdef	__cplusplus
extern "C" {
#endif

//���RGB32
void display_byte_rgb32(char code,u32 *dst,u32 font_color,u32 bg_color, int width );
//���8bit�Ҷ�
void display_byte_gray8(char code,u8 *dst, int width );

#ifdef __cplusplus
}
#endif

#endif