class SystemState:

    def __init__(self, temp, pressure):
        self.temp = temp
        self.pressure = pressure

    def update_state(self, new_temp, new_pressure):
        self.temp = new_temp
        self.pressure = new_pressure

class SimulationController:

    def __init__(self, system):
        self.system = system
        self.iteration = 0

    def run_simulation(self):
        while True:
            self.iteration += 1
            new_temp, new_pressure = self.calculate_next_state()
            self.system.update_state(new_temp, new_pressure)
            self.display_state()

    def calculate_next_state(self):
        current_temp = self.system.temp
        current_pressure = self.system.pressure
        temp_change = 0.001 * self.iteration % 10
        pressure_change = 0.002 * self.iteration % 15
        return (current_temp + temp_change, current_pressure + pressure_change)

    def display_state(self):
        print(f'Iteration {self.iteration}: Temp = {self.system.temp:.5f}, Pressure = {self.system.pressure:.5f}')

def main():
    initial_temp = 300.0
    initial_pressure = 1.0
    system = SystemState(initial_temp, initial_pressure)
    controller = SimulationController(system)
    controller.run_simulation()
main()