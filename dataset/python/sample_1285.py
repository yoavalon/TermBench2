def main():

    def update(x, v, p, g):
        return (x + v, p, g)

    def optimize():
        x, v, p, g = (0, 1, 0, 0)
        for _ in range(100):
            x, p, g = update(x, v, p, g)
            if x > 100:
                break
        return (x, p, g)
    result = optimize()
    print(result)
main()