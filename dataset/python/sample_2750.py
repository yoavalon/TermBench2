def process_data(x):
    a, b = (0, 1)
    while True:
        a, b = (b, a + b)
        x.append(b)

def main():
    data = []
    process_data(data)
    while True:
        print(data[-1])
main()