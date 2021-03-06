#ifndef NRF_SDM_H__
#define NRF_SDM_H__ 
#include "nrf_svc.h"
#include "nrf.h"
#include "nrf_soc.h"
#include "nrf_error_sdm.h"
#ifdef __cplusplus
extern "C" {
#endif
#ifdef NRFSOC_DOXYGEN
#define MBR_SIZE 0
#warning test
#endif
#define SD_MAJOR_VERSION (5)
#define SD_MINOR_VERSION (0)
#define SD_BUGFIX_VERSION (0)
#define SD_VERSION (SD_MAJOR_VERSION * 1000000 + SD_MINOR_VERSION * 1000 + SD_BUGFIX_VERSION)
#define SDM_SVC_BASE 0x10
#define SD_UNIQUE_STR_SIZE 20
#define SDM_INFO_FIELD_INVALID (0)
#define SOFTDEVICE_INFO_STRUCT_OFFSET (0x2000)
#define SOFTDEVICE_INFO_STRUCT_ADDRESS (SOFTDEVICE_INFO_STRUCT_OFFSET + MBR_SIZE)
#define SD_INFO_STRUCT_SIZE_OFFSET (SOFTDEVICE_INFO_STRUCT_OFFSET)
#define SD_SIZE_OFFSET (SOFTDEVICE_INFO_STRUCT_OFFSET + 0x08)
#define SD_FWID_OFFSET (SOFTDEVICE_INFO_STRUCT_OFFSET + 0x0C)
#define SD_ID_OFFSET (SOFTDEVICE_INFO_STRUCT_OFFSET + 0x10)
#define SD_VERSION_OFFSET (SOFTDEVICE_INFO_STRUCT_OFFSET + 0x14)
#define SD_UNIQUE_STR_OFFSET (SOFTDEVICE_INFO_STRUCT_OFFSET + 0x18)
#define SD_INFO_STRUCT_SIZE_GET(baseaddr) (*((uint8_t *) ((baseaddr) + SD_INFO_STRUCT_SIZE_OFFSET)))
#define SD_SIZE_GET(baseaddr) (*((uint32_t *) ((baseaddr) + SD_SIZE_OFFSET)))
#define SD_FWID_GET(baseaddr) (*((uint16_t *) ((baseaddr) + SD_FWID_OFFSET)))
#define SD_ID_GET(baseaddr) ((SD_INFO_STRUCT_SIZE_GET(baseaddr) > (SD_ID_OFFSET - SOFTDEVICE_INFO_STRUCT_OFFSET)) \
        ? (*((uint32_t *) ((baseaddr) + SD_ID_OFFSET))) : SDM_INFO_FIELD_INVALID)
#define SD_VERSION_GET(baseaddr) ((SD_INFO_STRUCT_SIZE_GET(baseaddr) > (SD_VERSION_OFFSET - SOFTDEVICE_INFO_STRUCT_OFFSET)) \
        ? (*((uint32_t *) ((baseaddr) + SD_VERSION_OFFSET))) : SDM_INFO_FIELD_INVALID)
#define SD_UNIQUE_STR_ADDR_GET(baseaddr) ((SD_INFO_STRUCT_SIZE_GET(baseaddr) > (SD_UNIQUE_STR_OFFSET - SOFTDEVICE_INFO_STRUCT_OFFSET)) \
        ? (((uint8_t *) ((baseaddr) + SD_UNIQUE_STR_OFFSET))) : SDM_INFO_FIELD_INVALID)
#define NRF_FAULT_ID_SD_RANGE_START 0x00000000
#define NRF_FAULT_ID_APP_RANGE_START 0x00001000
#define NRF_FAULT_ID_SD_ASSERT (NRF_FAULT_ID_SD_RANGE_START + 1)
#define NRF_FAULT_ID_APP_MEMACC (NRF_FAULT_ID_APP_RANGE_START + 1)
enum NRF_SD_SVCS
{
  SD_SOFTDEVICE_ENABLE = SDM_SVC_BASE,
  SD_SOFTDEVICE_DISABLE,
  SD_SOFTDEVICE_IS_ENABLED,
  SD_SOFTDEVICE_VECTOR_TABLE_BASE_SET,
  SVC_SDM_LAST
};
#define NRF_CLOCK_LF_ACCURACY_250_PPM (0)
#define NRF_CLOCK_LF_ACCURACY_500_PPM (1)
#define NRF_CLOCK_LF_ACCURACY_150_PPM (2)
#define NRF_CLOCK_LF_ACCURACY_100_PPM (3)
#define NRF_CLOCK_LF_ACCURACY_75_PPM (4)
#define NRF_CLOCK_LF_ACCURACY_50_PPM (5)
#define NRF_CLOCK_LF_ACCURACY_30_PPM (6)
#define NRF_CLOCK_LF_ACCURACY_20_PPM (7)
#define NRF_CLOCK_LF_ACCURACY_10_PPM (8)
#define NRF_CLOCK_LF_ACCURACY_5_PPM (9)
#define NRF_CLOCK_LF_ACCURACY_2_PPM (10)
#define NRF_CLOCK_LF_ACCURACY_1_PPM (11)
#define NRF_CLOCK_LF_SRC_RC (0)
#define NRF_CLOCK_LF_SRC_XTAL (1)
#define NRF_CLOCK_LF_SRC_SYNTH (2)
typedef struct
{
  uint8_t source;
  uint8_t rc_ctiv;
  uint8_t rc_temp_ctiv;
  uint8_t accuracy;
} nrf_clock_lf_cfg_t;
typedef void (*nrf_fault_handler_t)(uint32_t id, uint32_t pc, uint32_t info);
SVCALL(SD_SOFTDEVICE_ENABLE, uint32_t, sd_softdevice_enable(nrf_clock_lf_cfg_t const * p_clock_lf_cfg, nrf_fault_handler_t fault_handler));
SVCALL(SD_SOFTDEVICE_DISABLE, uint32_t, sd_softdevice_disable(void));
SVCALL(SD_SOFTDEVICE_IS_ENABLED, uint32_t, sd_softdevice_is_enabled(uint8_t * p_softdevice_enabled));
SVCALL(SD_SOFTDEVICE_VECTOR_TABLE_BASE_SET, uint32_t, sd_softdevice_vector_table_base_set(uint32_t address));
#ifdef __cplusplus
}
#endif
#endif
