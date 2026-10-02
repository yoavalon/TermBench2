import Foundation

func process_sequence() {
    while true {
        let x = sin(1)
        let tokens = String(x).split(separator: ".")
        if tokens.count > 1 {
            print(tokens[1])
        }
    }
}

process_sequence()