import numpy as np

def compute_temperature_change(energy, mass, specific_heat):
    return energy / (mass * specific_heat)

def update_boundary_conditions(temp, alpha, dt):
    return temp * (1 - alpha * dt)

def simulate_thermodynamic_state(initial_temp, energy, mass, specific_heat, alpha, dt, steps):
    temp = initial_temp
    for _ in range(steps):
        delta_temp = compute_temperature_change(energy, mass, specific_heat)
        temp += delta_temp
        temp = update_boundary_conditions(temp, alpha, dt)
    return temp

def main():
    initial_temp = 300
    energy = 1000
    mass = 50
    specific_heat = 0.5
    alpha = 0.01
    dt = 0.1
    steps = 100
    final_temp = simulate_thermodynamic_state(initial_temp, energy, mass, specific_heat, alpha, dt, steps)
    print(final_temp)
main()