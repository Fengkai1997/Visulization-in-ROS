load('782.mat')%file name 
X=T(976:1181,8:8)%T is the name of variable(table) from mat
Y=T(976:1181,9:9)%9:9choose the data we need 
COG=T(976:1181,10:10)
Time=T(976:1181,2:2)
Xnew=table2cell(X)
Ynew=table2cell(Y)
COGnew=table2cell(COG)
Timenew=table2cell(Time)
X1=reshape(Xnew,1,206) %transpose to one line 
Y1=reshape(Ynew,1,206)
COG1=reshape(COGnew,1,206)
Time1=reshape(Timenew,1,206)
dlmwrite('X782.csv',X1,'precision','%8.10f') %precision 
dlmwrite('Y782.csv',Y1,'precision','%8.10f')
dlmwrite('COG782.csv',COG1,'precision','%8.10f')
writecell(Time1,'Time782.csv') %write string in csv
