#include "music.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>


void Music::backgroundmusic(QString path){
    QUrl url = QUrl(path);
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(url);
    music->setVolume(25);
    music->play();

}

void Music::playsound(QString path){
    QUrl url = QUrl(path);
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(url);
    music->setVolume(100);
    music->play();
}

void Music::randomsound(){
    int val;

    val = rand() % 4 + 1;

    if (val == 1){playsound("qrc:/SoundEffect/Pain-SoundBible.com-1883168362.wav");}
    if (val == 2){playsound("qrc:/SoundEffect/Cry+2.wav");}
    if (val == 3){playsound("qrc:/SoundEffect/Yawn+1.wav");}
    if (val == 4){playsound("qrc:/SoundEffect/Cough2.wav");}
}

void Music::stopmus(){
    music->stop();
}


void Music::pausemusic(){
    music->pause();
}

void Music::playmusic(){
    music->play();
}

//This runs the background music by adding the songs in a playlist
void Music::infinitemusic(QList<QString> list){
    playlist = new QMediaPlaylist();

    QList<int> newlist = randomshuffle(list);

    for (int i = 0; i < newlist.size(); ++i) {
        QUrl url = QUrl(list.at(newlist.at(i)));
        playlist->addMedia(url);
    }
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    musicinf = new QMediaPlayer();
    musicinf->setPlaylist(playlist);
    musicinf->setVolume(30);
    musicinf->play();
}

QList<int> Music::randomshuffle(QList<QString> list){
    QList<int> already;
    int x;
    srand (time(NULL));
    for (int i = 0; i < list.size(); i++){
        x = rand()%list.size();
        srand (time(NULL));
        while (already.contains(x)){
            x = rand()%list.size();
        }
        already.append(x);
    }
    qDebug() << already;
    return already;
}

