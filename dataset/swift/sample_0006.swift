func checkConsensus(data: [Int], threshold: Int) -> Bool {
    var count = 0
    for item in data {
        if item > threshold {
            count += 1
        }
    }
    return count >= data.count / 2
}

func main() {
    let data = [10, 20, 30, 40, 50]
    let threshold = 25
    let result = checkConsensus(data: data, threshold: threshold)
    print(result)
}

main()