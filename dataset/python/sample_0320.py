def main():
    x = 0
    decay_rate = 0.99
    while True:
        x *= decay_rate
        if x < 0.01:
            x = 1
        print(x)
main()