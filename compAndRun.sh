#!/usr/bin/env bash

# Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/)

# Script exit if a command fails:
#set -e

# Script exit if a referenced variable is not declared:
#set -u

# If one command in a pipeline fails, its exit code will be returned as the result of the whole pipeline:
#set -o pipefail

# Activate tracing:
#set -x

function comp()
{
	export OMP_NUM_THREADS=4
	export OMP_SCHEDULE='dynamic'
	export OMP_DYNAMIC='TRUE'
	export OMP_NESTED='TRUE'

	make exectag
}

function clean()
{
	unset OMP_NUM_THREADS
	unset OMP_SCHEDULE
	unset OMP_DYNAMIC
	unset OMP_NESTED

	make clean
}

if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
	echo "Script ${BASH_SOURCE[0]} must run with 'source' command."
	exit -1
fi

if [ -n "$1" ]; then

	if [[ "$1" == "0" ]]; then

		clean

	elif [[ "$1" == "1" ]]; then

		comp

	elif [[ "$1" == "01" ]]; then

		clean
		comp

	else

		echo -e "Unknow option: [$1]"

	fi

else

	echo -e "Usage:"
	echo -e "source ./${BASH_SOURCE[0]} 0\n\tClean project\n"
	echo -e "source ./${BASH_SOURCE[0]} 1\n\tCompile project\n"
	echo -e "source ./${BASH_SOURCE[0]} 01\n\tClean and compile project\n"

fi
