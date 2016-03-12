#!/bin/bash

# Installation script for Task Stalker program
# Options:
# 	-uninstall ; Uninstall the program

trap QUIT INT

QUIT()
{
	echo -e "\n\nInstallation/Uninstallation cancelled (bye!)"
	exit 0
}

function USR_BIN_INSTALL()
{
	if [[ $EUID -ne 0 ]]; then
		echo -e "\nYou must run this install script as root to perform this action!"
		INSTALLATION
	else
		echo -e "\nInstalling to /usr/bin/TaskStalker"
		make

		if [ -f TaskStalker ]; then
			mv TaskStalker /usr/bin/TaskStalker
		fi

		make clean
	fi
}

function LOCAL_INSTALL()
{
	echo -e "\nInstall TaskStalker to local directory"
	make
	make clean
}

function INSTALLATION()
{
	while :
	do
		echo -e "\nEnter '1' to install to /usr/bin,"
		echo "'2' to install to local directory,"
		echo "or '3' to cancel the installation."
		echo -e "\nPlease enter your selection:"

		read SELECTION

		if [ "$SELECTION" == "1" ]; then
			USR_BIN_INSTALL
			break
		elif [ "$SELECTION" == "2" ]; then
			LOCAL_INSTALL
			break
		elif [ "$SELECTION" == "3" ]; then
			QUIT
			break
		else
			echo "Invalid input!"
		fi
	done
}

function UNINSTALLATION()
{
	while :
	do
		echo -e "\nAre you sure you want to uninstall Task Stalker from your system?"
		read ANS

		if [ "$ANS" == "yes" ]; then
			break
		elif [ "$ANS" == "no" ]; then
			QUIT
		else
			echo "Please enter 'yes' or 'no'."
		fi
	done

	make clean

	if [ -f TaskStalker ]; then
		rm TaskStalker
	fi

	if [ -f /usr/bin/TaskStalker ]; then
		if [[ $EUID -ne 0 ]]; then
			echo -e "\nCannot uninstall /usr/bin/TaskStalker; you must be root to perform this action!"
		else
			rm /usr/bin/TaskStalker
		fi
	fi
}

if [ "$1" == "-uninstall" ]; then
	UNINSTALLATION
else
	INSTALLATION
fi
