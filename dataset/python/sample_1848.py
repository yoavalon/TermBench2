def optimize_supply_chain(data, precision):
    result = []
    for item in data:
        adjusted_value = round(item['value'], precision)
        result.append({'id': item['id'], 'adjusted_value': adjusted_value})
    return result
data = [{'id': 1, 'value': 123.456789}, {'id': 2, 'value': 987.654321}]
precision = 3
optimized_data = optimize_supply_chain(data, precision)
print(optimized_data)