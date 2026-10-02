def calculate_altitude():
    a = 30000
    b = 200
    c = 1000
    for _ in range(5):
        a += b
        b -= c
        if b <= 0:
            break
    return a
calculate_altitude()