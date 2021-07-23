import sys
from PyQt5 import QtWidgets, QtCore, QtGui
from PyQt5.QtWidgets import QInputDialog, QFileDialog, QPushButton, QVBoxLayout, QWidget, QGridLayout, QHBoxLayout, \
    QLineEdit
from PyQt5.QtGui import QIcon, QPixmap, QTextCursor
from PyQt5.QtWidgets import QLabel, QTextEdit


class Window(QtWidgets.QMainWindow):

    def __init__(self):
        super(Window, self).__init__()

        layout = QHBoxLayout()
        self.setLayout(layout)

        self.edits = [QLineEdit(self) for _ in range(3)]
        for edit in self.edits:
            layout.addWidget(edit)

        self.setGeometry(50, 50, 500, 300)
        self.setWindowTitle("Fire Safety Guide Generation")
        self.setWindowIcon(QtGui.QIcon('pythonlogo.png'))

        openFile = QtWidgets.QAction("&Open File", self)
        openFile.setShortcut("Ctrl+O")
        openFile.setStatusTip('Open File')
        openFile.triggered.connect(self.file_open)

        mainMenu = self.menuBar()
        fileMenu = mainMenu.addMenu('&Open File')
        fileMenu.addAction(openFile)

        self.pybutton = QPushButton('Open File', self)
        self.pybutton.clicked.connect(self.file_open)
        self.pybutton.resize(200, 32)
        self.pybutton.move(80, 60)

        self.home()

    def home(self):
        self.show()

    def file_open(self):
        name = QFileDialog.getOpenFileName(self, 'Open File')
        file1 = open(name[0], 'r')
        print(file1)

        with file1:
            text = file1.read()
            print(text)

        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        lay = QVBoxLayout(self.central_widget)

        label = QLabel(self)
        pixmap = QPixmap('C:\\Users\\kentw\\OneDrive - University of Toronto\\NSERC MIE 2021\\Fire_Safety\\13737.jpg')
        label.setPixmap(pixmap)
        self.resize(pixmap.width(), pixmap.height())

        lay.addWidget(label)

        self.layout = QGridLayout()
        self.setLayout(self.layout)

        # COMMENT TO AVOID MULTIPLE WINDOWS
        # self._insert_mywidget(self.layout)

        # DONT KNOW WHAT IT DOES
        # labels = [QLabel("hi")]
        # print("???????")
        # for i, label in enumerate(labels):
        #     self.layout.addWidget(label, 1, i)

        self.form_widget = FormWidget(self)
        self.setCentralWidget(self.form_widget)
        self.pybutton.hide()
        self.update()

    def _insert_mywidget(self, layout):
        self.widget = Window()

        # to insert a columnspan at least one row must be is necessary
        layout.addWidget(self.widget, 0, 0, 1, 10)

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


class FormWidget(QWidget):
    def __init__(self, parent):
        super(FormWidget, self).__init__(parent)
        self.layout = QVBoxLayout(self)

        label = QLabel(self)
        label.setText("Hi")
        self.layout.addWidget(label)

        pixmap = QPixmap('C:\\Users\\kentw\\OneDrive - University of Toronto\\NSERC MIE 2021\\Fire_Safety\\13737.jpg')
        label.setPixmap(pixmap)
        self.layout.addWidget(label)

        SophieResult = ['hot']
        # The dictionary for Guide and Keyword mapping
        Modeloutput = {'toxic': ['guide 137.txt', 'guide 138.txt', 'guide 139.txt', 'guide 144.txt'],
                       'corrosive': ['guide 137.txt'], \
                       'explosive': ['guide 137.txt', 'guide 138.txt'],
                       'hot': ['guide 137.txt', 'guide 138.txt', 'guide 139.txt']}
        address = 'C:\\Users\\kentw\\OneDrive - University of Toronto\\NSERC MIE 2021\\Fire_Safety\\'
        filenames = []

        for each in SophieResult:
            for guide in Modeloutput[each]:
                filenames.append(address + guide)
        filenames = list(dict.fromkeys(filenames))
        data = ""

        # Reading data from file1
        for item in filenames:
            with open(item) as fp:
                data += fp.read()
                data += "\n"
            file = open(item, 'r')

        with file:
            # text = file.read()
            label = QLabel(self)
            label.setText(data)
            self.layout.addWidget(label)

        self.setLayout(self.layout)


def run():
    app = QtWidgets.QApplication(sys.argv)
    GUI = Window()
    sys.exit(app.exec_())


run()