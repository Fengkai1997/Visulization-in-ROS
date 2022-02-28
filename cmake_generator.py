#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Feb 26 00:01:01 2022

@author: xu
"""



import os
import pandas as pd
import csv


os.chdir('/home/xu/桌面/Nuess/Boat_neuss_0201/')#path
neuss_csv = pd.read_csv("neu_0201.csv")
neuss = pd.read_csv("neu_0201.csv")
#for next step, avoid to delete the neuss
#print(neuss.sample(10))
#a=neuss["randomid"]
ship_id = neuss_csv.drop_duplicates(subset=["randomid"], keep="first", inplace=False)#find all ship ids
ship_id1 = ship_id["randomid"]
ship_id_list = ship_id1.values.tolist()

print(ship_id_list)
n=len(ship_id_list)
print(n)
ship_number=[]
names = locals()
for i in range(len(ship_id_list)):
    names[str(ship_id_list[i]) + str(i)] = neuss[(neuss["randomid"]==ship_id_list[i])]  
    names['longti' + str(i)] = names[str(ship_id_list[i]) + str(i)][["longitude"]]
    names[str(ship_id_list[i])] = names['longti' + str(i)].shape[0]
    ship_number.append(names[str(ship_id_list[i])])


with open("cmake.txt","w") as f:
    for k in range(258):
        f.write("add_executable(Boat_0201_"+str(ship_id_list[k])+" src/Boat_0201_"+str(ship_id_list[k])+".cpp)")
        f.write('\r\n')
        f.write("target_link_libraries(Boat_0201_"+str(ship_id_list[k])+" ${catkin_LIBRARIES})")
        f.write('\r\n')
        
with open("ship.txt","w") as f: 
    f.write("<launch>")
    f.write('\r\n')
    for j in range(258):
        f.write('<node name="Boat_0201_'+str(ship_id_list[j])+'" pkg="areas736_745" type="Boat_0201_'+str(ship_id_list[j])+'" output="screen"/>')
        f.write('\r\n')
    f.write("</launch>")