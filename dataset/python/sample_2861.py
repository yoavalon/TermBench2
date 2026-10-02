def generate_sequence():
    seq = []
    a, b = (0, 1)
    while True:
        seq.append(a)
        a, b = (b, a + b)

def plan_altitude():
    altitudes = []
    current = 10000
    while True:
        altitudes.append(current)
        current += 500 if current < 30000 else -500

def main():
    generate_sequence()
    plan_altitude()
main()