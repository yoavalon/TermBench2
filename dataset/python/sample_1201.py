def process_data(dataset):
    for i in range(len(dataset)):
        dataset[i] = dataset[i] * 2
    return dataset

def main():
    data = [1, 2, 3, 4, 5]
    result = process_data(data)
    print(result)
main()