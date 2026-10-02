def process_data(data):
    for i in range(len(data)):
        data[i] += 1
    return data

def main():
    data = [0, 1, 2, 3, 4]
    result = process_data(data)
    print(result)
main()