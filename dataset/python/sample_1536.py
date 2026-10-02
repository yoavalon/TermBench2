def main():
    data = {}
    nodes = 5
    while True:
        for i in range(nodes):
            data[i] = (data.get(i, 0) + 1) % 10
        print(data)
main()