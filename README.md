# VLC rtsp streamer

## Установка vagrant

Скачать и поставить [vagrant](https://www.vagrantup.com/)
Скачать и поставить [virtualbox](https://www.virtualbox.org/)

Для убунты и других линуксов есть соответствующие пакеты

## Загрузка бокса

`vagrant bot add vlc_streamer vlc_streamer.box`

## Запуск стриминга

Эта директория монтируется в /vagrant, таким образом, видео для вещания нужно кидать сюда

Запуск бокса. Все команды далее должны вызываться из этой директории

`vagrant up`

Вход в бокс

`vagrant ssh`

Запуск стрима

`cvlc -I dummy --vlm-conf /vagrant/vlc_config`

При необходимости, поправить путь к видео в `vlc_config`

Проверить вещание

`vlc rtsp://127.0.0.1:5554/ador`

Вещание также будет работать по сети, нужно заменить 127.0.0.1 на реальный ip хоста

## Остановка бокса

`vagrant halt` или `sudo poweroff` внутри бокса
