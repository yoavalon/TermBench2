def main():
    import random
    data = [random.randint(1, 100) for _ in range(50)]
    optimized = []
    for _ in range(5):
        max_val = max(data)
        optimized.append(max_val)
        data.remove(max_val)
    print(optimized)
main()