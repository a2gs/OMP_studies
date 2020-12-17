# Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/)
# C flags:
CFLAGS_OPTIMIZATION = -g
#CFLAGS_OPTIMIZATION = -O3
CFLAGS_VERSION = -std=c11 -fopenmp
CFLAGS_WARNINGS = -Wall -Wextra -Wno-unused-parameter -Wno-unused-but-set-parameter
CFLAGS_DEFINES = -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -D_POSIX_SOURCE=1 -D_DEFAULT_SOURCE=1 -D_GNU_SOURCE=1 -UDEBUGFLAG
CFLAGS = $(CFLAGS_OPTIMIZATION) $(CFLAGS_VERSION) $(CFLAGS_WARNINGS) $(CFLAGS_DEFINES)

# System shell utilities
CC = gcc
RM = rm -fr
CP = cp
AR = ar
RANLIB = ranlib
CPPCHECK = cppcheck

INCLUDEPATH = -I./
LIBS = -lgomp
LIBPATH = -L./

all: clean exectag

exectag:
	@echo
	@echo "=== Compiling =============="
	$(CC) -o sample sample.c openmp_util.c $(CFLAGS) $(INCLUDEPATH) $(LIBPATH) $(LIBS)
	$(CC) -o sample_barrier_master sample_barrier_master.c openmp_util.c $(CFLAGS) $(INCLUDEPATH) $(LIBPATH) $(LIBS)
	$(CC) -o sample_sections_barrier sample_sections_barrier.c openmp_util.c $(CFLAGS) $(INCLUDEPATH) $(LIBPATH) $(LIBS)
	$(CC) -o sample_sections_barrier_single_master sample_sections_barrier_single_master.c openmp_util.c $(CFLAGS) $(INCLUDEPATH) $(LIBPATH) $(LIBS)
	$(CC) -o sample_sections_nowait sample_sections_nowait.c openmp_util.c $(CFLAGS) $(INCLUDEPATH) $(LIBPATH) $(LIBS)
	$(CC) -o sample_for_critical sample_for_critical.c openmp_util.c $(CFLAGS) $(INCLUDEPATH) $(LIBPATH) $(LIBS)
	$(CC) -o sample_ordered sample_ordered.c openmp_util.c $(CFLAGS) $(INCLUDEPATH) $(LIBPATH) $(LIBS)

clean:
	@echo
	@echo "=== clean_data =============="
	-$(RM) sample_sections_barrier sample_sections_barrier_single_master sample_sections_nowait sample_for_critical sample_barrier_master sample_ordered
	-$(RM) sample core *.o
