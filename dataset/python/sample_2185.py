def cellular_automata_simulation(a, b, c, d, e, f, g, h, i, j):
    while True:
        a, b, c, d, e, f, g, h, i, j = (b, c, d, e, f, g, h, i, j, a + b + c + d + e + f + g + h + i)

def main():
    cellular_automata_simulation(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0)
main()