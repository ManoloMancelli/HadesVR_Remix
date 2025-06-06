# Official HadesVR Wand Controller

These controllers aim to simulate the original Vive wand controllers. This build uses custom-ordered Wand PCB and off-the-shelf components.

![1](img/wandofficial/wand_controller.png)

# Hardware Setup

1. Order [Wand PCB](https://github.com/ManoloMancelli/HadesVR_Remix/blob/main/Hardware/Wand%20Controllers/Hades%20VR%20Wand%20-%20Original%20Board.zip)

![1](img/wandofficial/wand_pcb.png)

2. Buy Arduino Pro Mini 3.3V 8mHz - Make sure it looks like the one below - Very important!

![1](img/wandofficial/pro_mini.png)

3. Buy one 18650 cell and cell holder

![1](img/wandofficial/cell.png)

# Environment Setup

This guide assumes you have fresh Windows installation on your PC. Anything you have installed previously, might have an impact on this project.

1. Install all of the Windows Updates.

2. Download and install the [CH340 Driver](https://cdn.sparkfun.com/assets/learn_tutorials/8/4/4/CH341SER.EXE)

3. Download [Arduino IDE](https://www.arduino.cc/en/software/)

4. Download [7Zip](https://www.7-zip.org/download.html)

5. Install FastIMU library inside Arduino.

![1](img/fastimu_lib.png)

6. Install RF24 library inside Arduino.

![1](img/rf24_lib.png)

7. Download [Wand Firmware](https://github.com/ManoloMancelli/HadesVR_Remix/tree/main/Software/Firmware%20-%20For%20the%20boards/Official%20HadesVR%20Wand%20-%20Untested)

8. Unpack the Firmware onto your desktop

9. Install [Steam](https://store.steampowered.com/tags/en/Download)

10. Install [SteamVR](https://store.steampowered.com/app/250820/SteamVR/)

11. Install [HadesVR Driver](Driver.md)

# PCB Assembly

1. Solder goldpins to your Arduino Pro Mini

![1](img/wandofficial/pro_mini_pins.png)

2. Solder goldpins to your PCB

![1](img/wandofficial/pcb_pins.png)

3. Solder buttons to your PCB

![1](img/wandofficial/pcb_buttons.png)

4. Solder joystick to your PCB

![1](img/wandofficial/pcb_joystick.png)

5. Glue the cell holder to PCB and solder the voltage wires

![1](img/wandofficial/pcb_cell.png)

6. Solder the Red LED and 68 Ohm resistor. Longer pin of LED goes towards the bottom of the board. Resistor polarity doesn't matter. You can solder it either way.

![1](img/wandofficial/pcb_led.png)

7. Solder the 470nF capacitor - C1. I've used the 0402 SMD version.

![1](img/wandofficial/pcb_c1.png)

8. Solder the 3.3k resistor - R2 and 1k resistor - R1. I've used the 0402 SMD version.

![1](img/wandofficial/pcb_resistor.png)

9. Solder the Gyroscope (MPU) on top of the goldpins. Make sure it's parallel and as close to the PCB as possible.

![1](img/wandofficial/pcb_mpu.png)

10. Solder the Arduino Pro Mini on top of the goldpins. Make sure it's higher than Gyroscope (MPU) and it's not touching it.

![1](img/wandofficial/pcb_pro_mini.png)

11. Shorten the Gyroscope (Mpu) goldpins with tweezers

![1](img/wandofficial/pcb_short_mpu.png)

12. Solder the NRF24 module on top of the goldpins. Make sure it's higher than Gyroscope (MPU) and it's not touching it

![1](img/wandofficial/pcb_nrf.png)

13. Solder a piece of wire between Gyroscope (MPU) capactior and 3V3 pin

![1](img/wandofficial/pcb_3v3.png)

14. Place a jumper on top of SRC and BAT goldpin. I don't have any jumpers right now so I will use a piece of wire instead.

![1](img/wandofficial/pcb_src_goldpin.png)

15. Solder the TP4056 module using goldpin pieces

![1](img/wandofficial/pcb_tp4056.png)

16. Spray whole board with IPA

![1](img/wandofficial/pcb_ipa.png)

17. Brush entire board with toothbrush. Don't use the one for your teeth lol. Semi-hard brush works the best. This will remove any flux from the PCB

![1](img/wandofficial/brush.png)

18. Put the plastic part on top of your joystick

![1](img/wandofficial/joystick_cap.png)

19. Put the 18650 cell into the plastic holder. Make sure to put it in correctly! + goes to + and - goes to -

![1](img/wandofficial/pcb_cell2.png)

20. Connect the USB cable to TP4056 and charge the battery. Red light means that the battery is charging. When it's fully charged, green light will be lit.

![1](img/wandofficial/pcb_charge.png)

# Firmware Preparation

1. Unzip the Firmware onto your desktop

2. Open "Firmware.ino"

3. Change the Gyroscope (IMU) type to the one you used

![1](img/wandofficial/firmware_mpu_type.png)

You can check what type it is directly on your board

![1](img/imu_chip.png)

4. Define whenever this is Right or Left controller

![1](img/wandofficial/firmware_role.png)

5. Define the Battery and Joystick values

![1](img/wandofficial/firmware_battery_joystick.png)

Now the Firmware is ready and you can proceed to next steps

# Firmware Flashing

For this part I will be using separate, Arduino Uno board. You can also use the USBasp programmer but it's far easier to do it with Arduino Uno.

1. Prepare 5 pieces of wire

2. Open Arduino IDE on your PC and connect Arduino Uno with USB.

3. Select Arduino Uno and correct port.

![1](img/wandofficial/uno_port.png)

4. Create a new, empty sketch

5. Upload the sketch to your Arduino Uno

6. Solder the wires to your Arduino Uno board

![1](img/wandofficial/uno_pinout.png)

You should now have something like this

![1](img/wandofficial/uno_wires.png)


7. Unplug the Arduino Uno from your PC

8. Connect the Arduino Uno with wires to your Arduino Pro Mini

![1](img/wandofficial/pro_mini_program_wires.png)

9. Oper "Firmware.ino"

10. Select Arduino Pro Micro 3.3V 8mHz

11. Click Upload

12. When you see "uploading", click the reset button on your Pro Mini board.

13. Wait for the upload to finish

14. (Optional) Remove the goldpin connector

![1](img/wandofficial/pro_mini_goldpin_removed.png)



# Gyroscope Calibration

1. Make sure the controller is turned off

2. While controller is off, press and hold :

 - Left Controller -> Middle and Right button
 - Right Controller -> Middle and Left button

3. While pressing buttons, turn on the controller. Keep buttons pressed.

4. LED will flash two times and turn off. When it does so, place the controller on flat surface

5. Don't touch the controller until LED will light up again and stays lit.

Calibration is now done and controller is ready to go.

# 3D Printed Case

I've designed a super-simple 3D printed case which works with this build.

It's quite chunky since the original HadesVR Wand uses the 18650 cell for battery.

![1](img/wandofficial/wand_controller.png)

1. Download the [3D Files](https://github.com/ManoloMancelli/HadesVR_Remix/tree/main/3D%20Prints/HadesVR%20Official%20Wand%20Housing)

 - If you have Bambu Lab printer like I do. You can get the files directly on [MakerWorld](https://makerworld.com/en/models/1356541-hadesvr-wand#profileId-1400341)

![1](img/wandofficial/makerworld_stl.png)

2. Print the 3D files. I use Bambu Lab P1S. You can use any other 3D printer as long as it's calibrated properly

3. Remove the Controller LED

![1](img/wandofficial/pcb_led_removed.png)

4. Prepare brand-new Red LED.

![1](img/wandofficial/red_led.png)

5. Solder one wire to each Led pin

 - You should as well use heat shrink tubes on your pins. This will prevent any short circuits

![1](img/wandofficial/red_led_wires.png)

6. Thread the LED wires through the Ping Pong hole on your controller. Make sure that LED is about 2cm away from printed part.

![1](img/wandofficial/wire_thread.png)

7. Cover the wire hole with glue so that they won't be able to move and will stay in correct place

![1](img/wandofficial/wire_glue.png)

8. Connect the Led wires to your PCB from underneath the board

![1](img/wandofficial/pcb_led2.png)

9. Put the PCB inside the bottom 3D printed part

![1](img/wandofficial/pcb_bottom_case.png)

10. Prepare Ping Pong ball. Make a 8mm hole with a drill. You can also use a phillips screwdriver.

![1](img/wandofficial/ping_pong_hole.png)

11. Glue the Ping Pong ball on top of the LED

![1](img/wandofficial/ping_pong_led.png)

You should now have something like this

![1](img/wandofficial/wand_ping_pong.png)

![1](img/wandofficial/wand_ping_pong2.png)

12. Remove the Joystick cap

![1](img/wandofficial/joystick_no_cap.png)

13. Place the Top Cover upside down

![1](img/wandofficial/top_cover_upside_down.png)

14. Insert the Joystick cap

![1](img/wandofficial/top_cover_joystick_cap.png)

15. Insert the Buttons

![1](img/wandofficial/top_cover_buttons.png)

16. Carefully insert the PCB with Bottom Cover while top cover is still upside down

![1](img/wandofficial/upside_down.png)














# Troubleshooting

1. Wand works but is detected as Knuckle

 - Make sure that you have correct "Controller Mode" set in HadesVR driver config

![1](img/wand_controller_mode.png)

2. In-game Wand model looks like hand

 - There are no custom models at this point. You are stuck with generic hand model.

3. Rotation is working but controller doesn't move when I wave my hand

 - Wand controller requires PSMoveService EX and PSEye / HadesVR Base Stations to work in 6DoF

4. Joystick is not working properly

 - Make sure you changed the joystick values

![1](img/joystick_values.png)

5. SteamVR shows low controller battery

 - At this moment, there is no battery measurement system. Just ignore it.


