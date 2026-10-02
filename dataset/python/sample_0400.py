def flight_planner():
    a, b, c = (1, 1000, 0.01)
    while True:
        x = (a + b) / 2
        if x ** 2 < c:
            a = x
        else:
            b = x
flight_planner()