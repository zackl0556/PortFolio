import seaborn as sns
from sklearn.model_selection import train_test_split
import numpy as np
import matplotlib.pyplot as plt
df= sns.load_dataset("titanic")
#La funcion dropna segun la documentacion de pandas elimina todos los valores no nulos 

df['age']=df['age'].fillna(df['age'].mean()) #las edades que no conocemos la establecemos a la media

df=df.dropna()


#El dataset contiene un informacion sobre los pasajeros como si sobrevivio su genero en que clase estaba si era adulto, y donde iba a embarcar

#usamos el resto de informacion para entrenar el modelo y saber si ha sobrevivido
df['sex']=df['sex'].map({"male":0,"female":1})
df['embarked']=df['embarked'].map({"S":0,"C":1,"Q":2})
df['class']=df['class'].map({"First":0,"Second":1,"Third":2})
df['who']=df['who'].map({"man":0,"woman":1,"child":2})
df["embark_town"]=df['embark_town'].map({"Southampton":0,"Cherbourg":1,"Queenstown":2})
df=df.drop('alive',axis=1)


df=df.drop('deck',axis=1)
X = df.drop('survived', axis=1)#Dejamos solo el resto de informacion
y=df['survived']#aqui hacemos un dataframe con solo si ha sobrevivido o no



X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.2,random_state=42) #separacion de datos de entrenamiento y test 


#Escalamos los datos
from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()
X_train= scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)


#Aplicamos Regresion Logistica
from sklearn.linear_model import LogisticRegression
logreg = LogisticRegression(random_state=42)#creamos un modelo con random state 32

# agrupamos el modelo con los datos
logreg.fit(X_train, y_train)

#hacemos la prediccion con los datos de x_test
ylr_pred = logreg.predict(X_test)

#Aplicamos svm
from sklearn.svm import SVC

svm=SVC(kernel="linear")#creamos un modelo svm con kernel lineal

# agrupamos el modelo con los datos
svm.fit(X_train,y_train)

#hacemos la prediccion con los datos de x_test
ysvm_pred=svm.predict(X_test)

#aplicamos mlp
from sklearn.neural_network import MLPClassifier
#Definimos el modelo mlp con los tamaños del layer 64 neuronas para el primer lado 32 para el otro
mlp = MLPClassifier(hidden_layer_sizes=(64, 32),
                    max_iter=1000, random_state=42)

mlp.fit(X_train,y_train)

ymlp_pred=mlp.predict(X_test)

#aplicamos decisiontree
from sklearn.tree import DecisionTreeClassifier

dtc=DecisionTreeClassifier()

dtc.fit(X_train,y_train)
ydtc_pred=dtc.predict(X_test)
#aplicamos Random Forest
from sklearn.ensemble import RandomForestClassifier

Rf=RandomForestClassifier()

Rf.fit(X_train,y_train)
yrf_pred=Rf.predict(X_test)

#Aplicaaamos xgboost
from xgboost import XGBClassifier

Xgb=XGBClassifier()
Xgb.fit(X_train,y_train)
yxgb_pred=Xgb.predict(X_test)




#Comparamos los modelos
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
print("Accuracy (Regresión Logística):", accuracy_score(y_test, ylr_pred))# Vamos a ver cuanta puntuacion tiene regresion logistica
print("Accuracy (SVM):", accuracy_score(y_test, ysvm_pred))# Vamos a ver cuanta puntuacion tiene svm
print("Accuracy (MLP):", accuracy_score(y_test, ymlp_pred))# Vamos a ver cuanta puntuacion tiene mlp
print("Accuracy (Decision tree):", accuracy_score(y_test, ydtc_pred))# Vamos a ver cuanta puntuacion tiene Decision tree
print("Accuracy (Random Forest):", accuracy_score(y_test, yrf_pred))# Vamos a ver cuanta puntuacion tiene Random Forest
print("Accuracy (XGBoost):", accuracy_score(y_test, yxgb_pred))# Vamos a ver cuanta puntuacion tiene XGBoost







sns.heatmap(confusion_matrix(y_test, ydtc_pred),annot=True)
plt.show()