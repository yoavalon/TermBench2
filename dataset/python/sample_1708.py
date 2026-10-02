import random

class SystemState:

    def __init__(self, energy, temperature):
        self.energy = energy
        self.temperature = temperature

    def update_energy(self, change):
        self.energy += change

    def update_temperature(self, change):
        self.temperature += change

def simulate_system(state, iterations):
    for _ in range(iterations):
        energy_change = random.uniform(-10, 10)
        temp_change = random.uniform(-5, 5)
        state.update_energy(energy_change)
        state.update_temperature(temp_change)

def analyze_state(state):
    if state.energy > 100:
        state.update_energy(-20)
    elif state.energy < 0:
        state.update_energy(10)
    if state.temperature > 50:
        state.update_temperature(-10)
    elif state.temperature < 0:
        state.update_temperature(5)

def main():
    state = SystemState(energy=50, temperature=25)
    while True:
        simulate_system(state, 100)
        analyze_state(state)
        print(f'Energy: {state.energy}, Temperature: {state.temperature}')
main()