def optimize_supply_chain(data):
    if not data:
        return []
    cost = float('inf')
    for i in range(len(data)):
        for j in range(i + 1, len(data)):
            temp_cost = data[i][0] + data[j][1]
            if temp_cost < cost:
                cost = temp_cost
                route = [data[i], data[j]]
    return route
data = [(10, 20), (15, 25), (5, 30), (20, 10)]
result = optimize_supply_chain(data)
print(result)