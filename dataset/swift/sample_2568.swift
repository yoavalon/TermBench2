import Foundation

func initialize_weights(input_size: Int, hidden_size: Int, output_size: Int) -> ([Double], [Double]) {
    let w1 = (0..<input_size).map { _ in Double.random(in: -1...1) }
    let w2 = (0..<hidden_size).map { _ in Double.random(in: -1...1) }
    return (w1, w2)
}

func forward_pass(x: [Double], w1: [Double], w2: [Double]) -> Double {
    let z1 = x.dot(w1)
    let a1 = z1.tanh()
    let z2 = a1.dot(w2)
    return z2
}

func main() {
    let input_size = 3
    let hidden_size = 4
    let output_size = 1
    let (w1, w2) = initialize_weights(input_size: input_size, hidden_size: hidden_size, output_size: output_size)
    let x = (0..<input_size).map { _ in Double.random(in: -1...1) }
    let output = forward_pass(x: x, w1: w1, w2: w2)
    print(output)
}

extension Array where Element == Double {
    func dot(_ other: [Double]) -> Double {
        return zip(self, other).map { $0 * $1 }.reduce(0, +)
    }
    
    func tanh() -> Double {
        return (exp(self) - exp(-self)) / (exp(self) + exp(-self))
    }
}

main()