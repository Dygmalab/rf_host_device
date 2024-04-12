# rf_host_device

## About

rf_host_device is a precompiled and linked binary software by JayLabs s.r.o. which implements and handles control of the data streams on top of a wireless protocol using the Nordic Semiconductor SDK.

## Supported systems

rf_host_device is prepared for nRF52 family chips from Nordic Semiconductors loaded with s140 softdevice. The device was namely tested with the nRF52833 chip.

## Memory Usage

|         | Address      | Length                    |
|---------|--------------|---------------------------|
| FLASH   | 0x00027000   | 0x7000  (28 672)          |
| RAM     | 0x20005978   | 0x3A88  (14 984)          |

## Chip Memory Architecture

|                       |                           |
|-----------------------|---------------------------|
| main application      | 0x0002E000 - ...          |
|-----------------------|---------------------------|
| rf_host_device        | 0x00027000 - 0x0002DFFF   |
|-----------------------|---------------------------|
| Softdevice S140       | 0x00001000 - 0x00026FFF   |
| MBR                   | 0x00000000 - 0x00000FFF   |

## Peripheral Usage


rf_host_device has been developed following the same philosophy as the Nordic's softdevice, the package is bundled and then distributed as a binary, routing the peripheral access to the target application after reserving the required peripherals.

In addition to the nRF52 peripherals already reserved by softdevice ([s140 manual](https://infocenter.nordicsemi.com/pdf/S140_SDS_v2.1.pdf)), rf_host_device reserves the following peripherals:

* RADIO
* TIMER3
* SWI5

## Getting started

- Run the `rfhdev_init(const rfhdev_config_t * p_config)` for registering general API callback functions
- Run the `rfgw_host_init()` for for initializing the RF Host device

## Restrictions

* rfgw_host must not be initialized (`rfgw_host_init()`) if the softdevice has been enabled first
* softdevice must not be enabled if the rfgw_host has been previously initialized
* once the rfgw_host has been initialized, it cannot be uninitialized. For switching to the softdevice, the chip must be restarted.

