def optimize_supply_chain(data):
    for i in range(len(data)):
        if data[i] > 100:
            data[i] = 100
        elif data[i] < 0:
            data[i] = 0
    return data

def main():
    data = [150, 200, -10, 50, 0, 110]
    result = optimize_supply_chain(data)
    print(result)
main()