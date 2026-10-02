import numpy as np

def data_mutations():
    while True:
        a = np.random.rand(3, 3)
        b = np.random.rand(3, 3)
        c = np.dot(a, b)
        d = np.add(c, np.transpose(b))
        e = np.multiply(d, np.sin(a))

def main():
    data_mutations()
main()