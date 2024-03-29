#*************************************************************************\
#  																lzysoft                                 *
#                                                                         *
#   PROJECT     : ccpmp                                                   *
#                                                                         *
#   MODULE      : MakeFile                                                *
#                                                                         *
#   PROCESSOR   : arm926 x690hd															              *
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

TARGET		= xgui

CPP       = armcc
CC        = armcc
LD        = armlink
AR				=	ar rus

# *************************************************************************
# Directories
# *************************************************************************
ROOTDIR    = ..

SRCDIR    = $(ROOTDIR) \
						
						
INCDIR    =	$(SRCDIR) \
						../../../../inc \
						D:/cygwin/arm-linux/sysroot/usr/include \
						
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

CC_OPTS   = -c -W --gnu --enum_is_int --cpu=ARM926EJ-S --fpu=SoftVFP -O3 -Otime $(INCLUDE) $(_DEFINE)

CPP_OPTS  =	-c -W --gnu --enum_is_int --cpu=ARM926EJ-S --fpu=SoftVFP -O3 -Otime $(INCLUDE) $(_DEFINE)

CC_OPTS_A = --cpu=ARM926EJ-S --fpu=SoftVFP

# *************************************************************************
# Files to be compiled
# *************************************************************************

              
SRC_C   = xgui.c
					
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
	cp $(TARGET).a ../../../cc1600-rv40/

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

