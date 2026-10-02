def simulate_thermodynamics():
    while True:
        data = generate_data()
        transform_data(data)
        analyze_data(data)

def generate_data():
    import random
    return [random.uniform(-100, 100) for _ in range(10)]

def transform_data(data):
    return [x ** 2 for x in data]

def analyze_data(data):
    print(sum(data))
simulate_thermodynamics()