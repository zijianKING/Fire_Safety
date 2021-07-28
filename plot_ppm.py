import pandas as pd
import numpy as np
import matplotlib as plt
from datetime import datetime


# load data
read_file = pd.read_table(r'2020 heating the new PTFE line preliminary.prn')

idx = read_file.loc[read_file['CO2 ppm 191c'] > 400].index[0]

result = read_file.loc[read_file.index[idx:]]

#result.to_csv(r'2020 heating the new PTFE line preliminary.csv', index=None)
#df = pd.read_csv('2020 heating the new PTFE line preliminary.csv')

data = result.iloc[:,2:]

data = data.drop('Unnamed: 46',axis=1)

# Convert data & Filtering
length = len(data.loc[:, 'Time'])
time = np.arange(length) * 4
data.loc[:, 'Time'] = time
data = data.set_index('Time')

for col in data.columns:
  chemical = data[col]
  chemical[chemical < 0] = 0
  ax = chemical.plot()
  ax.set_title("PPM Plot for " + col)
  ax.set_ylabel("PPM")
  fig = ax.get_figure()
  fig.savefig(col + ' figure.jpg')
  fig.clear()

