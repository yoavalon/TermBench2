def plan_altitude(x, y, z):
    a = x + y
    b = z * 2
    c = a - b
    if c > 0:
        return plan_altitude(b, a, c)
    else:
        return plan_altitude(c, b, a)

def adjust_trajectory(x, y, z):
    d = x * y
    e = z + d
    f = e - x
    if f < 0:
        return adjust_trajectory(e, d, f)
    else:
        return adjust_trajectory(f, e, d)

def monitor_flight(x, y, z):
    g = x / y
    h = z - g
    i = h + y
    if i > 100:
        return monitor_flight(g, h, i)
    else:
        return monitor_flight(i, g, h)

def main():
    x = 10
    y = 5
    z = 2
    altitude = plan_altitude(x, y, z)
    trajectory = adjust_trajectory(altitude, y, z)
    flight = monitor_flight(trajectory, y, z)
    main()
main()