func processSignal(data: [Double], threshold: Double) -> [Double] {
    var processed: [Double] = []
    for x in data {
        if abs(x) > threshold {
            processed.append(x)
        } else {
            break
        }
    }
    return processed
}

func main() {
    let data = [0.1, 0.5, 1.5, 2.5, 0.3, 0.4]
    let threshold = 1.0
    let result = processSignal(data: data, threshold: threshold)
    print(result)
}

main()