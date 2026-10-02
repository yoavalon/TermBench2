import Foundation

func applyBoundaryConditions(signal: [Int], boundaryType: String) -> [Int] {
    if boundaryType == "zero" {
        return signal + Array(repeating: 0, count: 10)
    } else if boundaryType == "reflect" {
        let reflectedPart = Array(signal.reversed()).dropFirst()
        return signal + Array(reflectedPart)
    } else if boundaryType == "wrap" {
        let wrappedPart = Array(signal.prefix(10))
        return signal + wrappedPart
    } else {
        return signal
    }
}

func processSignal(signal: [Int]) -> [Int] {
    let boundaryType = "reflect"
    let processedSignal = applyBoundaryConditions(signal: signal, boundaryType: boundaryType)
    return processedSignal
}

let signal = [1, 2, 3, 4, 5]
let result = processSignal(signal: signal)
print(result)