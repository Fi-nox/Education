# -*- coding: utf-8 -*-
"""
Created on Tue Apr 26 09:06:54 2022

@author: Michael Reuscher
"""

def Berechnung(Umsatz, Prov_Satz1, Prov_Satz2, Prov_Satz3, Prov_Satz4):
    if (Umsatz < 10000):        
        Ausgabesatz = Prov_Satz1
    elif (Umsatz > 10000 and not Umsatz > 20000):       
        Ausgabesatz = Prov_Satz2
    elif (Umsatz > 20000 and not Umsatz > 50000):        
        Ausgabesatz = Prov_Satz3
    elif (Umsatz > 50000):       
        Ausgabesatz = Prov_Satz4    
    return Umsatz * Ausgabesatz / 100, Ausgabesatz
    
#Provisionssätze   
Prov_Satz1 = 0
Prov_Satz2 = 2.5
Prov_Satz3 = 3.5
Prov_Satz4 = 5
escape = "j"

print("Provisionsberechnung")
while (escape == "j"):
    Umsatz = float(input("Bitte Umsatz in Euro eingeben: "))

    Provisions_Zahlung, Ausgabesatz = Berechnung(Umsatz, Prov_Satz1, Prov_Satz2, Prov_Satz3, Prov_Satz4)

    print("Umsatz: {:.2f}".format(round(Umsatz, 2)).replace(".", ","), "€")
    print("Provisionssatz: {:.2f}".format(round(Ausgabesatz, 2)).replace(".", ","), "%")
    print("Provisionszahlung: {:.2f}".format(round(Provisions_Zahlung, 2)).replace(".", ","), "€")
    escape = input("Weitere Berechnung? j/n: ")
    
if (escape == "n"): 
    print("Programmende")

