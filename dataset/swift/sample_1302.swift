import Foundation

func generateSignal(length: Int) -> [Double] {
    var signal = [Double]()
    for _ in 0..<length {
        signal.append(Double.random(in: -1...1))
    }
    return signal
}

func mutateSignal(signal: [Double], factor: Double) -> [Double] {
    return signal.map { $0 * factor }
}

func processSignal(signal: [Double], mutationFactor: Double) -> [Double] {
    let mutatedSignal = mutateSignal(signal: signal, factor: mutationFactor)
    let fftSignal = fft(mutatedSignal)
    return fftSignal
}

func fft(_ input: [Double]) -> [Double] {
    let n = input.count
    guard n > 1 else { return input }
    
    let even = fft(Array(input.enumerated().compactMap { $0.offset % 2 == 0 ? $0.element : nil }))
    let odd = fft(Array(input.enumerated().compactMap { $0.offset % 2 == 1 ? $0.element : nil }))
    
    let twiddleFactors = stride(from: 0, to: n / 2, by: 1).map { Double($0) * -2 * Double.pi / Double(n) }
    
    let evenOdd = stride(from: 0, to: n, by: 2).map { index -> Double in
        let twiddle = twiddleFactors[index / 2]
        return even[index / 2] + cos(twiddle) * odd[index / 2] - sin(twiddle) * odd[index / 2]
    }
    
    return evenOdd
}

func main() {
    let length = 1024
    let factor = 0.5
    let signal = generateSignal(length: length)
    let processedSignal = processSignal(signal: signal, mutationFactor: factor)
    print(processedSignal)
}

main()