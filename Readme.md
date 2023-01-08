# ESP8266 C++ dev container

I'm never gonna have to setup this shit again. Al hail docker.

This template comes with:

- The hello world project setup
- make is setup
- RTOS sdk is setup
- Tool chain is setup
- All environment variables are setup
- Config for the esp8266 is setup

## Requirements

- [dev container](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)
- [vscode](https://code.visualstudio.com/)
- [docker desktop](https://www.docker.com/products/docker-desktop/)

### Windows requirements

- [wsl2](https://learn.microsoft.com/en-us/windows/wsl/install)
- [ubuntu for wsl](https://linuxhint.com/install_ubuntu_windows_10_wsl/) (you can use this and just use the latest version of ubuntu)
- [usbipd](https://github.com/dorssel/usbipd-win/releases/tag/v2.4.1)

## How to use

In general everything will be the same between operating systems. The differences will be documented after the similar steps.

- Install the [dev container](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) plugin in `vscode`
- Clone this repo
- Open the repo in `vscode`
- Now it should asks if you want to open this project in a `dev container` and you can say yes

Congrats now you can navigate with the terminal to the hello world project and `make` it and `make flash` it.

### Mac/Linux

Should work out of the box.

### Windows

For now I only have a extra step that has to be done for windows. This is related to how the usb devices are shared with the docker container.

#### Usb sharing with docker

- Go end install the latest version of [usbipd](https://github.com/dorssel/usbipd-win/releases/tag/v2.4.1)
- Now run this command

```powershell
 usbipd wsl list
 ```

- Then you will have to find the ESP8266, look for something called on the line of `USB-SERIAL CH340 (COM9)`
- Now you can attach the usb device by using this command]

```powershell
usbipd wsl attach --busid=<set this to whatever bus-id you esp has>
```

Now you can restart your `dev container` in `vscode`.

#### Setup wsl2 with ubuntu

This is very well documented. Just follow the links below.

- [wsl2](https://learn.microsoft.com/en-us/windows/wsl/install)
- [ubuntu for wsl](https://linuxhint.com/install_ubuntu_windows_10_wsl/) (you can use this and just use the latest version of ubuntu)