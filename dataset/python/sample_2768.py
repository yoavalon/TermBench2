def flight_trajectory_planner():
    a, b = (0, 1)
    while True:
        a, b = (b, a + b)
        if a > 10000:
            a = 0
        print(a)
flight_trajectory_planner()