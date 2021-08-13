import pandas as pd
# import numpy as np
from chemical_mapping import chemical_mapping
# import matplotlib.pyplot as plt
# from pandas.plotting import table
import dataframe_image as dfi

TARGET_TABLE = r"../data/classification.xlsx"


def draw_rule_based_table(input_file):
    data = chemical_mapping(input_file)
    existing_chemical = set(data.columns)

    target = pd.read_excel(TARGET_TABLE, sheet_name="gases")
    chemicals = target.iloc[:, 0]

    arr = [idx for idx, v in enumerate(chemicals) if (v.upper() in existing_chemical)]

    # print(existing_chemical)
    result = target.iloc[arr, :]
    result = result.rename(columns={'Unnamed: 0': 'Chemicals'})

    # print(result)
    dfi.export(result, 'dataframe.png')


# def save_df_image(df):
#     ax = plt.subplot(111, frame_on=False) # no visible frame
#     ax.xaxis.set_visible(False)  # hide the x axis
#     ax.yaxis.set_visible(False)  # hide the y axis
#
#     table(ax, df)  # where df is your data frame
#
#     plt.savefig('mytable.png')


if __name__ == '__main__':
    input_file = r"../data/2020 heating the new PTFE line preliminary.prn"
    draw_rule_based_table(input_file)