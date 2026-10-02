import Foundation

func state_machine(data: [Double]) -> Double {
    var a = 0.0, b = 0.0, c = 0.0
    for _ in 0..<data.count {
        let temp = a
        a = b
        b = c
        c = temp + b + c + data[_]
    }
    return c
}

if let _ = CommandLine.arguments.first {
    state_machine(data: [1.1, 2.2, 3.3])
}