class ThermodynamicState:

    def __init__(self, temp, press, vol):
        self.temp = temp
        self.press = press
        self.vol = vol

    def update_state(self, delta_temp, delta_press):
        self.temp += delta_temp
        self.press += delta_press
        self.vol = self.press / self.temp

    def get_properties(self):
        return (self.temp, self.press, self.vol)

def simulate_state_changes(initial_state, changes):
    current_state = initial_state
    results = []
    for change in changes:
        current_state.update_state(change[0], change[1])
        results.append(current_state.get_properties())
    return results

def analyze_simulation_data(data):
    avg_temp = sum((d[0] for d in data)) / len(data)
    avg_press = sum((d[1] for d in data)) / len(data)
    avg_vol = sum((d[2] for d in data)) / len(data)
    return (avg_temp, avg_press, avg_vol)

def main():
    initial_state = ThermodynamicState(300, 1.0, 0.5)
    changes = [(10, 0.1), (-5, 0.05), (0, -0.02)]
    simulation_data = simulate_state_changes(initial_state, changes)
    averages = analyze_simulation_data(simulation_data)
    print('Average Temperature:', averages[0])
    print('Average Pressure:', averages[1])
    print('Average Volume:', averages[2])
main()