import pandas as pd
data=pd.read_csv("D:\sdu\cpp\project_rebuild\just_doit\Lesson.csv")
week,order,credit,type=input().split()
week=int(week)
order=int(order)
credit=int(credit)
type=int(type)

chosen=data[(data["week"]==week) & (data["order"]==order) & (data["type"]==type) & (data["credit"]==credit)]
#print(chosen)
a=list(chosen["Id"])
for i in a:
    print(i)

