#*************************************************************************\
#  																lzysoft                                 *
#                                                                         *
#   PROJECT     : ccpmp                                                   *
#                                                                         *
#   MODULE      : MakeFile                                                *
#                                                                         *
#   PROCESSOR   : jz47xx      															              *
#                                                                         *
#   Tool-chain  : arm-linux-gcc                                           *
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
#     1.0     2008-1-30      rainy    Created.                            *
#*************************************************************************/

TARGET		= zlib

CPP       = mipsel-linux-g++
CC        = mipsel-linux-gcc
LD        = mipsel-linux-ld
OBJCOPY   = mipsel-linux-objcopy
OBJDUMP   = mipsel-linux-objdump
AR				=	mipsel-linux-ar rus

# *************************************************************************
# Directories
# *************************************************************************
ROOTDIR    = ..

SRCDIR    = $(ROOTDIR) \
						$(ROOTDIR)/zlib-1.2.3 \
						
INCDIR    =	$(SRCDIR) \
						../../../../inc \
						
#include include "-I"
INCCMD		= 

#defined include "-D"
DEFCMD		=	-D"__align=arm_align" \
						-D"inline=__inline" \
						-D"__gnuc_va_list=va_list" \

# defined
DEFINE =	__MULTIPLATFORM__ \
					__MULTIPLATFORM_CC1600_GCC__ \
					__MULTIPLATFORM_CC1600__ \
					\
					
VPATH     = $(SRCDIR)

# *************************************************************************
# Compiler and linker options
# *************************************************************************

INCLUDE   = $(addprefix -I,$(INCDIR))

INCLUDE   = $(addprefix -I,$(INCDIR)) $(INCCMD)
_DEFINE   = $(addprefix -D,$(DEFINE)) $(DEFCMD)

W_OPTS    = -Wall -finline-functions -fomit-frame-pointer -msoft-float \
-fno-builtin -fno-exceptions

CC_OPTS   = -g -c -O2 $(INCLUDE) -mips32 $(W_OPTS) -mno-abicalls -fno-pic \
-pipe -G 0 -D__NO_INLINE__ \

CPP_OPTS  =	-c -fno-exceptions -fno-rtti -Wall -W \
-DNO_DEBUG -DGCC_BUILD $(ENV_MACRO) \
$(W_OPTS) -fno-pic -pipe -O

CC_OPTS_A = $(CC_OPTS) -D_ASSEMBLER_ -DMPU_JZ4740 $(ENV_MACRO)

# *************************************************************************
# Files to be compiled
# *************************************************************************

              
SRC_C   = adler32.c compress.c crc32.c deflate.c gzio.c infback.c inffast.c inflate.c \
					inftrees.c minigzip.c trees.c uncompr.c zutil.c
					
SRC_CPP =
SRC_S   =
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

$(IMAGE_LIB) : $(OBJ)
	$(AR) $(TARGET).a $(OBJ)
	cp $(TARGET).a ../../../gcc-mips/

$(OBJ_C) : %.o : %.c
	$(CC) $(CC_OPTS) -o $@ $<

$(OBJ_CPP) : %.o : %.cpp
	$(CPP) $(CPP_OPTS) -o $@ $<

$(OBJ_S) : %.o : %.S
	$(CC) $(CC_OPTS_A) -o $@ $@.S

.PHONY : clean depend

clean :
	rm -f $(IMAGE_LIB) $(OBJ) $(MAP)

# *************************************************************************
#                              END  OF  FILE
# *************************************************************************

