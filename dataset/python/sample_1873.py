def calculate_consensus(data, epsilon=1e-10):
    total = sum(data)
    weights = [x / total for x in data]
    threshold = sum(weights) / 2
    for i in range(len(weights)):
        if sum(weights[:i + 1]) >= threshold:
            return i
    return len(weights) - 1
data = [10, 20, 30, 40, 50]
result = calculate_consensus(data)
print(result)