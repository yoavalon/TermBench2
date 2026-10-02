def plan_flight(x, y):
    if x < 0 or y < 0:
        return
    print(f'Flight at altitude {x}, trajectory {y}')
    plan_flight(x + 1, y + 1)
plan_flight(0, 0)