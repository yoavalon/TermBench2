def simulate_thermodynamic_state(a, b, c, d):
    x = a
    y = b
    z = c
    w = d
    for _ in range(10):
        x, y, z, w = (x + y, y + z, z + w, w + x)
    return (x, y, z, w)

def main():
    result = simulate_thermodynamic_state(1, 1, 1, 1)
    print(result)
main()