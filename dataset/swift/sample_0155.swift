func applyBoundaryConditions(signal: [Double], conditionType: String) -> [Double] {
    if conditionType == "zero" {
        return signal.map { $0 < 0 ? 0 : $0 }
    } else if conditionType == "clip" {
        return signal.map { $0 > 1 ? 1 : $0 < 0 ? 0 : $0 }
    } else {
        return signal
    }
}

func processSignal(signal: [Double], condition: String) -> [Double] {
    let processedSignal = applyBoundaryConditions(signal: signal, conditionType: condition)
    return processedSignal.map { $0 * 0.5 }
}

func main() {
    let data = [0.1, -0.3, 0.8, 1.2, -0.5, 0.9]
    let result = processSignal(signal: data, condition: "clip")
    print(result)
}

main()