#ifndef RISCV_MMIO_DEVICE_H_
#define RISCV_MMIO_DEVICE_H_

#include <stdint.h>

typedef struct MMIODevice MMIODevice;

typedef uint32_t MMIODeviceRead(MMIODevice* device, uint32_t address);
typedef void MMIODeviceWrite(MMIODevice* device, uint32_t address, uint32_t value);

typedef struct MMIODeviceOps {
    MMIODeviceRead* read;
    MMIODeviceWrite* write;
} MMIODeviceOps;

struct MMIODevice {
    const MMIODeviceOps* ops;
    void* cb_arg;
};

uint32_t mmio_device_read(MMIODevice* device, uint32_t address);
void mmio_device_write(MMIODevice* device, uint32_t address, uint32_t value);

#endif  // RISCV_MMIO_DEVICE_H_
