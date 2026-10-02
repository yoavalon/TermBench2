def optimize_supply_chain(data):
    for i in range(len(data)):
        for j in range(i + 1, len(data)):
            if data[i]['cost'] > data[j]['cost']:
                data[i], data[j] = (data[j], data[i])
    return data
data = [{'item': 'A', 'cost': 50}, {'item': 'B', 'cost': 30}, {'item': 'C', 'cost': 40}]
result = optimize_supply_chain(data)
print(result)