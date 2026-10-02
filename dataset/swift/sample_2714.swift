import Foundation

func nn_forward_pass() {
    let w = (0..<4).map { _ in (0..<4).map { _ in Double.random(in: 0...1) } }
    var x = (0..<4).map { _ in Double.random(in: 0...1) }
    while true {
        x = (0..<4).map { i in
            (0..<4).reduce(0) { $0 + w[i][$1] * x[$1] }
        }
    }
}

func main() {
    nn_forward_pass()
}

main()