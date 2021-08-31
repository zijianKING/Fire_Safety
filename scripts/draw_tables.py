import pandas as pd
from chemical_mapping import chemical_mapping
import dataframe_image as dfi

TARGET_TABLE = r"../data/classification.xlsx"


def draw_rule_based_table(input_file):
    data = chemical_mapping(input_file)
    existing_chemical = set(data.columns)

    target = pd.read_excel(TARGET_TABLE, sheet_name="gases", engine='openpyxl')
    chemicals = target.iloc[:, 0]

    arr = [idx for idx, v in enumerate(chemicals) if (v.upper() in existing_chemical)]

    # print(existing_chemical)
    result = target.iloc[arr, :]
    result = result.rename(columns={'Unnamed: 0': 'Chemicals'})

    # print(result)
    dfi.export(result, 'dataframe.png')
    print("Rule-based prediction model is done.\n")


if __name__ == '__main__':
    input_file = r"../data/2020 heating the new PTFE line preliminary.prn"
    draw_rule_based_table(input_file)