import argparse
import os
import struct

path = os.getcwd() +'\\music'
args = argparse.ArgumentParser()
args.add_argument('-d', type = bool, default = False)
parser = args.parse_args()

class Task1(object):

    list_music = []

    def __init__(self):
        self.__bit = 16
        self.__files = os.listdir(path=path)

    def decoding(self):
        for file in self.__files:
            with open(path +'\\' + file, 'rb') as file:
                file.seek(-128, 2)
                track = MusicTrack()
                track.header, track.title, track.artist, track.album, track.year, track.comment, track.genre = struct.unpack("!!!!3s30s30s30s4s30!sb", file.read())
                self.list_music.append(track)
                del track
        print('\tНазвание  -  Исполнитель  -  Альбом\n')
        for track in self.list_music:
            print('[ ' + track.artist.decode('windows-1251').rstrip('\x00') + ' ]  -  [ ' + track.title.decode('windows-1251').rstrip('\x00') + ' ]  -  [ ' + track.album.decode('windows-1251').rstrip('\x00') + ' ]')


class MusicTrack(object):
    header = ""
    title = ""
    artist = ""
    album = ""
    year = ""
    comment = ""
    genre = ""
