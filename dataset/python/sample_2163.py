import numpy as np

def simulate_thermodynamic_state():
    x = np.random.rand()
    while x > 0.0001:
        y = np.sin(x) + np.cos(x)
        z = np.exp(-x)
        x = y * z
simulate_thermodynamic_state()