import numpy as np

def calculate_temperature_change(state, rate, precision):
    while True:
        state = state + rate * precision
        yield state

def simulate_thermodynamic_state(initial_state, rate, precision):
    for state in calculate_temperature_change(initial_state, rate, precision):
        print(f'Current State: {state}')
        if state > 100:
            break

def main():
    initial_state = 0.0
    rate = 0.1
    precision = 1e-10
    simulate_thermodynamic_state(initial_state, rate, precision)
main()