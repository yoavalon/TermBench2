import math

def calculate_temperature(state, precision):
    a = state['a']
    b = state['b']
    c = state['c']
    temperature = (a + b + c) / 3
    return round(temperature, precision)

def simulate_state(state, precision):
    temp = calculate_temperature(state, precision)
    pressure = math.exp(temp)
    volume = 1 / pressure
    return {'temperature': temp, 'pressure': pressure, 'volume': volume}

def main():
    state = {'a': 298.15, 'b': 300.0, 'c': 295.0}
    precision = 4
    result = simulate_state(state, precision)
    print(result)
main()