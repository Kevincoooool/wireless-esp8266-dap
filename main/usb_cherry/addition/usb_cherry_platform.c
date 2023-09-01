/*
 * @Author: Kevincoooool
 * @Date: 2023-08-01 14:04:54
 * @Description: 
 * @version:  
 * @Filename: Do not Edit
 * @LastEditTime: 2023-08-02 09:50:26
 * @FilePath: \cherryusb_esp32\main\usb_cherry\addition\usb_cherry_platform.c
 */
#include "esp_intr_alloc.h"
#include "soc/usb_periph.h"
#include "soc/periph_defs.h"
#include "esp_private/usb_phy.h"

uint32_t SystemCoreClock = 240 * 1000000; // dwc2 的一个参数

static intr_handle_t interrupt_handle_ps; // esp32 中断要用
    static usb_phy_handle_t handle_s;

void usb_dc_low_level_init(void)
{
    void usb_interrupt_enable();

    // esp32s2 phy
        usb_phy_config_t config_s = {
        .controller = USB_PHY_CTRL_OTG,
        .otg_mode = USB_OTG_MODE_DEVICE,
        .target = USB_PHY_TARGET_INT
    };
    usb_new_phy(&config_s, &handle_s);

    usb_interrupt_enable();
}
void usb_dc_low_level_deinit(void)
{
    usb_del_phy(handle_s);
}
// usb 中断
static void usb_interrupt_cb(void *arg_pv)
{
    extern void OTG_FS_IRQHandler(); // dwc2 的中断处理函数

    OTG_FS_IRQHandler();
}

// usb 中断开启
void usb_interrupt_enable()
{
    esp_intr_alloc(ETS_USB_INTR_SOURCE, ESP_INTR_FLAG_LOWMED, (intr_handler_t)usb_interrupt_cb, 0, &interrupt_handle_ps);
}

// usb 中断关闭
void usb_interrupt_disable()
{
    esp_intr_free(interrupt_handle_ps);
}