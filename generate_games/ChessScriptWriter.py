#!/usr/bin/env python
# coding: utf-8

#Import libraries

import re
import pandas as pd
import os
import requests
import json
import urllib.request
from pathlib import Path
import subprocess


#Declare Globals
tgtFilePath="./Documents/mygames.csv" #This is the path where the final CSV gets created
moveStartLine = 22 #Moves in chess.com PGNs typically start from the 22nd line for each game
InputPGNDirectory="./Documents/InputPGNs/" #This is the location where the API downloads the PGNs from the archives
OutputPGNDirectory="./Documents/OutputPGNs/"
OutputScriptDirectory = "./Documents/OutputMoveScripts/"
user='datasherlock' #The user for whom the script is intended to run

def importPGNData(filepath):
    """This function returns the data read as a string"""
    with open(filepath) as f:
        return f.readlines()

def mergeMoves(game):
    """This function cleans out the moves and other attributes, removes newlines and formats the list to be converted into a dictionary"""
    game_output = []

    for i in range(len(game)):
        game[i]=game[i].replace('\n','')
        game[i]=re.sub(r'\+', '', game[i]) # remove _+ signs
        game[i]=re.sub(r'\#', '', game[i]) # remove _+ signs
        game_output+=game[i].split()
    return game_output

def create_main_script(move_list, file):
    with open(os.path.join(OutputScriptDirectory,file), 'w') as f: 
        for move in move_list:
            move_start = move[0:2].upper()
            move_end = move[2:].upper()
            f.write(
                "cb.submitMove(\"" + move_start + "\", \"" + move_end + "\"" +");\n" + 
                "cout << '\\n';" +
                "\n\n")

def main():

    for file in os.listdir(InputPGNDirectory):
        args = "--nocomments --noresults --notags --nomovenumbers -Wlalg -o " + \
               os.path.join(OutputPGNDirectory,file) + ' ' +\
               os.path.join(InputPGNDirectory,file)
        print(args)
        os.system(r'Documents\pgn-extract.exe ' + args)
        data = importPGNData(os.path.join(OutputPGNDirectory,file))
        move_list = mergeMoves(data)
        create_main_script(move_list, file.replace("pgn", '')+"txt")

    print("Export Complete!")

#Run Program
if __name__ == "__main__":
    main()