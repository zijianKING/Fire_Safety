## :fire_engine:fireSafety
[![GitHub contributors](https://img.shields.io/github/contributors/CathyF9600/Fire_Safety.svg)](https://github.com/CathyF9600/Fire_Safety/graphs/contributors/)
[![GitHub issues](https://img.shields.io/github/issues/CathyF9600/Fire_Safety.svg)](https://GitHub.com/CathyF9600/Fire_Safety/issues/)
[![GitHub pull-requests](https://img.shields.io/github/issues-pr/CathyF9600/Fire_Safety.svg)](https://GitHub.com/CathyF9600/Fire_Safety/pulls/)

## Project Scope
Source code for the interface that displays hazard icons and strategies for the fire safety project of FASE MIE DORL-Undergrad<br/>

## Project Site: 
https://github.com/CathyF9600/Fire_Safety

## Libraries and Dependencies
sktime~=0.7.0<br/>
dataframe-image<br/>
pandas~=1.1.5<br/>
numpy~=1.21.1<br/>
matplotlib~=3.4.2<br/>
DateTime~=4.3<br/>
scikit-learn~=0.24.2<br/>

## Release Note
1. Download all dependencies in requirements.txt by running `pip install -r requirements.txt` in command line.
2. A virtual environment is preferred. You can, for example, build it on PyCharm with "Add Python Interpreter" -> "Virtualenv Environment".
3. Please paste the path to your own Python Interpreter (virenv allowed) onto line 32 in `Fire_Safety/cpp_ui/mainwindow.cpp` in order to get C++ run your Python file.
4. Sktime currently supports environments with python version 3.6, 3.7, or 3.8. If importing sktime cannot be resolved, try compile it locally with the instruction [here](https://www.sktime.org/en/latest/installation.html).
5. PredictionModel/Prediction.py is written on PyCharm 2021. Running on VS Code might require change in the format of relative path. For example, `data.to_csv(r'2020 heating the new PTFE line preliminary.csv', index=None)` works on PyCharm while `read_file = pd.read_table(r'PredictionModel/2020 heating the new PTFE line preliminary.prn')` works on VS Code
6. Install the latest QtCreator in your machine in order to run *.pro file in folder `cpp_ui`
7. To try out the release version, run the *.exe file in folder `Fire_Safety\cpp_ui\build-FireSafety-Desktop_Qt_5_15_2_MinGW_64_bit-Release`. Let us know if anythiny doesn't work for you

## Documentation
[Abstract](https://github.com/CathyF9600/Fire_Safety/blob/main/abstract.pdf)


## Branches
1. main: the final version
3. cpp_ui: initial version
4. [openFile](../openFile/README.md): Python version
5. plot: code that creates chemical ppm plot

## [Issues](https://github.com/CathyF9600/Fire_Safety/issues)

## Contact
email yuchun.feng@mail.utoronto.ca
