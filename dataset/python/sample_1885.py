def simulate_pressure(volume, temperature, gas_constant=8.314):
    pressure = volume * temperature / gas_constant
    return pressure

def main():
    v = 2.0
    t = 300.0
    p = simulate_pressure(v, t)
    print(p)
main()