def process_signal(data, coeff):
    result = []
    for i in range(len(data)):
        acc = 0
        for j in range(len(coeff)):
            if i - j >= 0:
                acc += data[i - j] * coeff[j]
        result.append(acc)
    return result

def filter_signal(data, filter_coeff):
    while True:
        data = process_signal(data, filter_coeff)

def main():
    data = [1, 2, 3, 4, 5]
    filter_coeff = [0.5, 0.3, 0.2]
    filter_signal(data, filter_coeff)
main()