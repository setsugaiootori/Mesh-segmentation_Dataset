import os
import lackey
import win32gui
from lackey import *
from pywinauto import Application
import pyautogui
import PyQt5
import threading
import time
import pyperclip
import numpy as np
import tkinter


def write_filename():
    # Write the pending file to the file
    f = open('D:\development-program\gratuatedesign\datesets/datasets.txt', 'r+')
    # Write the pending file to the file
    for filepath,dirnames,filenames in os.walk(r'D:\development-program\gratuatedesign\datesets'):
        for filename in filenames:
            print(os.path.join(filepath, filename))
            f.write(os.path.join(filepath, filename + '\n'))
    f.close()


def read():  
    f = open("D:\development-program\gratuatedesign\datesets/datasets.txt", 'r')
    dataMat = []
    for line in f.readlines():
        # lock.acquire()
        # line = f.readline().split("\n")[i]
        fn = line.strip().split(" ")
        dataMat.append(fn[:])
    return dataMat
    f.close()
def hide_me():
    pyautogui.hotkey('alt', 'f4')

def start(a):
    # Image recognition path
    lackey.click('D:\development-program\gratuatedesign\qt/test\Mesh-Segmentation-master\photo\Mesh.png')
    pyperclip.copy(a)
    pyautogui.hotkey('ctrl', 'v')
    sleep(1)
    pyautogui.press('enter')
    pyautogui.keyDown('shift')
    pyautogui.moveRel(800, 500)
    a = 0
    while a < 10:
        pyautogui.scroll(1)
        sleep(1)
        a = a + 1
    pyautogui.keyUp('shift')
    con=input("是否人工调试(y/n)")
    con ="n"
    if con=="n":
        app1.window(class_name='CurveNetMaker').menu_select("Save")
        lackey.click('D:\development-program\gratuatedesign\qt/test\Mesh-Segmentation-master\photo\save.png')
        sleep(3)
        lackey.click('D:\development-program\gratuatedesign\qt/test\Mesh-Segmentation-master\photo\ok.png')
        sleep(2)
    if con=="y":
        root = tkinter.Tk()
        b=tkinter.Button(root,text="调试完成",command=hide_me)
        b.pack()
        root.mainloop()
        app1.window(class_name='CurveNetMaker').menu_select("Save")
        lackey.click('D:\development-program\gratuatedesign\qt/test\Mesh-Segmentation-master\photo\save.png')
        sleep(3)
        lackey.click('D:\development-program\gratuatedesign\qt/test\Mesh-Segmentation-master\photo\ok.png')
        sleep(2)

if __name__ == '__main__':
    filename = np.array(read())
    # Program running path
    app1 = Application(backend="uia").start(
        r'D:\development-program\gratuatedesign\qt\test\Mesh-Segmentation-master\x64\Release\CurveNetMaker.exe')
    # app1.window(class_name='CurveNetMaker').menu_select("Open")
    for i in filename[:, 0]:
        app1.window(class_name='CurveNetMaker').menu_select("Open")
        print(i)
        start(i)
