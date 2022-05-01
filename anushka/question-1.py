import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
f = pd.read_csv("people.csv")
f.index
len(f)

def check_age_range(f) :
    age_range = lambda r : r in range(151)
    print(f["age"].apply(age_range))
    check_age_range(f)
def check_age(f) :
    age_check = lambda r : r[0] > r[1]
    print(f[["age","yearsmarried"]].apply(age_check,axis=1))

check_age(f)
f.status
def check_status(f) :
    status=set(f.status)
    status_check = lambda r : r in status
    print(f["status"].apply(status_check))
check_status(f)
def check_group(f) :
    def group_check(x) :
        if (x[0] in range(18) and x[1]=="child") or (x[0] in range(18,66) and x[1]=="adult") or (x[0]>65
        and x[1]=="elderly") :
            return True
        else :
            return False
        print(f[["age","age_group"]].apply(group_check,axis=1))
check_group(f)
E = {"check_age_range" : check_age_range, "check_age" : check_age, "check_status":
    check_status, "check_group" : check_group}
E["check_age"](f)
#x = []
#for i in E.keys() :
# x.append(E[i](f))
f.loc[0,:]
x = f.plot()
#plt.bar(E.keys(),x)
plt.show()
f.describe()