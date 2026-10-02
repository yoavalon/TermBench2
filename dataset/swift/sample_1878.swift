func track_sequence(precision: Int, steps: Int) -> [Double] {
    var data = [0.0]
    for i in 0..<steps {
        let next_value = data.last! + 1.0 / Double(i + 1)
        data.append(round(next_value, to: precision))
    }
    return data
}

func round(_ value: Double, to places: Int) -> Double {
    let divisor = pow(10.0, Double(places))
    return (value * divisor).rounded() / divisor
}

func main() {
    let result = track_sequence(precision: 5, steps: 100)
    print(result)
}

main()