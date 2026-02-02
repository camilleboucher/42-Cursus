_This project has been created as part of the 42 curriculum by cboucher._

# Born2beRoot

## Description
In this project we have to do a linux virtual machine to learn the fundamentals of virtualization, system administration and bash scripting. For the bonus, we will deploy a web server for a wordpress website and I installed netdata who is a monitoring service.

### Choices
I choosed Debian instead of Rocky Linux because at the moment there is a bug with the last version of Rocky Linux with virtualization. Debian is a robust and stable distribution since a lot of years for server and desktop. It uses apt package manager with deb packets.
Rocky is too young but it's a promising distribution and it's the successor of CentOS (the community version of REHL). It uses dnf package manager with rpm packets.

I choosed a 20 Go disk size for an easy partitioning during the installation, the steps are faster for resizing and adding others partitions.
For security, Apparmor is simple and rapid to deploy instead of SELinux who is a better choice for high-security or enterprise but demands more expertise to manage.
For firewall rules, UFW is also simple and fast to use. firewalld is usefull fore complex environments and Fedora based distributions.
For a Type 2 Hypervisor, I choosed VirtualBox because it's a mature application and UFW is Apple oriented. A Type 1 Hypervisor is an optimised kernell especially for virtualizations (Proxmox for exemple).

### Learning concepts
The virtualization is usefull for testing, manage multiples virtual machines, OS and applications in a single real machine.
The TCP protocol is reliable (ex: HTTPS and SSH). The UDP protocol is faster but less reliable because we can loose packets (ex: streaming and online gaming).

## Instructions

### VM Passwords
|   **Disk encryption**   |   **Root user**   | **cboucher user** | **Wordpress** |
|:-----------------------:|:-----------------:|:-----------------:|:-------------:|
| strongPASSWORDindeed%64 | AmeSEXYnIknowit68 |    AnomoraTOF31   |  kikoudu16LOL |

### General commands
1.	Display partitions:
```bash
	lsblk
```
2.	Set a new hostname:
```bash
	hostnamectl set-hostname NAME
```
3.	Manage services:
```bash
	systemctl [status|start|stop|restart] SERVICENAME
	systemctl [is-enabled|enable|disable] cron
```
4.	Connexion via SSH (port 2222):
```bash
	ssh USER@HOST -p PORT
```
5.	apt package manager:
```bash
	apt [install|remove] PACKET1 PACKET2etc
	apt autoremove
```
6.	Manage firewall rules:
```bash
	ufw default deny incoming && ufw default allow outgoing
	ufw allow 4242
	ufw enable
	ufw status numbered
	ufw delete NUMBER_RULE
```
7.	Shut down the virtual machine properly:
```bash
	poweroff
	reboot
```
8.	Create a file hash:
```bash
	sha1sum FILE
```

### Group & Users commands
1.	Add an user (adduser is a script who uses PAM but not useradd who is low-level):
```bash
	adduser USERNAME
	useradd USERNAME
	useradd -mg GROUPNAME USERNAME
```
2.	Add a group:
```bash
	groupadd GROUPNAME
```
3.	Manage users:
```bash
	usermod -aG GROUP1,GROUP2 USER
```
4.	Change user's password:
```bash
	passwd USER
```
5.	List user's groups:
```bash
	groups
	groups USER
```

### Configurations
1.	SSH configuration path:
```bash
	/etc/ssh/ssh_config
```
2.	group configuration path:
```bash
	/etc/group
```
3.	sudo configuration:
```bash
	visudo
```
4.	Default passwords policies:
```bash
	/etc/login.defs
	chage -l USER
	chage [-M|-m] NUMBER_OF_DAYS USER
```
5.	Enforce password policies with libpam-pwquality:
```bash
	/etc/pam.d/common-password
```
6.	Cron configuration:
```bash
	crontab -e
```

## Resources
1.	I relied on Linux (and sysadmin) skills I have already acquired over several years out of passion.
2.	Born2beroot guide:
```bash
	https://github.com/chlimous/42-born2beroot_guide
```
3.	Web research and AI chat for documentation and the script.
