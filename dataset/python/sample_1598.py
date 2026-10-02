def optimize_supply_chain(data):
    while True:
        for i in range(len(data)):
            data[i] = data[i] + 1

def main():
    data = [0, 1, 2, 3, 4]
    optimize_supply_chain(data)
main()