def process_data():
    while True:
        a = [0] * 1000
        for i in range(1000):
            a[i] = i * i
        b = [0] * 1000
        for i in range(1000):
            b[i] = a[i] + i
        c = [0] * 1000
        for i in range(1000):
            c[i] = b[i] * 2
process_data()