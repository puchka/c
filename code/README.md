These codes was writen to send binary file through canal that allows only text file.
There was a time when I couldn't send data unless from facebook message. They just allowed sending text message.
I found a way to send binary data as texts.

The original code I wrote can be found in Taurre/
I posted my code in a forum and some people sent their version :
taurre, SylafrsOne and rz0 (with many useful comments :))
The codes they proposed can be found in the respective folder (The code proposed by SylafrsOne is in Taurre/ because Taurre given only the encoding code.

The discussion concerning the original code can be found in :
https://openclassrooms.com/forum/sujet/lecture-fichier-en-mode-rb-25466
(in french :))

decode.c
=========

decode a hexadecimal text file to binary file

gcc -o decode decode.c
./decode <input file> <output file>

tiret.c
=======

I encoutered a problem in which facebook put a dash with the text sent.
This C code remove those extra characters.

./gcc -o tiret tiret.c
./tiret <input file> <output file>

encode.c
=========

encode a binary file to an hexadecimal text file

gcc -o encode encode.c
./encode <input file> <output file>

I used one image (sary_.txt) from a marathon in topcoder as an example I've sent via facebook message in that time.