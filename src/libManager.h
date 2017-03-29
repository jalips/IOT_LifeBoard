/*********************************************************************

Library manager

Use to list all include necessary files

*********************************************************************/

// Include application, user and local libraries
#ifndef __CC3200R1M1RGC__
// TODO : It's for what ??
#include <SPI.h>                // Do not include SPI for CC3200 LaunchPad
#endif

// Core library for code-sense - IDE-based
#include "Energia.h"

#include <WiFi.h>
#include <SLFS.h>

#include <Wire.h>
#include "Adafruit_TMP006.h"

#include "utility/udma_if.h"
#include "utility/simplelink.h"

#include <WifiIPStack.h>
#include <Countdown.h>
#include <MQTTClient.h>

#include "lib/ArduinoHttpClient-master/src/ArduinoHttpClient.h"
