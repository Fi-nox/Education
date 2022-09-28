# -*- coding: utf-8 -*-
"""
Created on Tue May  3 14:36:10 2022

@author: Michael Reuscher

Crypto Name

"""
from cryptography.fernet import Fernet
# key = Fernet.generate_key()
key = b"b8MtNgDnsrStuH7WF_qQu2SGB2Q8KXek9w5q1QCmOKs="

f = Fernet(key)

name = input("Bitte gib einen Namen ein der verschlüsselt werden soll: ")


name = bytes(name, encoding = "utf-8")
cname = f.encrypt(name)
print(cname)
cname = ""
print("\n0 eingeben um das Programm zu beenden.")
token = input("Bitte Token eingeben: ")
token = bytes(token, encoding = "utf-8")
print(f.decrypt(token))

