########################################################################
#                                                                       
#              Main Makefile for Neural Networks project                
#                                                                       
########################################################################
PROJECT     = neural
INCLUDE_DIR = $(PWD)/include
OBJS        = $(patsubst %.cpp,%.o,$(sort $(wildcard src/*/*.cpp)))
NPROCS      = $(shell grep -c ^processor /proc/cpuinfo)
TOTAL       = $(words $(OBJS))

CMAKE       = CMakeFiles          \
              CMakeCache.txt      \
              cmake_install.cmake

GARBAGE     = $(DATA) $(OBJS) $(PROJECT) $(CMAKE)

CC          = @g++
STRIP       = @strip
MAKE        = @make -j${NPROCS} --no-print-directory
ECHO        = @echo
CLEAN       = @rm -rf
PROGRESS    = \[`echo $(OBJS) | sed "s/\ /\n/g" | grep -n $@ | cut -f1 -d: | tr -d '\n' | xargs -0 printf "%d"`\/$(TOTAL)\]


NORMAL      = "\033[0m"
PURPLE      = "\033[1;35m"
YELLOW      = "\033[0;33m"
GREEN       = "\033[0;32m"
CYAN        = "\033[1;36m"
RED         = "\033[1;31m"

LDFLAGS     = -static-libstdc++ \
              -static-libgcc    \
              -lsfml-graphics   \
              -lsfml-window     \
              -lsfml-system     \
              -lsfml-audio      \
              -lm               \
              -ljansson         \
              -lsteam_api

CFLAGS      = -Wall                       \
              -Wextra                     \
              -DCREATE_ARCHIVE            \
              -std=c++11                  \
              -I$(INCLUDE_DIR)            \
              -I$(INCLUDE_DIR)/meta       \
              -I$(INCLUDE_DIR)/steam


all: info
	$(MAKE) $(PROJECT)


info:
	$(ECHO) $(CYAN)
	$(ECHO) "▗▄ ▗▖                    ▗▄▖       ▗▄ ▗▖                         ▗▖        "
	$(ECHO) "▐█ ▐▌                    ▝▜▌       ▐█ ▐▌      ▐▌                 ▐▌        "
	$(ECHO) "▐▛▌▐▌ ▟█▙ ▐▌ ▐▌ █▟█▌ ▟██▖ ▐▌       ▐▛▌▐▌ ▟█▙ ▐███ █   █ ▟█▙  █▟█▌▐▌▟▛ ▗▟██▖"
	$(ECHO) "▐▌█▐▌▐▙▄▟▌▐▌ ▐▌ █▘   ▘▄▟▌ ▐▌       ▐▌█▐▌▐▙▄▟▌ ▐▌  ▜ █ ▛▐▛ ▜▌ █▘  ▐▙█  ▐▙▄▖▘"
	$(ECHO) "▐▌▐▟▌▐▛▀▀▘▐▌ ▐▌ █   ▗█▀▜▌ ▐▌       ▐▌▐▟▌▐▛▀▀▘ ▐▌  ▐▙█▟▌▐▌ ▐▌ █   ▐▛█▖  ▀▀█▖"
	$(ECHO) "▐▌ █▌▝█▄▄▌▐▙▄█▌ █   ▐▙▄█▌ ▐▙▄      ▐▌ █▌▝█▄▄▌ ▐▙▄ ▝█ █▘▝█▄█▘ █   ▐▌▝▙ ▐▄▄▟▌"
	$(ECHO) "▝▘ ▀▘ ▝▀▀  ▀▀▝▘ ▀    ▀▀▝▘  ▀▀      ▝▘ ▀▘ ▝▀▀   ▀▀  ▀ ▀  ▝▀▘  ▀   ▝▘ ▀▘ ▀▀▀ "
	$(ECHO) $(NORMAL)
	$(ECHO) $(RED) "C  flags:" $(YELLOW) $(CFLAGS)  $(NORMAL)
	$(ECHO) $(RED) "LD flags:" $(YELLOW) $(LDFLAGS) $(NORMAL)
	$(ECHO)
	$(ECHO) $(PURPLE) "Building $(TOTAL) files in $(NPROCS) threads" $(NORMAL)
	$(ECHO) $(PURPLE) "Building: $(PROJECT)" $(NORMAL)
	$(ECHO)


$(PROJECT): $(OBJS)
	$(ECHO)
	$(ECHO) $(CYAN) Linking $(PROJECT) $(NORMAL)
	$(CC) $(OBJS) -o $(PROJECT) $(LDFLAGS)

	$(ECHO) $(CYAN) Stripping $(PROJECT) $(NORMAL)
	$(STRIP) $(PROJECT)


.cpp.o:
	$(ECHO) $(GREEN) "  Compiling" $(NORMAL)$(PROGRESS)$(GREEN) ": $(*F)" $(NORMAL)
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	$(ECHO) $(YELLOW)$(GARBAGE) $(NORMAL)
	$(CLEAN) $(GARBAGE)
