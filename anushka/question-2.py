import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
f = pd.read_csv("dirty_iris.csv")
f.isnull()
f.dropna()
number_complete = len(f.dropna())
number_complete
complete_percent = len(f.dropna())/len(f)
complete_percent
f.fillna(value="NA",inplace=True)
def species_check(f) :
    species = set(["setosa","versicolor","virginica"])
    func = lambda r : r in species
    x = np.array([func(xi) for xi in f["Species"]])
    if (False in x) :
        print("Violation : Invalid species name")
        print(str(len(x) - np.sum(x)) + " violations")
    else :
        print("No Violation")
    return (len(x) - np.sum(x))
species_check(f)
#f.ftypes
temp = pd.read_csv("dirty_iris.csv")
temp.dropna(inplace = True)
def all_positive(f) :
    func = lambda r : r>0
    a = np.array([func(f[xi]) for xi in f.columns[:-1]])
    a = a.reshape(a.shape[0]*a.shape[1])
    if (False in a) :
        print("Violation : Non-positive values present")
        print(str(len(a) - np.sum(a)) + " violations")
    else :
        print("No Violation")
    return (len(a) - np.sum(a))
all_positive(temp)

temp["Petal.Length"]>(2*temp["Petal.Width"])

def check_petal(f) :
    a = np.array(f["Petal.Length"]>(2*f["Petal.Width"]))
    if (False in a) :
        print("Violation : Petal Length is less than twice of Petal Width in some places")
        print(str(len(a) - np.sum(a)) + " violations")
    else :
        print("No Violation")
    return (len(a) - np.sum(a))

check_petal(temp)

def sepal_check(f) :
    a = np.array(f["Sepal.Length"]<=30)
    if (False in a) :
        print("Violation : Sepal Length is greater than 30 cm in some places")
        print(str(len(a) - np.sum(a)) + " violations")
    else :
        print("No Violation")
    return (len(a) - np.sum(a))
sepal_check(temp)

def sepal_petal_check(f) :
    a = np.array(f["Sepal.Length"]>f["Petal.Length"])
    if (False in a) :
        print("Violation : Sepal length is greater than petal length in some places")
        print(str(len(a) - np.sum(a)) + " violations")
    else :
        print("No Violation")
    return (len(a) - np.sum(a))
sepal_petal_check(temp)

rules = {"species_check" : species_check, "all_positive" : all_positive, "check_petal" :
check_petal, "sepal_check" : sepal_check, "sepal_petal_check" : sepal_petal_check}
x = []
for i in rules.keys() :
    x.append(rules[i](temp))
f.loc[0,:]
plt.bar(rules.keys(),x)
plt.show()
f.describe()
temp.describe()
z = []
for i in range(len(temp.columns)-1) :
    z.append(temp[temp.columns[i]])
plt.boxplot(z,labels=temp.columns[:-1],patch_artist=True)
plt.show()