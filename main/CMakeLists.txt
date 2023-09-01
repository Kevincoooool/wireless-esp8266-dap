# set(COMPONENT_ADD_INCLUDEDIRS "${PROJECT_PATH}")
# set(COMPONENT_SRCS
#     main.c cmsis_dap_v2.c timer.c tcp_server.c usbip_server.c DAP_handle.c
#     kcp_server.c tcp_netconn.c uart_bridge.c wifi_handle.c
    
    
    
    
#     )


# register_component()


idf_component_register(SRCS 
    "main.c"
    "cmsis_dap_v2.c" 
    "chry_ringbuffer.c"
    "timer.c" 
    "tcp_server.c" 
    "usbip_server.c" 
    "DAP_handle.c"
    "kcp_server.c" 
    "tcp_netconn.c" 
    "uart_bridge.c" 
    "wifi_handle.c"
    "usb_cherry/addition/usb_cherry_platform.c"
    "usb_cherry/CherryUSB/class/cdc/usbd_cdc.c"
    "usb_cherry/CherryUSB/class/hid/usbd_hid.c"
    # "usb_cherry/CherryUSB/class/wireless/usbd_rndis.c"

    "usb_cherry/CherryUSB/class/msc/usbd_msc.c"
    "usb_cherry/CherryUSB/core/usbd_core.c"
    "usb_cherry/CherryUSB/port/dwc2/usb_dc_dwc2.c"

    INCLUDE_DIRS
    "."
    "usb_cherry"
    # "usb_cherry/CherryUSB/class/wireless"
    "usb_cherry/CherryUSB/class/cdc"
    "usb_cherry/CherryUSB/class/hid"
    "usb_cherry/CherryUSB/class/msc"
    "usb_cherry/CherryUSB/common"
    "usb_cherry/CherryUSB/core"
    "usb_cherry/CherryUSB/port/dwc2"
)

