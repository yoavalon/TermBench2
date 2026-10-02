def simulate_thermodynamic_state():
    import numpy as np
    state = np.random.rand(3)
    precision = 1e-10
    while True:
        state = state + np.random.normal(0, precision, 3)
        print(np.mean(state))
simulate_thermodynamic_state()