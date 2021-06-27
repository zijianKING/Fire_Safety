import sys
from PyQt5 import QtWidgets, QtCore, QtGui
from PyQt5.QtWidgets import QInputDialog, QFileDialog, QPushButton

class Window(QtWidgets.QMainWindow):

    def __init__(self):
        super(Window, self).__init__()
        self.setGeometry(50, 50, 500, 300)
        self.setWindowTitle("Fire Safety Guide Generation")
        self.setWindowIcon(QtGui.QIcon('pythonlogo.png'))

        openFile = QtWidgets.QAction("&Open File", self)
        openFile.setShortcut("Ctrl+O")
        openFile.setStatusTip('Open File')
        openFile.triggered.connect(self.file_open)

        self.statusBar()

        mainMenu = self.menuBar()
        
        fileMenu = mainMenu.addMenu('&Open File')
        fileMenu.addAction(openFile)

        pybutton = QPushButton('Open File', self)
        pybutton.clicked.connect(self.file_open)
        pybutton.resize(200,32)
        pybutton.move(80, 60)        

        self.home()

    def home(self):

        self.show()

    def file_open(self):
        name = QFileDialog.getOpenFileName(self, 'Open File')
        file1 = open(name[0],'r')
        print(file1)

        #self.editor()

        with file1:
            text = file1.read()
            print(text)
            #self.textEdit.setText(text)

        #dlg.setFilter("Text files (*.txt)")
        #filenames = QStringList()
        #name = QtWidgets.QFileDialog.getOpenFileName(self, 'Open File')


        # Import Sophie's Code
        # Modeloutput = RunSophie()
        #SophieResult = ['toxic','hot']
        SophieResult = ['toxic','hot']
        
        # The dictionary for Guide and Keyword mapping
        Modeloutput = {'toxic':['guide 137.txt','guide 138.txt','guide 139.txt','guide 144.txt'], 'Corrosive':['guide 137.txt'], \
            'explosive':['guide 137.txt','guide 138.txt'],'hot':['guide 137.txt','guide 138.txt','guide 139.txt','guide 144.txt']}

        address = 'C:\\Users\\zijia\\Downloads\\Fire_Safety-openFile\\Fire_Safety-openFile\\'

        filenames = []
        
        for each in SophieResult:
            for guide in Modeloutput[each]:
                    filenames.append(address + guide)
        filenames = list(dict.fromkeys(filenames))

        #name, ok = QInputDialog.getText(self, "Open File", "Enter File Name")
        #print(name)
        data = ""
		
		# Reading data from file1
        for item in filenames:
            with open(item) as fp:
                data += fp.read()
                data += "\n"
            file = open(item,'r')

		#for i in filenames:
		#	file = open(i,'r')
			
        self.editor()

        with file:
            #text = file.read()
            self.textEdit.setText(data)

    def color_picker(self):
        color = QtWidgets.QColorDialog.getColor()
        self.styleChoice.setStyleSheet("QWidget { background-color: %s}" % color.name())

    def editor(self):
        self.textEdit = QtWidgets.QTextEdit()
        self.setCentralWidget(self.textEdit)


    def font_choice(self):
        font, valid = QtWidgets.QFontDialog.getFont()
        if valid:
            self.styleChoice.setFont(font)

    def style_choice(self, text):
        self.styleChoice.setText(text)
        QtWidgets.QApplication.setStyle(QtWidgets.QStyleFactory.create(text))

    def download(self):
        self.completed = 0

        while self.completed < 100:
            self.completed += 0.0001
            self.progress.setValue(self.completed)  
        

    def close_application(self):
        choice = QtWidgets.QMessageBox.question(self, 'Extract!',
                                            "Get into the chopper?",
                                            QtWidgets.QMessageBox.Yes | QtWidgets.QMessageBox.No)
        if choice == QtWidgets.QMessageBox.Yes:
            print("Extracting Naaaaaaoooww!!!!")
            sys.exit()
        else:
            pass
        
        

    
def run():
    app = QtWidgets.QApplication(sys.argv)
    GUI = Window()
    sys.exit(app.exec_())


run()