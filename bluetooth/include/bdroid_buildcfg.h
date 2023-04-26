/*
 *
 *  Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *  Not a Contribution, Apache license notifications and license are retained
 *  for attribution purposes only.
 *
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _BDROID_BUILDCFG_H
#define _BDROID_BUILDCFG_H

#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif
int property_get(const char *key, char *value, const char *default_value);
#ifdef __cplusplus
}
#endif

static inline const char* BtmGetDefaultName()
{
    char product_device[92];
    property_get("ro.product.device", product_device, "");

    if (strstr(product_device, "foles"))
        return "Moto Z4";
    if (strstr(product_device, "parker"))
        return "Moto one zoom";
    if (strstr(product_device, "def"))
        return "Moto one hyper";
    if (strstr(product_device, "liber"))
        return "Moto one fusion+";
    if (strstr(product_device, "odessa"))
        return "Moto G9 plus";
    if (strstr(product_device, "minsk"))
        return "Moto G stylus (2021)";
    if (strstr(product_device, "hanoip"))
        return "Moto G60";

    // Fallback to Moto Generic
    return "Motorola";
}

#define BTM_DEF_LOCAL_NAME BtmGetDefaultName()
// Disables read remote device feature
#define BTM_WBS_INCLUDED TRUE
#define BTIF_HF_WBS_PREFERRED TRUE

#define BLE_VND_INCLUDED   TRUE
#endif
