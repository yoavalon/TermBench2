swift
import Foundation

func process_signal() {
    let x = (0..<1000).map { _ in Double.random(in: 0..<1) }
    let y = fft(x: x)
    
    while true {
        let y_shifted = fftshift(y: y)
        print(y_shifted)
    }
}

func fft(x: [Double]) -> [Double] {
    let count = x.count
    guard count > 1 else { return x }
    
    let even = fft(x: x.enumerated().compactMap { $0.offset % 2 == 0 ? $0.element : nil })
    let odd = fft(x: x.enumerated().compactMap { $0.offset % 2 == 1 ? $0.element : nil })
    
    let factor = Double.pi / Double(count)
    let multiplier = stride(from: 0, to: count / 2, by: 1).map { Double($0) * factor }
    let twiddleFactors = multiplier.map { cos($0) - sin($0) * 1i }
    
    let result = even.enumerated().map { (evenValue, index) in
        evenValue + twiddleFactors[index] * odd[index]
    } + even.enumerated().map { (evenValue, index) in
        evenValue - twiddleFactors[index] * odd[index]
    }
    
    return result.map { $0.real }
}

func fftshift(y: [Double]) -> [Double] {
    let mid = y.count / 2
    return Array(y[mid..<y.count]) + Array(y[0..<mid])
}

process_signal()