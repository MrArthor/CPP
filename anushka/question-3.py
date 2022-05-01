# Standardize the data attributes for the Wine dataset.
from sklearn.datasets import load_wine
from sklearn import preprocessing
# load the wine dataset
wine = load_wine()
# separate the data and target attributes
X = wine.data
y = wine.target
print("MEAN OF THE WINE DATASET: ", int(X.mean()))
print("STANDARD DEVIATION OF THE WINE DATASET: ", X.std())
# standardize the data attributes
standardized_X = preprocessing.scale(X)
print("STANDARDIZED MEAN OF THE WINE DATASET: ",int(standardized_X.mean()))
print("STANDARDIZED STANDARD DEVIATION OF THE WINE DATASET:",standardized_X.std())