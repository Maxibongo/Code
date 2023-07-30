### Welcome to SliceGAN ###
####### Steve Kench #######
'''
Use this file to define your settings for a training run, or
to generate a synthetic image using a trained generator.
'''

from slicegan import model, networks, util
import argparse
import numpy as np
import pathlib 
import os

# training variables
specific_data = False
current_directory = pathlib.Path.cwd()
base_data_path = pathlib.Path('../../../../Data/').resolve()
all_data_path = pathlib.Path('../../../../Data/Samples').resolve()
isotropic = bool(np.random.randint(0,1))
isotropic = True

# testing variables
specific_generator = False
generator_name = ''


# Define project name
Project_name = 'Fluo'
# Specify project folder.
Project_dir = str(base_data_path)
# Run with False to show an image during or after training
parser = argparse.ArgumentParser()
parser.add_argument('training', type=int)
args = parser.parse_args()
Training = args.training
Project_path = util.mkdr(Project_name, Project_dir, Training)


## Data Processing
# Define image  type (colour, grayscale, three-phase or two-phase.
# n-phase materials must be segmented)
image_type = 'grayscale'
# define data type (for colour/grayscale images, must be 'colour' / '
# grayscale. nphase can be, 'tif', 'png', 'jpg','array')
data_type = 'grayscale'
# Path to your data. One string for isotrpic, 3 for anisotropic
if specific_data == False:
    data_path, data_name = util.get_random_data_paths(all_data_path, isotropic)
else:
    data_path = [''] # some path
    data_name = '' # some data name



## Network Architectures
# Training image size, no. channels and scale factor vs raw data
img_size, img_channels, scale_factor = 64, 1,  1
# z vector depth
z_channels = 16
# Layers in G and D
lays = 6
# kernals for each layer
dk, gk = [4]*lays, [4]*lays
# strides
ds, gs = [2]*lays, [2]*lays
# no. filters
df, gf = [img_channels,64,128,256,512,1], [z_channels,256,256,128,64,img_channels]
# paddings
dp, gp = [1,1,1,1,0],[2,2,2,2,3]

## Create Networks
netD, netG = networks.slicegan_nets(Project_path, Training, image_type, dk, ds, df,dp, gk ,gs, gf, gp)

# Train
if Training:
    model.train(Project_path, image_type, data_type, data_path, netD, netG, img_channels, img_size, z_channels, scale_factor, data_name)
else:
    if specific_generator == False:
        generator_name = util.get_random_generator_name(str(base_data_path) + '/' + Project_name)
    img, raw, netG = util.test_img(str(base_data_path)+'/'+Project_name, image_type, netG(), generator_name, z_channels, lf=4)
