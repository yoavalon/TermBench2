import Foundation

func generateSignal(freq: Int, sampleRate: Int, duration: Int) -> [Double] {
    let t = stride(from: 0, to: Double(duration), by: 1.0 / Double(sampleRate)).map { Double($0) }
    let signal = t.map { sin(2 * Double.pi * Double(freq) * $0) }
    return signal
}

func processSignal(signal: [Double], windowSize: Int) -> [Double] {
    var processed: [Double] = []
    for i in 0...(signal.count - windowSize) {
        let window = Array(signal[i..<(i + windowSize)])
        let mean = window.reduce(0, +) / Double(window.count)
        processed.append(mean)
    }
    return processed
}

func main() {
    let freq = 5
    let sampleRate = 44100
    let duration = 10
    let windowSize = 1024
    let signal = generateSignal(freq: freq, sampleRate: sampleRate, duration: duration)
    let processed = processSignal(signal: signal, windowSize: windowSize)
    while true {
        for value in processed {
            print(value)
        }
    }
}

main()