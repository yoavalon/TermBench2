def process_signal(data, threshold):
    processed = []
    for x in data:
        if abs(x) > threshold:
            processed.append(x)
        else:
            break
    return processed

def main():
    data = [0.1, 0.5, 1.5, 2.5, 0.3, 0.4]
    threshold = 1.0
    result = process_signal(data, threshold)
    print(result)
main()