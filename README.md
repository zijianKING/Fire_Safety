## :fire_engine:fireSafety
[![GitHub contributors](https://img.shields.io/github/contributors/CathyF9600/Fire_Safety.svg)](https://github.com/CathyF9600/Fire_Safety/graphs/contributors/)
[![GitHub issues](https://img.shields.io/github/issues/CathyF9600/Fire_Safety.svg)](https://GitHub.com/CathyF9600/Fire_Safety/issues/)
[![GitHub pull-requests](https://img.shields.io/github/issues-pr/CathyF9600/Fire_Safety.svg)](https://GitHub.com/CathyF9600/Fire_Safety/pulls/)

## Project Scope
Summer research project for FASE MIE DORL-Undergrad in University of Toronto <br/>

## Project Site: 
https://github.com/CathyF9600/Fire_Safety

## :octocat:Branches
1. QtCreator_0725: actively developped version
2. cpp_ui: initial version
3. :open_file_folder:[openFile](../openFile/README.md): Python version
4. plot: code that creates chemical ppm plot

## :round_pushpin:To-do
1. second dialog minimize
2. run python in Qt
3. model parameter to reduce run time

## Release Note
1. download all dependencies in requirements.txt
2. sktime currently supports environments with python version 3.6, 3.7, or 3.8
3. PredictionModel/Prediction.py is written on PyCharm 2021, running in VS Code might require change in the format of relative path. For example, `data.to_csv(r'2020 heating the new PTFE line preliminary.csv', index=None)` works on PyCharm while `read_file = pd.read_table(r'PredictionModel/2020 heating the new PTFE line preliminary.prn')` works on VS Code
