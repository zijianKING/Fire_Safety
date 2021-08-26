## :fire_engine:fireSafety
[![GitHub contributors](https://img.shields.io/github/contributors/CathyF9600/Fire_Safety.svg)](https://github.com/CathyF9600/Fire_Safety/graphs/contributors/)
[![GitHub issues](https://img.shields.io/github/issues/CathyF9600/Fire_Safety.svg)](https://GitHub.com/CathyF9600/Fire_Safety/issues/)
[![GitHub pull-requests](https://img.shields.io/github/issues-pr/CathyF9600/Fire_Safety.svg)](https://GitHub.com/CathyF9600/Fire_Safety/pulls/)

## Project Scope
Source code for the interface that displays hazard icons and strategies for the fire safety project of FASE MIE DORL-Undergrad<br/>

## Project Site: 
https://github.com/CathyF9600/Fire_Safety

## Libraries and dependencies
sktime~=0.7.0
dataframe-image
pandas~=1.1.5
numpy~=1.21.1
matplotlib~=3.4.2
DateTime~=4.3
scikit-learn~=0.24.2

## Release Note
1. download all dependencies in requirements.txt by running `pip install -r requirements.txt` in command line
2. sktime currently supports environments with python version 3.6, 3.7, or 3.8
3. PredictionModel/Prediction.py is written on PyCharm 2021. Running on VS Code might require change in the format of relative path. For example, `data.to_csv(r'2020 heating the new PTFE line preliminary.csv', index=None)` works on PyCharm while `read_file = pd.read_table(r'PredictionModel/2020 heating the new PTFE line preliminary.prn')` works on VS Code
4. Install the latest QtCreator in your machine in order to run *.pro file in folder `cpp_ui`
5. To try out the release version, run the *.exe file in folder `Fire_Safety\cpp_ui\build-FireSafety-Desktop_Qt_5_15_2_MinGW_64_bit-Release`. Let us know if anythiny doesn't work for you

## Branches
1. main: the final version
3. cpp_ui: initial version
4. [openFile](../openFile/README.md): Python version
5. plot: code that creates chemical ppm plot

## [Issues](https://github.com/CathyF9600/Fire_Safety/issues)

## Contact
email yuchun.feng@mail.utoronto.ca
