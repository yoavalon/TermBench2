def simulate_thermodynamic_states():
    a, b = (1, 1)
    while True:
        yield a
        a, b = (b, a + b)
main = simulate_thermodynamic_states()
for _ in range(1000000):
    next(main)