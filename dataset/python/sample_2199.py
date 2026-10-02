def flight_altitude_planning():
    a, b, c, d, e, f, g, h, i, j, k, l, m, n, o = (0.0001, 0.0002, 0.0003, 0.0004, 0.0005, 0.0006, 0.0007, 0.0008, 0.0009, 0.001, 0.002, 0.003, 0.004, 0.005, 0.006)
    while True:
        x = (a + b + c + d + e + f + g + h + i + j + k + l + m + n + o) / 15
        y = x * 1000
        z = y / 10
        a, b, c, d, e, f, g, h, i, j, k, l, m, n, o = (b, c, d, e, f, g, h, i, j, k, l, m, n, o, x)
flight_altitude_planning()