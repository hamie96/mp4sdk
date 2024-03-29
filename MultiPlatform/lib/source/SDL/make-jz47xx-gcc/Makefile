#*************************************************************************\
#  Copyright (c) 2007 by China Chip Tech.                                 *
#                                                                         *
#   PROJECT     : ccpmp                                                   *
#                                                                         *
#   MODULE      : MakeFile                                                *
#                                                                         *
#   PROCESSOR   : MIPS 4Kc (32 bit RISC) - 47xx board                     *
#                                                                         *
#   Tool-chain  : sde-gcc                                                 *
#                                                                         *
#   DESCRIPTION :                                                         *
#   Makefile used for building application.                               *
#                                                                         *
#   The default target (all) builds application in two formats :          *
#   *.a : The file is archives for ccpmp.                                 *
#                                                                         *
#   Other targets are :                                                   *
#   clean :    Deletes all files generated by makefile.                   *
#                                                                         *
#  History :                                                              *
#    Version      Date      Author     Memo                               *
#     1.0     2008-01-30      rainy    Created.                           *
#     1.1     2009-12-09      vrix.yan  Modified                          *
#*************************************************************************/

TARGET    = libSDL
CPP       = sde-g++
CC        = sde-gcc
MXU       = mxu_as

# *************************************************************************
# Directories
# *************************************************************************

SRCDIR    = ../ \
	../src/ \
	../src/audio/ \
	../src/cdrom/ \
	../src/cpuinfo/ \
	../src/events/ \
	../src/file/ \
	../src/joystick/ \
	../src/stdlib/ \
	../src/thread/ \
	../src/timer/ \
	../src/video/ \
	../src/joystick/dummy/ \
	../src/cdrom/dummy/ \
	../src/loadso/dummy/ \
	../src/audio/mpf/ \
	../src/thread/mpf/ \
	../src/timer/mpf/ \
	../src/video/mpf/ \
	../SDL_image/ \
	../SDL_ttf/ \
	../SDL_mixer/ \
	../SDL_mixer/libmad/ \
	../SDL_mixer/timidity/ \
	../SDL_mixer/libmikmod/drivers \
	../SDL_mixer/libmikmod/include \
	../SDL_mixer/libmikmod/loaders \
	../SDL_mixer/libmikmod/mmio \
	../SDL_mixer/libmikmod/playercode \
	

INCDIR    =	$(SRCDIR) \
						../../../../inc \
						../../../../inc/libjpeg \
						../../../../inc/libpng \
						../../../../inc/zlib \
						../../../../inc/freetype \
						../include \
						
					
VPATH     = $(SRCDIR)

# *************************************************************************
# Compiler and linker options
# *************************************************************************

INCLUDE   = $(addprefix -I,$(INCDIR))

ENDIAN    = EL

ENV_MACRO =

W_OPTS    = -Wall -finline-functions -fomit-frame-pointer -msoft-float \
-fno-builtin -fno-exceptions

CC_OPTS   = -c  -Wall -W  -$(ENDIAN) $(INCLUDE) -G0 \
-DNO_DEBUG -DGCC_BUILD -DMPU_JZ4740 $(ENV_MACRO) \
-fno-pic -mips32 $(W_OPTS) -mno-abicalls -funsigned-char -pipe -G 0 -O2 \
-DNDEBUG -D_LIB -DFT2_BUILD_LIBRARY \

CPP_OPTS  =	-c -fno-exceptions -fno-rtti -Wall -W \
-DNO_DEBUG -DGCC_BUILD $(ENV_MACRO) \
$(W_OPTS) -fno-pic -pipe -O

CC_OPTS_A = $(CC_OPTS) -D_ASSEMBLER_ -DMPU_JZ4740 $(ENV_MACRO)

LINK	=	sde-g++

LFLAGS	=

LIBS	=	$(SUBLIBS) -lm -lz

TAR		=	tar -cf

GZIP	=	gzip -9f

STR		=	sde-strip -g -x

AR		=	sde-ar rus

# *************************************************************************
# Files to be compiled
# *************************************************************************

SRC_C   = $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
SRC_CPP = $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.cpp))
SRC_S   = $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.S))
SRC     = $(SRC_C) $(SRC_CPP) $(SRC_S)

OBJ_C   = $(notdir $(patsubst %.c, %.o, $(SRC_C)))
OBJ_CPP = $(notdir $(patsubst %.cpp, %.o, $(SRC_CPP)))
OBJ_S   = $(notdir $(patsubst %.S, %.o, $(SRC_S)))

OBJ     = $(OBJ_C) $(OBJ_CPP) $(OBJ_S)

# *************************************************************************
# Image file names and map file
# *************************************************************************

IMAGE_LIB = $(TARGET).a

# *************************************************************************
# Rules
# *************************************************************************

.PHONY : all

all : $(IMAGE_LIB)
	cp  $(TARGET).a ../../../gcc-mips/

$(IMAGE_LIB) : $(OBJ) $(OBJ_MXU)
	$(AR) $(TARGET).a $(OBJ) $(OBJ_MXU)
	$(STR) $(TARGET).a

$(OBJ_C) : %.o : %.c %.dc
	$(CC) $(CC_OPTS) -o $@ $<

$(OBJ_CPP) : %.o : %.cpp %.dcpp
	$(CPP) $(CPP_OPTS) -o $@ $<

$(OBJ_S) : %.o : %.S
	$(MXU) $< > $@.S
	$(CC) $(CC_OPTS_A) -o $@ $@.S

%.dc: %.c
	$(CC) -M $(CC_OPTS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

%.dcpp: %.c
	$(CC) -M $(CPP_OPTS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

.PHONY : clean depend

clean :
	rm -f $(IMAGE_LIB) $(OBJ) $(OBJ_MXU) $(MAP) *.S *.m *.dc *.dcpp

sinclude $(OBJ_C:.o=.dc)
sinclude $(OBJ_CPP:.o=.dcpp)

# *************************************************************************
#                              END  OF  FILE
# *************************************************************************

