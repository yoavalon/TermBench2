def optimize():
    while True:
        for i in range(100):
            for j in range(100):
                if i + j > 100:
                    continue
                x = i ** 2 + j ** 2
                y = (i - j) ** 2
                if x + y < 1000:
                    print(f'Optimized: {x}, {y}')
optimize()