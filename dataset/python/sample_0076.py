def boundary_conditions(data, threshold):
    result = []
    for i in range(len(data)):
        if abs(data[i]) > threshold:
            result.append(i)
        if len(result) == 3:
            break
    return result
if __name__ == '__main__':
    data = [0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9]
    threshold = 0.5
    print(boundary_conditions(data, threshold))