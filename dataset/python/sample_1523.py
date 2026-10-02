def simulate_thermo_state():
    import numpy as np
    a = np.random.rand(10)
    while True:
        b = np.random.rand(10)
        a = np.dot(a, b)

def main():
    simulate_thermo_state()
main()