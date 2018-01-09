/*
 * tpm.h - TPM ACPI definitions
 *
 * Copyright (C) 2014 IBM Corporation
 *
 * Authors:
 *  Stefan Berger <stefanb@us.ibm.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 *
 * Implementation of the TIS interface according to specs found at
 * http://www.trustedcomputinggroup.org
 *
 */
#ifndef HW_ACPI_TPM_H
#define HW_ACPI_TPM_H

#define TPM_TIS_ADDR_BASE           0xFED40000
#define TPM_TIS_ADDR_SIZE           0x5000

#define TPM_TIS_IRQ                 5

#define TPM_LOG_AREA_MINIMUM_SIZE   (64 * 1024)

#define TPM_TCPA_ACPI_CLASS_CLIENT  0
#define TPM_TCPA_ACPI_CLASS_SERVER  1

#define TPM2_ACPI_CLASS_CLIENT      0
#define TPM2_ACPI_CLASS_SERVER      1

#define TPM2_START_METHOD_MMIO      6

/*
 * Physical Presence Interface -- shared with the BIOS
 */
#define TCG_MAGIC 0x41504354

struct tpm_ppi {
    uint8_t ppin;            // set by BIOS
    uint32_t pprq;           // opcode; set by ACPI
    uint32_t succ;           // set by BIOS (0 = success)
    uint32_t lppr;           // last opcode; set by BIOS
    uint32_t pprp;           // response from TPM; set by BIOS
    uint32_t pprm;           // parameter for opcode; set by ACPI
    uint8_t next_step;       // BIOS only
} QEMU_PACKED;

#define TPM_PPI_STRUCT_SIZE  sizeof(struct tpm_ppi)

#endif /* HW_ACPI_TPM_H */
