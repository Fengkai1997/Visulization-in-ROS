import os
import shapefile as shp
from matplotlib import pyplot as plt
import pandas as pd
#openpart
os.chdir('/home/1/')
#drawpart
#border_shp=shp.Reader("COALNE.shp")
border_shp=shp.Reader("wtwaxs.shp")
#border_shp=shp.Reader("780.shp") 18 11 20
border=border_shp.shapes()
border_points = border[0].points # sublayer choose
x,y = zip(*border_points)
fig,ax=plt.subplots()
ax.plot(x,y,"k-") 
ax.grid()
ax.axis("equal")
plt.show()
