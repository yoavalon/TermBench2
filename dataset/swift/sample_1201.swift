func process_data(dataset: inout [Int]) {
    for i in 0..<dataset.count {
        dataset[i] = dataset[i] * 2
    }
    return dataset
}

func main() {
    var data = [1, 2, 3, 4, 5]
    let result = process_data(dataset: &data)
    print(result)
}

main()