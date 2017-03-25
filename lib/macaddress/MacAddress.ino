///
/// @brief  Get MAC address
/// @return MAC address
///
MACAddress getMacAddress()
{
    WiFi.status();
    uint8_t macAddressVal[SL_MAC_ADDR_LEN];
    uint8_t macAddressLen = SL_MAC_ADDR_LEN;
    sl_NetCfgGet(SL_MAC_ADDRESS_GET,NULL,&macAddressLen,macAddressVal);
    MACAddress MAC(macAddressVal);
    return MAC;
}
