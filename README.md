# Mesh-segmentation_Dataset
Generation of a small model segmentation dataset

This repository is based on Mesh-Segmentation，Reference source：https://github.com/yixin26/Mesh-Segmentation

# Create dataset
## 1.Mesh-segmentation
Based on Mesh-Segmentation,run Executable Demo,After reading a mesh, segmentation is automatically perfomred. 
User will use a mouse and shift/control/alt key for interaction. We provide five types of operation, that is, global refinement/coarsening, local refinement/coarsening, and feature sketching.
Hold Shift + MouseWheel Up = increase alpha globally
Hold Shift + MouseWheel Down = decrease alpha globally

## 2.Partition dataset
Download the dataset you want to process, eg:http://irc.cs.sdu.edu.cn/~yunhai/public_html/ssl/ssd.html
Decompress and classify the dataset
The py can automatically divide the data set. The training set: verification set: test set is 7:2:1

## 3.Generate label file
The user can click the button to generate the label file，
Users can automatically(main.py) generate files by putting the model they want to process into the same folder (subfolder is also acceptable)
