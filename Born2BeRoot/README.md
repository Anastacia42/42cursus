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

Configuring sudo 

Creating the file with sudo configurations

```
sudo touch /etc/sudoers.d/sudoconfig
sudo mkdir /var/log/sudo
sudo nano /etc/sudoers.d/sudoconfig
```
You have to add the following Defaults instructions:

Defaults  secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
Defaults  passwd_tries=3
Defaults  badpass_message="you can choose a message like 'Incorrect password!', for example"
Defaults  logfile="/var/log/sudo/sudo.log"
Defaults  log_input, log_output
Defaults  requiretty


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

- **UFW**

Installing UFW

You have to active ufw and open 4242 port only.
```
sudo apt install ufw
sudo ufw enable
sudo ufw allow 4242
sudo ufw status
```

- **Password Policy**
```
sudo nano /etc/login.defs
```

Replace the next lines: 

PASS_MAX_DAYS 9999 --> PASS_MAX_DAYS  30
PASS_MIN_DAYS 0    --> PASS_MIN_DAYS  2

```
sudo apt install libpam-pwquality
sudo nano /etc/pam.d/common-password
```
Find this line: "password requisite pam_pwquality.so retry=3"
Add this to end of it: "minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root"

- **Netwok**

Turn off your machine and go to VirtualBox software.
Settings --> Network --> Adapter 1 --> Advanced --> Port Forwarding --> Add new rule (green icon on the right side).

It will continue!
