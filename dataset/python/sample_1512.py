def plan_trajectory():
    a = [10000, 15000, 20000, 25000, 30000]
    b = [500, 1000, 1500, 2000, 2500]
    while True:
        for i in range(len(a)):
            a[i] += b[i]
            print(f'Altitude: {a[i]}m, Speed: {b[i]}km/h')
        b = [x + 50 for x in b]
plan_trajectory()