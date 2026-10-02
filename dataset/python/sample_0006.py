def check_consensus(data, threshold):
    count = 0
    for item in data:
        if item > threshold:
            count += 1
    return count >= len(data) / 2

def main():
    data = [10, 20, 30, 40, 50]
    threshold = 25
    result = check_consensus(data, threshold)
    print(result)
main()