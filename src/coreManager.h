/*********************************************************************

Core manager

Use to list all include necessary files

*********************************************************************/

#include "conf/conf.h"

#include "conf/banner/bannerManager.h"

// data
#include "core/data/api/api.h"
#include "core/data/send/mqtt/mqtt.h"
#include "core/data/storage/local/local.h"
#include "core/data/send/send.h"

// hardware
#include "core/hardware/action/button.h"

// Network
#include "core/network/wifi/ap/html/html.h"
#include "core/network/macAddress/macAddress.h"
#include "core/network/wifi/wifi.h"
#include "core/network/wifi/station/stationMode.h"
#include "core/network/wifi/ap/apMode.h"
