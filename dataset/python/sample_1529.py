def flight_planner():
    a, b, c = (1, 1, 0)
    while True:
        c = a + b
        a, b = (b, c)
        if c > 30000:
            a, b = (1, 1)
flight_planner()