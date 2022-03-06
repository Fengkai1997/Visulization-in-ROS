#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Feb 22 13:31:08 2022

@author: xu
"""


import os
import pandas as pd

os.chdir('/home/xu/桌面/Nuess/0201/')#path
neuss_csv = pd.read_csv("neu_01.csv")
neuss = pd.read_csv("neu_01.csv")
#for next step, avoid to delete the neuss
#print(neuss.sample(10))
#a=neuss["randomid"]
ship_id = neuss_csv.drop_duplicates(subset=["randomid"], keep="first", inplace=False)#find all ship ids
ship_id1 = ship_id["randomid"]
ship_id_list = ship_id1.values.tolist()

print(ship_id_list)
n=len(ship_id_list)
print(n)

names = locals()
for i in range(len(ship_id_list)):
    names[str(ship_id_list[i]) + str(i)] = neuss[(neuss["randomid"]==ship_id_list[i])]
    names[str(ship_id_list[i]) + str(i)].to_csv("Boat01_"+str(ship_id_list[i]) + str(i) + '.csv',index=False,)
    
    names['longti' + str(i)] = names[str(ship_id_list[i]) + str(i)][["longitude"]]
    names['longti' + str(i)] = names['longti' + str(i)].T
    names["Boat01_"+str(ship_id_list[i]) +'_long'] = names['longti' + str(i)].values.tolist()
    names["Boat01_"+str(ship_id_list[i])+'_long']= pd.DataFrame(names["Boat01_"+str(ship_id_list[i])+'_long'])
    names["Boat01_"+str(ship_id_list[i])+'_long'].to_csv("Boat01_"+str(ship_id_list[i]) +'_long'+ '.csv',index=False,header = None)

    names['lati' + str(i)] = names[str(ship_id_list[i]) + str(i)][["latitude"]]
    names['lati' + str(i)] = names['lati' + str(i)].T
    names['lati' + str(i)].to_csv("Boat01_"+str(ship_id_list[i]) +'_lati'+ '.csv', header = None,index=False)
    
    names['COG' + str(i)] = names[str(ship_id_list[i]) + str(i)][["courseoverground"]]
    names['COG' + str(i)] = names['COG' + str(i)].T
    names['COG' + str(i)].to_csv("Boat01_"+str(ship_id_list[i]) +'_COG'+ '.csv', header = None,index=False)

    names['time' + str(i)] = names[str(ship_id_list[i]) + str(i)][["timestamp"]]
    names['time' + str(i)] = names['time' + str(i)].T
    names['time' + str(i)].to_csv("Boat01_"+str(ship_id_list[i]) +'_time'+ '.csv', header = None,index=False)