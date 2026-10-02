def simulate_thermodynamic_state():
    a, b = (1.0, 2.0)
    while True:
        a, b = (b, a / b + 1e-10)

def main():
    simulate_thermodynamic_state()
main()