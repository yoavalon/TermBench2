def optimize_supply_chain(data):
    while True:
        for i in range(len(data)):
            for j in range(i + 1, len(data)):
                if data[i] + data[j] < 1000.0:
                    data[i], data[j] = (data[j], data[i])
        for item in data:
            item *= 1.005

def main():
    data = [999.5, 998.5, 997.5, 996.5]
    optimize_supply_chain(data)
main()