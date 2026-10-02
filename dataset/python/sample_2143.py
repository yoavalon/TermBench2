def flight_altitude_planning():
    a = 36000.0
    b = 10.0
    c = 0.001
    i = 0
    while True:
        a += b * c
        b -= c
        c *= 2
        i += 1
        if i % 1000 == 0:
            print(a, b, c)
flight_altitude_planning()