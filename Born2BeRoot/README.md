# Born2BeRoot

The objective of this project is to create a virtual machine with selected operating system on specified configurations.


Operating system: Linux - Debian 64-bit

Storage must be manipulated using LVM's, including the bonus part, where the configuration of each partition is done manually.


Machine's configurations imply sudo, ssh, ufw, password policy, users, group and crontab configuration.

- **Sudo**

Installing sudo.
Run this command to go to root.
```
su -
```
Then you use apt to install the sudo program
```
apt install sudo
```
Adding users to sudo group
```
adduser username sudo
```
Then reboot to update
```
sudo reboot
```
To verify the installation of sudo
```
sudo -v
```
Adding groups and users to other groups
```
sudo addgroup user42
sudo adduser username user42
sudo apt update
```

- **SSH**

Installing SSH
```
sudo apt install openssh-server
```
Configuring SSH
```
sudo nano /etc/ssh/sshd_config
```
Change the line "#Port22" to "Port4242" and the line "#PermitRootLogin prohibit-password" to "PermitRootLogin no"
```
sudo nano /etc/ssh/ssh_config
```
Change the line "#Port22" to "Port4242"

It will continue...
