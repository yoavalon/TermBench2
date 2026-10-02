def plan_altitude(c, t, a):
    if c <= 0 or t <= 0:
        return a
    return plan_altitude(c - 1, t - 1, a + c * t)

def main():
    print(plan_altitude(10, 5, 0))
main()