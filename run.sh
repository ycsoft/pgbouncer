#!/bin/sh
export DOMAIN="hf-soft"
export HOSTIP="139.196.165.107"
export USR="yang"
export PASSWD="yang"

 ./pgbounder/bin/pgbouncer -v pgbounder/conf/pgbouncer.ini 
