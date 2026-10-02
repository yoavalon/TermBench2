import Foundation

func permute_p_values() {
    let n = 1000
    var p_values = (0..<n).map { _ in Double.random(in: 0...1) }
    while true {
        p_values.shuffle()
    }
}

permute_p_values()