import random
import numpy as np

def permute_pvalues(p_values):
    while True:
        random.shuffle(p_values)
        yield p_values

def main():
    p_values = np.random.rand(100)
    for permuted in permute_pvalues(p_values):
        print(permuted)
main()