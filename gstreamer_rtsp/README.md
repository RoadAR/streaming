# VLC rtsp streamer

## Установка vagrant

Скачать и поставить [vagrant](https://www.vagrantup.com/)

Скачать и поставить [virtualbox](https://www.virtualbox.org/)

Для убунты и других линуксов есть соответствующие пакеты

## Загрузка бокса

`vagrant box add gstreamer_streamer gstreamer_streamer.box`

## Запуск стриминга

Эта директория монтируется в /vagrant, таким образом, видео для вещания нужно кидать сюда

Запуск бокса. Все команды далее должны вызываться из этой директории

`vagrant up`

Вход в бокс

`vagrant ssh`

### Сборка стримера

```
# cd /vagrant
# make
```

### Запуск стрима

`./rtsptest video.avi`

Проверить вещание

`vlc rtsp://127.0.0.1:5554/jpeg`

Вещание также будет работать по сети, нужно заменить 127.0.0.1 на реальный ip хоста

## Остановка бокса

`vagrant halt` или `sudo poweroff` внутри бокса
