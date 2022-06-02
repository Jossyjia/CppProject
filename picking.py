import pandas as pd
data=pd.read_csv("D:\\sdu\\cpp\\project_rebuild\\just_doit\\Lesson.csv",encoding="gbk")
file=open("D:\\sdu\\cpp\\project_rebuild\\just_doit\\selected.txt",'r')
week,order,credit,type=file.read().split()
week=int(week)
order=int(order)
credit=int(credit)
type=int(type)

chosen=data[(data["week"]==week) & (data["order"]==order) & (data["type"]==type) & (data["credit"]==credit)]
#print(chosen)
file=open("D:\\sdu\\cpp\\project_rebuild\\just_doit\selected.txt",'w')
a=list(chosen["Id"])
for i in a:
    file.write(str(i)+'\n')
