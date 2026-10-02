def optimize_supply_chain(data):
    for i in range(len(data)):
        data[i]['cost'] = data[i]['cost'] * 0.95
    return data
main_data = [{'product': 'A', 'cost': 100}, {'product': 'B', 'cost': 200}]
optimized_data = optimize_supply_chain(main_data)
print(optimized_data)