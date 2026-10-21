#!/bin/bash
if [ $# -eq 0 ]
	then
	echo "Welches Zahlensystem möchtest du umwandeln? O.Octal D.Dezimal H.Hexadezimal 4.Exit"
	read zahlensystem

	echo "Welche Zahl möchtest du umwandeln"
	read zahl

	if [ $zahl -lt 0 ]
 		then
		echo -1
	fi
	if [ $zahl -eq 0 ]
		then
		echo 0
	fi
	laenge=${#zahl}
	index="0"
	ungueltig="0"
	case $zahlensystem in

		O)
			zahlOctal=""
			while [ $index -lt $laenge ]
			do 
				case ${zahl:$index:1} in

					8) echo "ungültige Zahl"
					ungueltig="1"
					;;
					9) echo "ungültige Zahl"
					ungueltig="1"
					;;
					A) echo "ungültige Zahl"
					ungueltig="1"
					;;
					B) echo "ungültige Zahl"
					ungueltig="1"
					;;
					C) echo "ungültige Zahl"
					ungueltig="1"
					;;
					D) echo "ungültige Zahl"
					ungueltig="1"
					;;
					E) echo "ungültige Zahl"
					ungueltig="1"
					;;
					F) echo "ungültige Zahl"
					ungueltig="1"
					;;
				esac
				index=$(($index+1))
			done
			if [ $ungueltig -eq 0 ]
			then
				index="0"
				while [ $index -lt $laenge ]
				do 	
					case ${zahl:$index:1} in

						0) zahlOctal=$zahlOctal"000"
						;;
						1) zahlOctal=$zahlOctal"001"
						;;
						2) zahlOctal=$zahlOctal"010"
						;;
						3) zahlOctal=$zahlOctal"011"
						;;
						4) zahlOctal=$zahlOctal"100"
						;;
						5) zahlOctal=$zahlOctal"101"
						;;
						6) zahlOctal=$zahlOctal"110"
						;;
						7) zahlOctal=$zahlOctal"111"
						;;
					esac
					index=$(($index+1))
				done
				echo $zahlOctal
			fi
			;;
		D)
			zahlDezimal=""
			while [ $index -lt $laenge ]
			do
				case ${zahl:$index:1} in
					A) echo "ungültige Zahl"
					ungueltig="1"
					;;
					B) echo "ungültige Zahl"
					ungueltig="1"
					;;
					C) echo "ungültige Zahl"
					ungueltig="1"
					;;
					D) echo "ungültige Zahl"
					ungueltig="1"
					;;
					E) echo "ungültige Zahl"
					ungueltig="1"
					;;
					F) echo "ungültige Zahl"
					ungueltig="1"
					;;
				esac
				index=$(($index+1))
			done
			if [ $ungueltig -eq 0 ]
			then
				while [ $zahl -gt 0 ]
				do
					zahlDezimalOne=$(($zahl%2))
					zahlDezimal=$zahlDezimalOne$zahlDezimal
					zahl=$(($zahl/2))
				done
				echo $zahlDezimal
			fi
			;;
		 H)
			zahlHexadezimal=""
			while [ $index -lt $laenge ]
			do
				case ${zahl:$index:1} in
				0) zahlHexadezimal=$zahlHexadezimal"0000"
				;;
				1) zahlHexadezimal=$zahlHexadezimal"0001"
				;;
				2) zahlHexadezimal=$zahlHexadezimal"0010"
				;;
				3) zahlHexadezimal=$zahlHexadezimal"0011"
				;;
				4) zahlHexadezimal=$zahlHexadezimal"0100"
				;;
				5) zahlHexadezimal=$zahlHexadezimal"0101"
				;;
				6) zahlHexadezimal=$zahlHexadezimal"0110"
				;;
				7) zahlHexadezimal=$zahlHexadezimal"0111"
				;;
				8) zahlHexadezimal=$zahlHexadezimal"1000"
				;;
				9) zahlHexadezimal=$zahlHexadezimal"1001"
				;;
				A) zahlHexadezimal=$zahlHexadezimal"1010"
				;;
				B) zahlHexadezimal=$zahlHexadezimal"1011"
				;;
				C) zahlHexadezimal=$zahlHexadezimal"1100"
				;;
				D) zahlHexadezimal=$zahlHexadezimal"1101"
				;;
				E) zahlHexadezimal=$zahlHexadezimal"1110"
				;;
				F) zahlHexadezimal=$zahlHexadezimal"1111"
				;;
				esac
				index=$(($index+1))
			done
			echo $zahlHexadezimal
			;;
		4) echo "exit"
		;;
		*) echo "ungültige Auswahl"
		;;
		esac
	else 
	zahl=$2
	zahlensystem=$1
	if [ $zahl -lt 0 ]
 		then
		echo -1
	fi
	if [ $zahl -eq 0 ]
		then
		echo 0
	fi
	laenge="${#zahl}"
	index="0"
	ungueltig="0"
	case $zahlensystem in

		O)
			zahlOctal=""
			while [ $index -lt $laenge ]
			do 	
				case ${zahl:$index:1} in
				
					8) echo "ungültige Zahl"
					ungueltig="1"
					;;
					9) echo "ungültige Zahl"
					ungueltig="1"
					;;
					A) echo "ungültige Zahl"
					ungueltig="1"
					;;
					B) echo "ungültige Zahl"
					ungueltig="1"
					;;
					C) echo "ungültige Zahl"
					ungueltig="1"
					;;
					D) echo "ungültige Zahl"
					ungueltig="1"
					;;
					E) echo "ungültige Zahl"
					ungueltig="1"
					;;
					F) echo "ungültige Zahl"
					ungueltig="1"
					;;
				esac
				index=$(($index+1))
			done
			if [ $ungueltig -eq 0 ]
			then
				index="0"
				while [ $index -lt $laenge ]
				do 	
					case ${zahl:$index:1} in

						0) zahlOctal=$zahlOctal"000"
						;;
						1) zahlOctal=$zahlOctal"001"
						;;
						2) zahlOctal=$zahlOctal"010"
						;;
						3) zahlOctal=$zahlOctal"011"
						;;
						4) zahlOctal=$zahlOctal"100"
						;;
						5) zahlOctal=$zahlOctal"101"
						;;
						6) zahlOctal=$zahlOctal"110"
						;;
						7) zahlOctal=$zahlOctal"111"
						;;
					esac
					index=$(($index+1))
				done
				echo $zahlOctal
			fi
			;;
		D)
			zahlDezimal=""
			while [ $index -lt $laenge ]
			do
				case ${zahl:$index:1} in
					A) echo "ungültige Zahl"
					ungueltig="1"
					;;
					B) echo "ungültige Zahl"
					ungueltig="1"
					;;
					D) echo "ungültige Zahl"
					ungueltig="1"
					;;
					E) echo "ungültige Zahl"
					ungueltig="1"
					;;
					F) echo "ungültige Zahl"
					ungueltig="1"
					;;
				esac
				index=$(($index+1))
			done
			if [ $ungueltig -eq 0 ]
			then
				while [ $zahl -gt 0 ]
				do
					zahlDezimalOne=$(($zahl%2))
					zahlDezimal=$zahlDezimalOne$zahlDezimal
					zahl=$(($zahl/2))
				done
				echo $zahlDezimal
			fi
			;;
		 H)
			zahlHexadezimal=""
			while [ $index -lt $laenge ]
			do
				case ${zahl:$index:1} in
				0) zahlHexadezimal=$zahlHexadezimal"0000"
				;;
				1) zahlHexadezimal=$zahlHexadezimal"0001"
				;;
				2) zahlHexadezimal=$zahlHexadezimal"0010"
				;;
				3) zahlHexadezimal=$zahlHexadezimal"0011"
				;;
				4) zahlHexadezimal=$zahlHexadezimal"0100"
				;;
				5) zahlHexadezimal=$zahlHexadezimal"0101"
				;;
				6) zahlHexadezimal=$zahlHexadezimal"0110"
				;;
				7) zahlHexadezimal=$zahlHexadezimal"0111"
				;;
				8) zahlHexadezimal=$zahlHexadezimal"1000"
				;;
				9) zahlHexadezimal=$zahlHexadezimal"1001"
				;;
				A) zahlHexadezimal=$zahlHexadezimal"1010"
				;;
				B) zahlHexadezimal=$zahlHexadezimal"1011"
				;;
				C) zahlHexadezimal=$zahlHexadezimal"1100"
				;;
				D) zahlHexadezimal=$zahlHexadezimal"1101"
				;;
				E) zahlHexadezimal=$zahlHexadezimal"1110"
				;;
				F) zahlHexadezimal=$zahlHexadezimal"1111"
				;;
				esac
				index=$(($index+1))
			done
			echo $zahlHexadezimal
			;;

		*) echo "ungültige Eingabe"
		;;
		esac
	fi
