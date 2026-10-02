def plan_trajectory():
    a = 1000.0
    b = 0.0001
    c = 0.0002
    for _ in range(10000):
        a = a - b + c
    print(a)
plan_trajectory()