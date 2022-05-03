#Creating the variables needed to configure the crontab
#
#Architecture of VM
architecture=$(uname -a)
#Number of physical processors
physical=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
#Number of virtual processors
virtual=$(grep "^processor" /proc/cpuinfo | wc -l)
#Memory RAM usage and utilization rate as percentage
ram_usage=$(free -m | awk 'NR==2 {print $3}')
ram_total=$(free -m | awk 'NR==2 {printf("%dMB", $2)}')
ram_p=$(free -m | awk 'NR==2 {printf("%.2f%%", $3/$2*100)}')
#Disk usage and utilization rate as percentage
disk_usage=$(df -h --total | awk '$1=="total" {printf("%d", $3*1024)}')
disk_total=$(df -h --total | awk '$1=="total" {printf("%dGb", $2)}')
disk_p=$(df -h --total | awk '$1=="total" {print $5}')
#Utilization rate of processors as percentage
load=$(top -bn1 | grep '^%Cpu' | awk '{printf("%.2f%%", $2+$4)}')
#Date an time of last reboot
boot=$(who -b | awk '{print $4 " " $5}')
#LVMs active
LVM=$(lsblk | grep -c "lvm")
check=$(if [ ${LVM} -eq 0 ]; then echo no; else echo yes; fi)
#Number of active connections
connections=$(cat /proc/net/sockstat | awk '$1=="TCP:" {print $3}')
#Number of users using the server
users=$(users | wc -w)
#IPv4 address of server and MAC (Media Access Control) address
ip=$(hostname -I)
mac=$(ip link | awk '$1=="link/ether" {print $2}')
#Number of commands executed with the sudo program
sudo=$(cat /var/log/sudo/sudo.log | grep "COMMAND" | wc -l)
#
#Formating the output to be executed with wall
wall "
        #Architecture : $architecture
        #CPU physical : $physical
        #vCPU : $virtual
        #Memory Usage : $ram_usage/$ram_total ($ram_p)
        #Disk Usage : $disk_usage/$disk_total ($disk_p)
        #CPU load : $load
        #Last boot : $boot
        #LVM use : $check
        #Connections TCP : $connections ESTABLISHED
        #User log : $users
        #Network : IP $ip ($mac)
        #Sudo : $sudo cmd
"
