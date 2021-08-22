import numpy as np
import pandas as pd


def plot_ppm(file_name):
    read_file = pd.read_table(file_name)
    idx = read_file.loc[read_file['CO2 ppm 191c'] > 400].index[0]

    result = read_file.loc[read_file.index[idx:]]
    data = result.iloc[:, 2:]

    data = data.drop('Unnamed: 46', axis=1)

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
        # fig.savefig(col + ' figure.jpg')
        fig.clear()

    with open('chemicals.txt', 'w') as f:
        for col in data.columns:
            f.write(col)
            f.write('\n')


if __name__ == '__main__':
    file_name = r'../data/2020 heating the new PTFE line preliminary.prn'
    plot_ppm(file_name)
