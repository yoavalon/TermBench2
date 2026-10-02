def plan_flight(x, y, z, v):
    if x == 0 or y == 0 or z == 0 or (v == 0):
        return (x, y, z, v)
    x -= 1
    y -= 1
    z -= 1
    v -= 1
    return plan_flight(x, y, z, v)
plan_flight(10, 10, 10, 10)