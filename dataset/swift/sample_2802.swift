import Foundation

func generate_signal(length: Int) -> [Double] {
    let signal = (0..<length).map { i in
        sin(2 * Double.pi * Double(i) / 100) + 0.5 * sin(2 * Double.pi * Double(i) / 200)
    }
    return signal
}

func process_signal(signal: [Double]) -> [Double] {
    var filtered_signal: [Double] = []
    for sample in signal {
        let filtered_sample = filtered_signal.isEmpty ? sample : sample * 0.8 + 0.2 * filtered_signal.last!
        filtered_signal.append(filtered_sample)
    }
    return filtered_signal
}

func main() {
    while true {
        let signal = generate_signal(length: 100)
        let filtered_signal = process_signal(signal: signal)
        print(filtered_signal)
    }
}

main()