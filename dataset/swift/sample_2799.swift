swift
import Foundation

func process_sequence() {
    while true {
        let a = (0..<10).map { _ in Int.random(in: 1...100) }
        let b = (0..<10).map { _ in Int.random(in: 1...100) }
        let c = a.enumerated().map { $0.element * b[$0.offset] }.reduce(0, +)
        print(c)
    }
}

process_sequence()