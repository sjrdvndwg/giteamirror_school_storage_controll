#!/bin/bash

apt install mysql-server node npm -y
mkdir -p -v /server
cd /server
git clone https://gitea.puzzle-it.nu/School_projecten/Shoppie.git &
git clone https://gitea.puzzle-it.nu/School_projecten/shoppie-backend.git &

cd ./Shoppie && npm run dev &
cd ./shoppie-backend && npm run dev &
