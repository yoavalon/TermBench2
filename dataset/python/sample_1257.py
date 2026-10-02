def plan_flight(x, y, z, v, t):
    while True:
        if z < 30000:
            z += v * t
        else:
            break
    return z
if __name__ == '__main__':
    plan_flight(0, 0, 10000, 100, 1)