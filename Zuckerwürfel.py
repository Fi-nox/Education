"""
Created on Thu Sep 22 17:32:50 2022

@author: Michael Reuscher
"""
#Zuckerwürfelrechner
print("Hallo zum Zuckerwürfelrechner")  
cube = int(input("Bitte die Anzahl der Würfel eingeben um das Programm zu beenden 0 eingeben: "))
while cube != 0:
    layer = 0
    while cube > layer:
        layer = layer + 1
        cube = cube - layer
    else:
        if layer < 50:
            for i in range(layer):
                for y in range(layer-i-1):
                    print(end=" ")
                for str in range(i+1):
                    print("x", end=" ")
                print()           
        else:
            print("Pyramide ist zu groß um sie in der Konsole anzuzeigen.") 
    print("Reihen: " ,layer)
    print("Übrige Würfel: " ,cube)
    cube = int(input("Bitte die Anzahl der Würfel eingeben um das Programm zu beenden 0 eingeben: "))