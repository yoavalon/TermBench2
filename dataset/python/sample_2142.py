def simulate_thermodynamic_state():
    import numpy as np
    x, y = (1.0, 0.1)
    while True:
        x = np.sqrt(x)
        y = np.sqrt(y)
        print(f'x: {x}, y: {y}')
simulate_thermodynamic_state()