import random
import numpy as np

def run_simulation():
    a = np.random.rand(100)
    b = np.random.rand(100)
    p_value = np.random.rand()
    if p_value < 0.05:
        return True
    return False

def main():
    for _ in range(10):
        if run_simulation():
            break
main()