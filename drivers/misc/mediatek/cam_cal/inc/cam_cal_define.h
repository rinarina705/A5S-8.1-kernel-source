/*
 * Copyright (C) 2016 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */
#ifndef _CAM_CAL_DATA_H
#define _CAM_CAL_DATA_H

#ifdef CONFIG_COMPAT
/* 64 bit */
#include <linux/fs.h>
#include <linux/compat.h>
#endif

#ifdef ODM_WT_EDIT
/* Xuegui.Bao@Camera.Driver, 2018/10/10, add for [summer otp bringup] */
struct stCAM_CAL_INFO_STRUCT {
	u32 u4Offset;
	u32 u4Length;
	u32 sensorID;
	u32 deviceID;/* MAIN = 0x01, SUB  = 0x02, MAIN_2 = 0x04*/
	u8 *pu1Params;
};

struct stCAM_CAL_DATAINFO_STRUCT {
	u32 sensorID;
	u32 deviceID; /* MAIN = 0x01, SUB  = 0x02, MAIN_2 = 0x04*/
	u32 dataLength;
	u32 sensorVendorid;
	u8  vendorByte[1];
	u8  *dataBuffer;
};

typedef enum{
	MODULE_ITEM = 0,
	AWB_ITEM,
	SEGMENT_ITEM,
	AF_ITEM,
	LSC_ITEM,
	PDAF_ITEM,
	DUALCAM_ITEM,
	CROSS_TALK_ITEM,
	TOTAL_ITEM,
	MAX_ITEM,
}stCAM_CAL_CHECKSUM_ITEM;
#endif

struct stCAM_CAL_CHECKSUM_STRUCT{
	stCAM_CAL_CHECKSUM_ITEM item;
	u32 flagAdrees;
	u32 startAdress;
	u32 endAdress;
	u32 checksumAdress;
	u8  validFlag;
};

#ifdef CONFIG_COMPAT

struct COMPAT_stCAM_CAL_INFO_STRUCT {
	u32 u4Offset;
	u32 u4Length;
	u32 sensorID;
	u32 deviceID;
	compat_uptr_t pu1Params;
};
#endif

#endif/*_CAM_CAL_DATA_H*/
