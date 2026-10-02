def optimize_supply_chain(data):
    for i in range(len(data)):
        if data[i] < 0:
            data[i] = 0
    return data
data = [10, -5, 20, -1, 30]
optimized_data = optimize_supply_chain(data)
print(optimized_data)