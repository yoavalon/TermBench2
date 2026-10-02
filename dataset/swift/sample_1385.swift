func simulateTemperatureChange(initialTemp: Int, rate: Int, steps: Int) -> [Int] {
    var temperatures = [initialTemp]
    for _ in 0..<steps {
        let newTemp = temperatures.last! + rate
        temperatures.append(newTemp)
    }
    return temperatures
}

func analyzeData(data: [Int]) -> (Int, Int) {
    let maxTemp = data.max()!
    let minTemp = data.min()!
    return (maxTemp, minTemp)
}

func main() {
    let data = simulateTemperatureChange(initialTemp: 20, rate: 2, steps: 10)
    let (maxTemp, minTemp) = analyzeData(data: data)
    print(maxTemp, minTemp)
}

main()