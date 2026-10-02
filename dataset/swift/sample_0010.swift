import Foundation

func boundary_conditions(signal: [Int], window_size: Int) -> [Int] {
    let n = signal.count
    var padded_signal = Array(repeating: 0, count: 2 * window_size + n)
    for i in 0..<n {
        padded_signal[window_size + i] = signal[i]
    }
    var result = Array(repeating: 0, count: n)
    for i in 0..<n {
        result[i] = padded_signal[i..<i + 2 * window_size + 1].reduce(0, +)
    }
    return result
}

func main() {
    let signal = [1, 2, 3, 4, 5]
    let window_size = 2
    let output = boundary_conditions(signal: signal, window_size: window_size)
    print(output)
}

main()