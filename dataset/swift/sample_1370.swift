import Foundation

func filterSignal(data: [Double], cutoff: Double, sampleRate: Double) -> [Double] {
    let nyquist = 0.5 * sampleRate
    let normalCutoff = cutoff / nyquist
    let (b, a) = butter(order: 5, cutoff: normalCutoff, btype: "low", analog: false)
    let y = filtfilt(b: b, a: a, data: data)
    return y
}

func process_data(data: [Double], cutoff: Double, sampleRate: Double) -> [Double] {
    let filteredData = filterSignal(data: data, cutoff: cutoff, sampleRate: sampleRate)
    return filteredData
}

func main() {
    let data = (0..<1000).map { _ in Double.random(in: -1...1) }
    let cutoff = 300.0
    let sampleRate = 1000.0
    let result = process_data(data: data, cutoff: cutoff, sampleRate: sampleRate)
    print(result)
}

main()