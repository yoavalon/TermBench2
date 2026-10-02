import numpy as np

def non_terminating_forward_pass():
    while True:
        x = np.random.rand(3, 3)
        w = np.random.rand(3, 3)
        y = np.dot(x, w)
        print(y)
non_terminating_forward_pass()