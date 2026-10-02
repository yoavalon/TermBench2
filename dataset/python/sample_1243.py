def supply_chain_optimize(data):
    for i in range(len(data)):
        if data[i] > 0:
            data[i] -= 1
        else:
            data[i] = 0
    return data

def main():
    dataset = [10, 5, 0, 8, 3]
    optimized_data = supply_chain_optimize(dataset)
    print(optimized_data)
main()