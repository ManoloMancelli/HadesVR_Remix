# Headset

The headset connects directly to your PC using the USB cable.
Built-in HadesVR PCB provides rotation data from gyroscope and also receives the controller data wirelessly.


# Hardware Needed

## Shell
For the shell you can use any "Phone VR" enclosure, they come in very different qualities but all of them should do the trick (even the carboard ones). Keep in mind the enclosure will dictate your max fov and that you can always modify the shell to allow for a wider fov.

![1](img/Headset/1.png)


⚠️ The screen mount depends on what screen and case you use.

## Electronics

* Arduino Pro micro - Best one. Different ones won't work.

* Gyroscope - MPU9250 is the best one but you can use cheaper ones at your own risk.

* NRF24L01 - Wireless receiver for the Controllers communication

* 5v to 3.3v voltage regulator to power the NRF24 module

* Super bright RGB LED

* White PingPong ball (Vase-mode 3D printed works but it's fragile)


## Display(s)

There's a couple different displays you can use for this headset, anything from 4.5 to 6 inches should work just fine.
*As of right now*, using a phone with ALVR or RiftCat or whatever isn't supported though.

You can find these screens on Aliexpress, but make sure what you're getting is what you think you're getting. Ask the seller if the screen **AND** the driver board support the resolution and refresh rate they advertise.

Most of these screens come with a Blue driver board based around the [Toshiba TC358870XBG](https://toshiba.semicon-storage.com/ap-en/semiconductor/product/interface-bridge-ics-for-mobile-peripheral-devices/hdmir-interface-bridge-ics/detail.TC358870XBG.html), be skeptical of these boards since they support a huge multitude of displays at different refresh rates and resolutions, some sellers even claim they can drive two displays at 90hz.

There's a couple different versions of these blue driver boards, the most common one based around the TOSHIBA chip, the other one based on a clone of said chip.

![8](img/Headset/8.png)

Some screen options are:

### LS055R1SX04 with Green board
With this option you'll have to purchase the [display](https://www.aliexpress.com/item/4000999801804.html) and [board](https://www.aliexpress.com/item/1005002330323719.html) separately. Make sure you choose the right display to go with the right board (LS055R1SX04 lcd won't work with LS055R1SX03 board) and make sure the display has a backlight before purchasing since these are usually used for resin 3d printers.

These screens are 1440x2560(vertical), they officially support up to 60Hz but with the board linked below they can be pushed to around 72hz without artifacts.

The board is meant to run the display at 60hz but it can easily do 72hz if you create a custom resolution in nvidia control panel or amd's driver settings thing.

![10](img/Headset/10.png)

### LS055R1SX04 or LS055R1SX03 Blue board
These screens are 1440x2560(vertical), they officially support up to 60Hz but depending on the driver board they can be pushed to around 65hz without artifacts (this depends on the driver board).

⚠️ Make sure you're getting the correct refresh rate since a lot of sellers sell these boards with a driver board that's programmed to run at only 50hz

These are reasonably cheap since they're commonly used in resin 3d printers and can be found for around 50USD.

You can find these boards by searching with the terms "5.5 LCD MIPI"

![7](img/Headset/7.png)

### Dual AMOLED H381DLN01
These screens are 1080x1200 per eye (2160x1200) and they claim to run at 90Hz.
They use the Blue driver board and the screens are 3.81 inches each and use AMOLED displays.

⚠️ Make sure you're getting the correct refresh rate before buying

⚠️ Make sure the driver splits the image into the two displays and doesn't just display the same image across both displays before buying.

These are a lot more expensive than the last one and can be found for around 170USD for the pair of screens + driver board
You can find these boards by searching with the terms "90Hz VR LCD"

![9](img/Headset/9.png)

### Dual LS029B3SX02
These screens are 1440x1440 per eye (2880x1440) and run at 120hz.
The use a different driver board that uses DisplayPort as a video input and the displays are 2.9 inch IPS LCD.

⚠️ Make sure you're getting the correct refresh rate before buying

These go for around 180USD for the pair of screens and driver board, making them a better purchase than the dual AMOLED if you're looking for high refresh rate.

You can find these boards by searching with the terms "120Hz VR LCD"

![6](img/Headset/6.png)

# Circuit schematic
Circuit pins for the Arduino pro micro are as follows:

![2](img/Headset/2.png)


## ⚠️ IMPORTANT: YOU NEED A 5V TO 3.3V REGULATOR TO POWER THE NRF24 MODULE, ***THE PRO MICRO DOES NOT SUPPLY 3.3V ON ANY OF ITS PINS*** 
# Uploading the firmware

To upload the firmware you will need to have the [FastIMU](https://github.com/LiquidCGS/FastIMU) (also available on the Arduino library manager) and the [RF24 Arduino Library](https://github.com/nRF24/RF24) installed in your [Arduino IDE](https://www.arduino.cc/en/software). 

You can download the required library using the Libraries manager from within the Arduino IDE. The rest of the used libaries are already included in the firmware folder.

The steps to upload the firmware are as follows:

* Open Headset.ino inside the Software/Firmware/Headset folder
* Select "Arduino Leonardo" as the board if you're using an Arduino Pro Micro
* Select the correct COM port for the board
* Press the Upload button, if all goes well, you can move to setting the correct COMPort.

# Getting HID values

To configure the driver you will need the VID and PID values from the board you're using. The easiest way of getting them is going to the Arduino IDE, clicking on tools and clicking on get board info with the HMD plugged in:

![3](img/Headset/3.png)

Do note these values are in HEX so to use them in the driver config file you'll need to convert them to decimal numbers.
to do that you can use websites like [Rapidtables](https://www.rapidtables.com/convert/number/hex-to-decimal.html), just input your VID and PID values one at a time and convert them to decimal numbers.


Once done, you'll get values like these and then all you have to do is load them up in your driver config file. For more details on driver configuration, check out the [driver configuration docs](Driver.md#driver-configuration)

![4](img/Headset/4.png)