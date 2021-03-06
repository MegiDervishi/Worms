#ifndef MUSIC_H
#define MUSIC_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSound>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QUrl>
#include <QList>

/*Music Class is responsible for music*/


class Music{
public:
    QUrl url;
    QMediaPlayer * music;
    QMediaPlaylist *playlist;
    QMediaPlayer *musicinf;

void backgroundmusic(QString path);

void playsound(QString path);

void randomsound();

void stopmus();

void playmusic();

void pausemusic();

void infinitemusic(QList<QString> list);

QList<int> randomshuffle(QList<QString> list);

};

#endif // MUSIC_H

