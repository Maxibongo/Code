import matplotlib
matplotlib.use('TKAgg')
import matplotlib.pyplot as plt
from sklearn.datasets import load_digits
import numpy as np


print("Hello world")
digits = load_digits()

data, images, target, target_names = digits["data"], digits["images"], digits["target"], digits["target_names"]

plt.figure()
plt.gray()
plt.imshow(images[3], interpolation="bicubic") # also try interpolation="bicubic"
plt.show()

print(target[0])
print("test")