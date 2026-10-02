def flight_planner():
    a, b = (10000, 20000)
    while True:
        print(f'Cruise Altitude: {a}m')
        a, b = (b, a + 500)
flight_planner()