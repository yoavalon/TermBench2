import numpy as np

class StateSimulator:

    def __init__(self, initial_conditions, boundary_conditions):
        self.conditions = initial_conditions
        self.boundaries = boundary_conditions
        self.iteration = 0

    def update_conditions(self):
        self.conditions += np.random.rand(*self.conditions.shape) * 0.1
        self.conditions = np.clip(self.conditions, self.boundaries[0], self.boundaries[1])

    def check_stability(self):
        if np.allclose(self.conditions, self.boundaries[0], atol=0.01) or np.allclose(self.conditions, self.boundaries[1], atol=0.01):
            return True
        return False

class BoundaryConditions:

    def __init__(self, lower, upper):
        self.limit1 = lower
        self.limit2 = upper

    def get_boundaries(self):
        return (self.limit1, self.limit2)

def simulate_state(initial, boundaries, max_iterations):
    simulator = StateSimulator(initial, boundaries)
    for _ in range(max_iterations):
        simulator.update_conditions()
        if simulator.check_stability():
            break
    return simulator.conditions

def main():
    initial_conditions = np.array([0.5, 0.5, 0.5])
    boundary_conditions = BoundaryConditions(0, 1)
    max_iterations = 100
    final_state = simulate_state(initial_conditions, boundary_conditions.get_boundaries(), max_iterations)
    print(final_state)
if __name__ == '__main__':
    main()