class Simulation:

    def __init__(self, state):
        self.state = state

    def update_state(self, change):
        self.state += change

    def is_stable(self):
        return abs(self.state) < 0.01

class BoundaryConditions:

    def __init__(self, min_val, max_val):
        self.min_val = min_val
        self.max_val = max_val

    def enforce_boundaries(self, state):
        if state < self.min_val:
            return self.min_val
        elif state > self.max_val:
            return self.max_val
        return state

class Controller:

    def __init__(self, simulation, boundary_conditions):
        self.simulation = simulation
        self.boundary_conditions = boundary_conditions

    def run(self):
        change = 0.1
        while True:
            self.simulation.update_state(change)
            self.simulation.state = self.boundary_conditions.enforce_boundaries(self.simulation.state)
            if self.simulation.is_stable():
                break

def main():
    simulation = Simulation(0.0)
    boundary_conditions = BoundaryConditions(-1.0, 1.0)
    controller = Controller(simulation, boundary_conditions)
    controller.run()
if __name__ == '__main__':
    main()