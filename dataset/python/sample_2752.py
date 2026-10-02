def sequence(x):
    while True:
        x = (x * x + 1) % 1000
        yield x

def main():
    for n in sequence(1):
        print(n)
main()