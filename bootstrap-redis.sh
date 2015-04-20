#!/usr/bin/env bash

# redis
apt-get install -y python-software-properties
add-apt-repository -y ppa:chris-lea/redis-server
apt-get update
apt-get install -y redis-server

# setup redis
sed -i 's/bind 127.0.0.1/bind 0.0.0.0/g' /etc/redis/redis.conf
/etc/init.d/redis-server restart
