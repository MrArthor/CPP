# Standardize the data attributes for the Iris dataset.
from sklearn.datasets import load_iris
from sklearn import preprocessing
# load the Iris dataset
iris = load_iris()
# separate the data and target attributes
X = iris.data
y = iris.target
print("MEAN OF THE IRIS DATASET: ", int(X.mean()))
print("STANDARD DEVIATION OF THE IRIS DATASET: ", X.std())
# standardize the data attributes
standardized_X = preprocessing.scale(X)
print("STANDARDIZED MEAN OF THE IRIS DATASET: ",int(standardized_X.mean()))
print("STANDARDIZED STANDARD DEVIATION OF THE IRIS DATASET:",standardized_X.std())