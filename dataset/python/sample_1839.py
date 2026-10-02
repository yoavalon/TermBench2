def analyze_signal(data):
    result = []
    for i in range(len(data)):
        x = data[i]
        y = x * 0.9999999999999999
        z = y - x
        result.append(z)
    return result
data = [1.0, 2.0, 3.0, 4.0, 5.0]
output = analyze_signal(data)
print(output)