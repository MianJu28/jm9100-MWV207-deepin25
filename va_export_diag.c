#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <sys/mman.h>
#include <va/va.h>
#include <va/va_drmcommon.h>
typedef VAStatus (*e_t)(VADisplay, VASurfaceID, uint32_t, uint32_t, void *);
static e_t r;
static int c;
VAStatus vaExportSurfaceHandle(VADisplay d, VASurfaceID s, uint32_t m, uint32_t f, void *p)
{
if (!r) r = (e_t)dlsym(RTLD_NEXT, "vaExportSurfaceHandle");
VAStatus st = r(d, s, m, f, p);
if (st || m != 0x40000000 || c >= 16) return st;
c++;
VADRMPRIMESurfaceDescriptor *dd = (VADRMPRIMESurfaceDescriptor *)p;
unsigned sz = dd->objects[0].size;
unsigned char *mm = mmap(0, sz, 1, 1, dd->objects[0].fd, 0);
if (mm == (void *)-1) return st;
unsigned nz = 0;
for (unsigned k = 0; k < sz; k += 512) nz += !!mm[k];
fprintf(stderr, "[vad]#%d %.4s %dx%d sz=%u nz=%u off1=%d\n", c, (char *)&dd->fourcc, dd->width, dd->height, sz, nz, dd->layers[0].offset[dd->layers[0].num_planes > 1 ? 1 : 0]);
munmap(mm, sz);
return st;
}
