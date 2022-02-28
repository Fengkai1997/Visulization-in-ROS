#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Feb 25 23:10:44 2022

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
    
    
codes=pd.read_table('Boat_temp.txt',header=None)
for k in range(258):
    codes.loc[14]='std::string path2 ='+'"'+str(ship_id_list[k])+'"'+';'
    codes.loc[20]='const int q='+str(ship_number[k])+';'
    codes.to_csv('Boat_0201_'+str(ship_id_list[k])+'.cpp', sep='|',quoting=csv.QUOTE_NONE,index=False,header=False)
    
    
    
    
    
    
    
    
#list1=["1379243"]
#list2=[8]
#codes=pd.read_table('Boat_temp.txt',header=None)
#codes.loc[14]='std::string path2 ='+'"'+str(list1[0])+'"'+';'
#codes.loc[20]='const int q='+str(list2[0])+';'
#codes.to_csv('Boat_0201_'+str(list1[0])+'.cpp', sep='|',quoting=csv.QUOTE_NONE,index=False,header=False)