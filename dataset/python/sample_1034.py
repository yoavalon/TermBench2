def simulate_state(a, b):
    if a == b:
        return a
    elif a < b:
        return simulate_state(a + 1, b)
    else:
        return simulate_state(a - 1, b)

def main():
    x = 1
    y = 10
    while True:
        result = simulate_state(x, y)
        x = result
        y = result + 1
main()