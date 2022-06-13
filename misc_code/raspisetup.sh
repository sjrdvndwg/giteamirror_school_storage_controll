#!/bin/bash

apt install mysql-server node npm -y
mkdir -p -v /server
cd /server
git clone https://gitea.puzzle-it.nu/Sjoerd/Shoppie.git &
git clone https://gitea.puzzle-it.nu/Sjoerd/shoppie-backend.git &

cd ./Shoppie && npm run dev &
cd ./shoppie-backend && npm run dev &
