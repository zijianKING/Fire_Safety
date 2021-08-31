from scripts import *

# generate path for ../scripts
import sys
# print(sys.path[0])
for char in sys.path[0]:
    while sys.path[0][-1] != "\\":
        sys.path[0] = sys.path[0][:-1]
        # print(sys.path[0])
sys.path[0] = sys.path[0] + "scripts"
# print(sys.path[0])

if __name__ == "__main__":
    exec(open(sys.path[0]+'\draw_tables.py').read())
    exec(open('Prediction.py').read())
    # print("hello world")

