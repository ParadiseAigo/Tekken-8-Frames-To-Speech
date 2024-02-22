# Tekken-8-Frames-To-Speech

> Block any punishable move in Tekken 8 and a voice will tell you how minus it is exactly.

This is what a blocked minus 10 move will sound like: [example](https://github.com/ParadiseAigo/Tekken-8-Frames-To-Speech/blob/master/Tekken-8-Frames-To-Speech/audio/mp3/10.mp3) (click on "View raw" to play it).

## Installation
Download the executable [here](https://github.com/ParadiseAigo/Tekken-8-Frames-To-Speech/releases).

## Usage
Run the executable before or after opening Tekken 8. Restart the program whenever you restart Tekken 8.

## Issues
* When trying to run the .exe for the first time you might get an error that looks something like this: "VCRUNTIME140_1.dll was not found". To fix this error you can download the dll (from [here](https://www.dll-files.com/vcruntime140_1.dll.html)) and place it in the following folder: "C:\Windows\System32"
* False positives: some moves that are very plus on hit will consistently activate the voice even though there is nothing to punish. This however is rare enough and is easy to identify and thus is only slightly annoying at worst.
* False negatives: some punishable moves can cause the next punishable move to go undetected by the program. This only happens in specific situations, usually when many punishable moves are blocked in succession by any player. Just be aware that false negatives are a thing in this program even though it is rare.
