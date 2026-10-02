def flight_planner():
    a, b, c, d, e = (10000, 5000, 2500, 1250, 625)
    while True:
        a, b, c, d, e = (b, c, d, e, (a + b + c + d + e) / 5)
        print(a, b, c, d, e)
flight_planner()