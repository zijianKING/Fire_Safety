import pandas as pd
import numpy as np
import matplotlib as plt
from datetime import datetime


# load data
df = pd.read_csv('2020 heating the new PTFE line preliminary.csv')
data = df.iloc[:, 2:]

# Convert data & Filtering
length = len(data.loc[:, 'Time'])
time = np.arange(length) * 4
data.loc[:, 'Time'] = time
data = data.set_index('Time')

chemical = data['Acetylene (1000) 191C']
chemical[chemical < 0] = 0

ax = chemical.plot()
fig = ax.get_figure()
fig.savefig('figure.jpg')
