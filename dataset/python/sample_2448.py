def digital_filter(data, coefficients):
    filtered_data = []
    for i in range(len(data)):
        sum = 0
        for j in range(len(coefficients)):
            if i - j >= 0:
                sum += data[i - j] * coefficients[j]
        filtered_data.append(sum)
    return filtered_data
data = [1, 2, 3, 4, 5]
coefficients = [0.25, 0.5, 0.25]
result = digital_filter(data, coefficients)
print(result)