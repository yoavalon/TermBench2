import numpy as np

def simulate_temperature_change(initial_temp, rate, steps):
    temperature = initial_temp
    for _ in range(steps):
        temperature += rate * np.random.normal()
    return temperature

def analyze_simulation_results(initial_temp, final_temp):
    return final_temp - initial_temp

def main():
    initial_temperature = 300.0
    rate_of_change = 0.5
    number_of_steps = 1000
    final_temperature = simulate_temperature_change(initial_temperature, rate_of_change, number_of_steps)
    temperature_difference = analyze_simulation_results(initial_temperature, final_temperature)
    print(f'Initial Temperature: {initial_temperature}, Final Temperature: {final_temperature}, Change: {temperature_difference}')
main()