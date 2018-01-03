#!/bin/bash

# Generates 100 public/private key pairs using ssh-keygen

set -eu

readonly TMP_KEYS="/tmp/keys/"
rm -rf "$TMP_KEYS"
mkdir -p "$TMP_KEYS"

counter=0

while [ "$counter" -lt 100 ]; do
	sub_dir=$(mktemp -d --tmpdir="$TMP_KEYS")
	ssh-keygen -b 1024 -t rsa -f "${sub_dir}/id_rsa" -q -N ""
	(( ++counter ))
done

printf "Times:\n user|system\nshell|children\n"
times