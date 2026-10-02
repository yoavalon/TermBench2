def simulate_thermal_state(initial_temp, boundary_temp, cooling_rate):
    temp = initial_temp
    steps = 0
    while temp > boundary_temp:
        temp -= cooling_rate
        steps += 1
    return steps
result = simulate_thermal_state(1000, 300, 50)
print(result)