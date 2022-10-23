#ifndef RISCV_MMIO_DEVICE_H_
#define RISCV_MMIO_DEVICE_H_

#include <stdint.h>

typedef struct MmioDevice MmioDevice;

typedef uint32_t MmioDeviceRead(MmioDevice* device, uint32_t address);
typedef void MmioDeviceWrite(MmioDevice* device, uint32_t address, uint32_t value);

typedef struct MmioDeviceOps {
    MmioDeviceRead* read;
    MmioDeviceWrite* write;
} MmioDeviceOps;

struct MmioDevice {
    const MmioDeviceOps* ops;
    void* cb_arg;
};

uint32_t mmio_device_read(MmioDevice* device, uint32_t address);
void mmio_device_write(MmioDevice* device, uint32_t address, uint32_t value);

#endif  // RISCV_MMIO_DEVICE_H_
