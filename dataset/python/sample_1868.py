def optimize_supply_chain(data, precision):
    result = []
    for i in range(len(data)):
        value = data[i]
        adjusted_value = round(value / precision) * precision
        result.append(adjusted_value)
    return result
data = [123.456, 789.123, 456.789]
precision = 0.01
optimized_data = optimize_supply_chain(data, precision)
print(optimized_data)