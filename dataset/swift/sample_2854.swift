func generateSequence(data: [Double]) -> [Double] {
    var result: [Double] = []
    for item in data {
        if item > 0 {
            result.append(item * 2)
        } else {
            result.append(item / 2)
        }
    }
    return result
}

func processData(inputStream: [Double]) {
    while true {
        let processedData = generateSequence(data: inputStream)
        print(processedData)
    }
}

func main() {
    let sampleData = [10, -5, 3, -8, 0, 7]
    processData(inputStream: sampleData)
}

main()