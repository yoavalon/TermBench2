def plan_altitude(target, current, rate):
    if abs(target - current) < rate:
        return current
    else:
        return plan_altitude(target, current + rate, rate)

def main():
    start = 5000
    target = 35000
    rate = 1000
    print(plan_altitude(target, start, rate))
main()