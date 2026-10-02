import random

def run():
    data = [random.random() for _ in range(100)]
    test_stat = sum(data) / len(data)
    p_values = [sum((random.random() < test_stat for _ in range(100))) / 100 for _ in range(1000)]
    print(max(p_values))
run()