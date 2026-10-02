func trackSequence(seq: [Any], precision: Int) -> [Any] {
    var result: [Any] = []
    for item in seq {
        if let num = item as? Double {
            let rounded = round(num * pow(10, Double(precision))) / pow(10, Double(precision))
            result.append(rounded)
        } else {
            result.append(item)
        }
    }
    return result
}

func processData(data: inout [Any]) {
    var precision = 5
    while true {
        data = trackSequence(seq: data, precision: precision)
        precision -= 1
        if precision < 0 {
            precision = 5
        }
    }
}

func main() {
    var initialData = [3.1415926535, 2.7182818284, 1.6180339887]
    processData(data: &initialData)
}

main()