[![Discord](docs/img/Discord.png)](https://discord.gg/h2SFGEbuRH)
Official HadesVR Discord [feel free to join.](https://discord.gg/h2SFGEbuRH)

# HadesVR Remix
HadesVR Remix is a SteamVR compatible VR setup based on original HadesVR. 

My Remixed version aims for more "streamlined" HadesVR experience.

The setup includes DIY Headset and Controllers that emulate HTC vive wands. You can also build the receiver only if you wish to use HadesVR controllers with your pre-existing headset.

HadesVR driver also uses [PSMoveServiceEX](https://github.com/Timocop/PSMoveServiceEx) for the positional tracking of Headset and Controllers, using ping pong balls and different colours of LEDs.

For more information on *everything*, check out the [docs](docs/DocsIndex.md)!

![1](docs/img/headest_no_display.png)

# How does it work and what can it do?

The headset connects to the PC via USB and receives rotation and button data from both controllers wirelessly, while the tracking is done outside-in using Playstation Move Cameras and [PSMoveServiceEX](https://github.com/psmoveservice/PSMoveService).

You can use the setup in: 
* Headset and controllers mode - Headset + Controllers + PSMoveServiceEX Tracking - 6DoF
* Headset only mode - Headset + PSMoveServiceEX - 6DoF
* Headset only mode - Headset - 3DoF
* Controllers only mode - Controllers + [Receiver](docs/RFReceiver.md) - 6DoF


# Custom hardware

As of right now the custom hardware available is:

### ⚠️Both the Basic HMD and Wand Controllers are missing the 3d printable parts right now. 
* [HadesVR Basic HMD PCB](https://github.com/HadesVR/Basic-HMD-PCB) 
* [HadesVR Wand Controllers](https://github.com/HadesVR/Wand-Controller)


### ⚠️Important disclaimer: I **very** very heavily discourage against building the knuckles controller, it's got a whole lot of problems right now that I haven't gotten around to fixing yet, there's problems with the boards and there's problems with the 3d printer models, and there's problems with the reliability of the capacitive sensors of each finger. The index controller is not an easy build: it relies on a lot of SMD components, stuff has to be assambled in order or else you won't be able to flash the bootloader and the 3d printable parts are all a bit crappy and hard to fit together properly. 

### Also there is a bit of an issue with the boards right now which makes it hard to flash the bootloader since AVR's require a crystal to do that for some dumb reason, so I heavily recommend against making the custom Index controllers for now.

#### I'm also working on an easier to build type of controllers that emulate the vive wands, made only out of through hole components though it's not ready yet (mainly missing the 3d printable shell at the moment). With that being said:

Or maybe you want to DIY your own controllers? check out the [Controllers docs](docs/DocsIndex.md#controllers) for building the controllers with regular Arduino boards!


# Patreon
If you'd like to support me, consider subscribing to my [Patreon](https://www.patreon.com/Manollo)