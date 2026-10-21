#!/bin/bash
if [ $# -eq 0 ]
then
text=$'In welches System möchten sie umwandeln?\n1. Binär\n2. Octal\n3. Hexadezimal\n4. Exit'
echo $text
read zahlensystem
echo "Geben Sie Ihre Zahl ein:"
read zahl
case $zahlensystem in
	1 )
		if [ $zahl -lt 0 ]
		then
			echo "-1"
		elif [ $zahl -eq 0 ]
		then
			echo "0"
		else
			zahlBiOne=""
			while [ $zahl -gt 0 ]
			do
				zahlBi=$(($zahl%2))
				zahlBiOne=$zahlBi$zahlBiOne
				zahl=$(($zahl/2))
			done
			echo $zahlBiOne
		fi
		;;
	2)
		if [ $zahl -lt 0 ]
		then
			echo "-1"
		elif [ $zahl -eq 0 ]
		then
			echo "0"
		else
			zahlOcOne=""
			while [ $zahl -gt 0 ]
			do
				zahlOc=$(($zahl%8))
				zahlOcOne=$zahlOc$zahlOcOne
				zahl=$(($zahl/8))
			done
			echo $zahlOcOne
		fi
		;;
	3)
		if [ $zahl -lt 0 ]
                then
                        echo "-1"
                elif [ $zahl -eq 0 ]
                then
                        echo "0"
                else
			zahlHexOne=""
			while [ $zahl -gt 0 ]
			do
				zahlHex=$(($zahl%16))
				if [ $zahlHex -gt 9 ]
				then
				case $zahlHex in
				10)
					zahlHex="A"
					;;
				11)
					zahlHex="B"
					;;
				12)
					zahlHex="C"
					;;
				13)
					zahlHex="D"
					;;
				14)
					zahlHex="E"
					;;
				15)
					zahlHex="F"
					;;
				esac
				fi
				zahlHexOne=$zahlHex$zahlHexOne
				zahl=$(($zahl/16))
				done
				echo $zahlHexOne
		fi
		;;
	4)
		echo "Programm beendet"
		;;
	*)
		echo "ungültige Auswahl"
		;;

esac
else
zahlensystem=$1
zahl=$2
case $zahlensystem in
        1 )
                if [ $zahl -lt 0 ]
                then
                        echo "-1"
                elif [ $zahl -eq 0 ]
                then
                        echo "0"
                else
                        zahlBiOne=""
                        while [ $zahl -gt 0 ]
                        do
                                zahlBi=$(($zahl%2))
                                zahlBiOne=$zahlBi$zahlBiOne
                                zahl=$(($zahl/2))
                        done
                        echo $zahlBiOne
                fi
                ;;
	 2)
                if [ $zahl -lt 0 ]
                then
                        echo "-1"
                elif [ $zahl -eq 0 ]
                then
                        echo "0"
                else
                        zahlOcOne=""
                        while [ $zahl -gt 0 ]
                        do
                                zahlOc=$(($zahl%8))
                                zahlOcOne=$zahlOc$zahlOcOne
                                zahl=$(($zahl/8))
                        done
                        echo $zahlOcOne
                fi
                ;;
	 3)
                if [ $zahl -lt 0 ]
                then
                        echo "-1"
                elif [ $zahl -eq 0 ]
                then
                        echo "0"
                else
                        zahlHexOne=""
                        while [ $zahl -gt 0 ]
                        do
                                zahlHex=$(($zahl%16))
                                if [ $zahlHex -gt 9 ]
                                then
                                case $zahlHex in
                                10)
                                        zahlHex="A"
                                        ;;
                                11)
                                        zahlHex="B"
                                        ;;
                                12)
                                        zahlHex="C"
                                        ;;
                                13)
                                        zahlHex="D"
                                        ;;
                                14)
                                        zahlHex="E"
                                        ;;
                                15)
                                        zahlHex="F"
                                        ;;
                                esac
                                fi
                                zahlHexOne=$zahlHex$zahlHexOne
                                zahl=$(($zahl/16))
                                done
                                echo $zahlHexOne
                fi
                ;;
	 4)
                echo "Programm beendet"
                ;;
        *)
                echo "ungültige Auswahl"
                ;;

esac
fi
