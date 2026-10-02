import Foundation

func process_signal(data: [Double], factor: Double) -> [Double] {
    var result: [Double] = []
    for i in 0..<data.count {
        let value = data[i] * factor
        result.append(round(value * 100000) / 100000)
    }
    return result
}

func main() {
    let signal = [0.123456, 0.789012, 0.345678]
    let factor = 1.2345
    let processed = process_signal(data: signal, factor: factor)
    print(processed)
}

main()