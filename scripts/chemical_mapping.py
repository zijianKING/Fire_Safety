import pandas as pd
import numpy as np
from datetime import datetime


def chemical_mapping(input_file):
    # load data
    read_file = pd.read_table(input_file)

    idx = read_file.loc[read_file['CO2 ppm 191c'] > 400].index[0]

    result = read_file.loc[read_file.index[idx:]]

    # result.to_csv(r'2020 heating the new PTFE line preliminary.csv', index=None)
    # df = pd.read_csv('2020 heating the new PTFE line preliminary.csv')

    data = result.iloc[:, 2:]

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

    return data

