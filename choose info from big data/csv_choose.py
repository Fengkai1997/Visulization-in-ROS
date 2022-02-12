#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Feb 11 18:24:59 2022

@author: xu
"""

import os
import pandas as pd

os.chdir('/home/xu/桌面/1/')#path
pd_reader1 = pd.read_csv("02_01.csv")#file_name
pd_reader = pd_reader1[["randomid", "timestamp", "longitude","latitude","courseoverground","km"]]#choose the columns of data
pd_reader.to_csv('0201.csv')


#choose the areas and output data into csv
duis = pd_reader[(pd_reader["km"]>777)&(pd_reader["km"]<784)]
duis.to_csv('duis.csv')

kre = pd_reader[(pd_reader["km"]>759)&(pd_reader["km"]<770)]
kre.to_csv('kre.csv')

neu = pd_reader[(pd_reader["km"]>735)&(pd_reader["km"]<746)]
neu.to_csv('neu.csv')

HKE = pd_reader[(pd_reader["km"]>781)&(pd_reader["km"]<789)]
HKE.to_csv('HKE.csv')

ROR = pd_reader[(pd_reader["km"]>795)&(pd_reader["km"]<804)]
ROR.to_csv('ROR.csv')


#to avoid program crash, write the following steps in another.py
