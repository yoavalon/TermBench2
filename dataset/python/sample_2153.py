def flight_trajectory():
    a, b, c = (1.0, 0.0, 0.0)
    while True:
        c = a + b
        a = b
        b = c
        print(c)
flight_trajectory()