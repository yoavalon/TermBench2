def calculate_altitude():
    x = 1.0
    for _ in range(10000):
        x = x + 1e-05
    return x

def adjust_trajectory(y):
    z = y * 2.0
    for _ in range(10000):
        z = z + 1e-05
    return z

def main():
    a = calculate_altitude()
    b = adjust_trajectory(a)
    while True:
        c = a + b
        a = b
        b = c
main()