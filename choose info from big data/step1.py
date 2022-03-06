
"""
Created on Fri Feb 11 18:24:59 2022

@author: xu
"""

import os
import pandas as pd

os.chdir('/home/xu/桌面/Nuess/0201/')#path
pd_reader1 = pd.read_csv("02_01.csv")#file_name of original csv file
pd_reader = pd_reader1[["randomid", "timestamp", "longitude","latitude","courseoverground","km","maneuverindicator"]]#choose the KEY columns,one more column for insert the time_24h
time=pd_reader["timestamp"] 
time1=time.str[11:13]#choose the hour of the timestamp
pd_reader.insert(6,'time_24h',time1)#insert one colunm only contain the time in hour for our next step
pd_reader.to_csv('0201.csv')

#choose the areas and input in files
duis = pd_reader[(pd_reader["km"]>777)&(pd_reader["km"]<784)]
duis1 = duis[(pd_reader["time_24h"]=="08")]#choose the hour, for exmample 00,01,02,08,22 and use the"&"for more than 1 hour
duis1.to_csv('duis.csv')

kre = pd_reader[(pd_reader["km"]>759)&(pd_reader["km"]<770)]
kre1 = kre[(pd_reader["time_24h"]=="00")]
kre1.to_csv('kre.csv')

neu = pd_reader[(pd_reader["km"]>735)&(pd_reader["km"]<746)]
neu1 = neu[(pd_reader["time_24h"]=="01")]
neu1.to_csv('neu_01.csv')
neu.to_csv('neu_all.csv')



HKE = pd_reader[(pd_reader["km"]>781)&(pd_reader["km"]<789)]
HKE1 = HKE[(pd_reader["time_24h"]=="00")]
HKE1.to_csv('HKE.csv')

ROR = pd_reader[(pd_reader["km"]>795)&(pd_reader["km"]<804)]
ROR1 = ROR[(pd_reader["time_24h"]=="00")]
ROR1.to_csv('ROR.csv')

#to avoid program crash, write the following steps in another.py