# Custom Base Stations
<img src="https://github.com/ManoloMancelli/HadesVR_Remix/blob/main/docs/img/base_board.png" width="600">

This is a purely cosmetic mod. No need to do this if you don't have the skills or don't like how it looks.


<img src="https://github.com/ManoloMancelli/HadesVR_Remix/blob/main/docs/img/base_station.png" width="600">

You can get the 3D files [here](https://github.com/ManoloMancelli/HadesVR_Remix/tree/main/3D%20Prints/Base%20Stations)

[![Watch the video](https://github.com/ManoloMancelli/HadesVR_Remix/blob/main/docs/img/yt/base_video.png)](https://youtu.be/boW6VLNxAPs)

# Features

- Full PSMoveServiceEX support
- Fully 3D printable housing
- Removed microphone array
- Tripod mount on the back
- Tripod mount on the bottom
- Tripod mount on the top

# Driver Installation

Download and install [Zadig](https://zadig.akeo.ie/), we'll be using Zadig to install our libusb camera drivers.

Plug in all your cameras and open up Device Manager, you'll probably see something similar to this:

![1](img/Tracking/DrvInstall/1.png)

To install the drivers open up Zadig, select one of the USB cameras, select libusb-win32 as your driver and click install driver.

⚠️ You should only install the driver on the "Interface 0" cameras

![2](img/Tracking/DrvInstall/2.png)

Once it is done installing, select the next camera and repeat the process untill you've installed the drivers for all cameras. If you've done everything correctly, your device manager should look something like this:

![3](img/Tracking/DrvInstall/3.png)

Base Station should be now ready to use with PSMoveServiceEX

Those steps might be necessary to repeat for each Base Station.