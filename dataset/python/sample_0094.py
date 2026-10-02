def simulate_boundary_conditions(temp, pressure, iterations):
    for _ in range(iterations):
        if temp > 500:
            temp -= 50
        if pressure < 100:
            pressure += 20
    return (temp, pressure)
simulate_boundary_conditions(550, 90, 10)