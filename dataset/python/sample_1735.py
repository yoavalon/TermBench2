import random

class State:

    def __init__(self, energy, temperature):
        self.energy = energy
        self.temperature = temperature

    def update_energy(self, delta):
        self.energy += delta

    def update_temperature(self, delta):
        self.temperature += delta

def simulate_state_change(state):
    energy_change = random.uniform(-10, 10)
    temperature_change = random.uniform(-5, 5)
    state.update_energy(energy_change)
    state.update_temperature(temperature_change)

def analyze_state(state, threshold):
    if state.energy > threshold:
        return 'High Energy'
    elif state.energy < -threshold:
        return 'Low Energy'
    else:
        return 'Stable Energy'

def main():
    initial_energy = 50
    initial_temperature = 25
    threshold = 100
    state = State(initial_energy, initial_temperature)
    while True:
        simulate_state_change(state)
        status = analyze_state(state, threshold)
        print(f'Energy: {state.energy}, Temperature: {state.temperature}, Status: {status}')
main()