import pandas as pd
import numpy as np
import matplotlib as plt
from datetime import datetime
import numpy as np
import pandas as pd
import os
from sktime.transformations.panel.rocket import Rocket
from sklearn.linear_model import RidgeClassifierCV
from sktime.classification.interval_based._cif import CanonicalIntervalForest
from sklearn import metrics
from sklearn.pipeline import Pipeline
from sktime.utils.data_io import load_from_tsfile_to_dataframe
from sktime.transformations.panel.compose import ColumnConcatenator
from sktime.classification.interval_based import TimeSeriesForestClassifier
import dataframe_image as dfi
from sklearn.preprocessing import OneHotEncoder
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split, KFold
import os

'''
Part 1: Data Load
'''
read_file = pd.read_table(r'2020 heating the new PTFE line preliminary.prn')

idx = read_file.loc[read_file['CO2 ppm 191c'] > 400].index[0]

result = read_file.loc[read_file.index[idx:]]

data = result.iloc[:,2:]

# Convert data & Filtering
length = len(data.loc[:, 'Time'])
time = np.arange(length)
data.loc[:, 'Time'] = time
data = data.set_index('Time')

for col in data.columns:
  chemical = data[col]
  chemical[chemical < 0] = 0

data.columns = data.columns.str.split().str[0]
data.columns = data.columns.str.upper()

# The columns that ML Model used for prediction
PredictionSource = ['CH4','HEPTANE','CO2','CO','NO','ACETYLENE','CO2PPM','ETHYLENE','FORMICACID',\
             'N2O','BENZENE','HCN','TOLUENE','DIESEL','SO2','CO2%','NAPHTHALENE','HCL','PHENOL',\
             'STYRENE','COCL2','FORMALDEHYDE','METHYLMETACRYLATE','NAPHTHAL','NO2','ACRYLONITRILE',\
             'PROPANE','PROPYLENE','METHANOL','PROPANE','TRACES','NH3','METHANE','ETHANE','PHOSGENE',\
             'HNCO','AMMONIA']

# Append the missing columns required
for each in PredictionSource:
  if each not in data.columns:
    data[str(each)] = 0

data = data[PredictionSource]

# Remove duplicate
data = data.loc[:,~data.columns.duplicated()]

data.to_csv(r'2020 heating the new PTFE line preliminary.csv', index=None)

data = pd.read_csv("2020 heating the new PTFE line preliminary.csv")

df_strings = data.to_string(header=False,
                  index=False,
                  index_names=False).split('\n')
df_list = [','.join(ele.split()) for ele in df_strings]

#convert time series to a long string separated by colons, including label
ts_for_test = ':'.join(map(str, df_list))

path = os.path.dirname(os.path.abspath("__file__"))
print(path)
#change this to your csv file.
#multi_index_ftir_df = pd.read_csv("multi_index_ftir_df_equal_length.csv", index_col=[0,1])#, skipinitialspace=True)
#experiment_names = set(multi_index_ftir_df.index.get_level_values('Experiment'))

name_of_test = '2020 heating the new PTFE line preliminary'

def write_to_file(path, data, name_of_test):
    file_name = path + '\\ts_real_time_prediction' + str(name_of_test) + '.txt'
    with open(file_name, 'w') as file:
        file.write("# Data file for the real-time hazard prediction.\n")

        file.write(f"@problemName NRC \n")
        file.write(f"@timeStamps False\n")
        file.write(f"@univariate False\n")

        file.write(f"@equalLength true\n")
        file.write(f"@classLabel False\n")
        file.write("\n")

        # begin writing the core data for each case
        # which are the series and the class value list if there is any
        file.write("@data\n")
        for item in [data]:
            file.write("%s\n" % item)

write_to_file(path, ts_for_test, name_of_test)


def predict_rocket(input, directory):
  """
  Inputs:
  - test_data_realtime: the test instance, pre-processed to be in time-series format
  - directory: location of the train and test files

  Output:
  - prediction: a dictionary of prediction results. Keys are the hazard categories, values are 0 (='No') or 1 (='Yes')
  """
  #print("reading data...")
  #directory = os.path.dirname(os.path.abspath("__file__"))
  #X_train, y_train = load_from_tsfile_to_dataframe(directory + '\\sktime\\datasets\\data\\NRC\\ts_flammability_train.txt')
  #X_test, y_test = load_from_tsfile_to_dataframe(directory + '\\sktime\\datasets\\data\\NRC\\ts_flammability_test.txt')
  hazard_categories =['flammability', 'toxicity', 'explosivity', 'water extinguishable', 'corrosive', 'oxidizing']
  directory = os.path.dirname(os.path.abspath("__file__"))
  results = pd.DataFrame(columns = ['ROCKET Train', 'Rocket Test',
                                    'CIF Train', 'CIF Test',
                                    'TSF Train', 'TSF Test'], index = hazard_categories)

  predictions = {}
  for hazard in hazard_categories:
      print("hazard category: ", hazard)
      X_train, y_train = load_from_tsfile_to_dataframe(
                                                        'ts_' + hazard + '_train.txt')

      X_test, y_test = load_from_tsfile_to_dataframe(
                                                        'ts_' +hazard + '_test.txt')

      #ROCKET
      rocket = Rocket()
      rocket.fit(X_train)
      X_train_transform = rocket.transform(X_train)
      X_test_transform = rocket.transform(X_test)

      classifier = RidgeClassifierCV(alphas=np.logspace(-3, 3, 10), normalize=False)
      classifier.fit(X_train_transform, y_train)

      test_data_realtime = rocket.transform(X_test)
      score = classifier.score(X_test_transform, y_test)

      #results.loc[hazard]['ROCKET Train'] =  classifier.score(X_train_transform, y_train)
      #results.loc[hazard]['Rocket Test'] =  classifier.score(X_test_transform, y_test)

      #not sure if the real time prediction test case needs to be transformed....
      test_data = load_from_tsfile_to_dataframe(input)
      input_transform = rocket.transform(test_data)

      #to make predictions, use the following line:
      predictions[hazard] = classifier.predict(input_transform)

  return predictions

test_data_realtime = "ts_real_time_prediction2020 heating the new PTFE line preliminary.txt"
directory = os.path.dirname(os.path.abspath("__file__"))
print(directory)

PredictResult = predict_rocket(test_data_realtime, directory)

PredictResult

result = pd.DataFrame.from_dict(PredictResult)

result

result.index = ['Prediction Result']

result = result.replace('0','no').replace('1','yes')

dfi.export(result, 'predictionResult.png')
