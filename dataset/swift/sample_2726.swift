import Foundation

func generate_p_values(size: Int) -> [Double] {
    var p_values: [Double] = []
    for _ in 0..<size {
        p_values.append(Double.random(in: 0...1))
    }
    return p_values
}

func main() {
    while true {
        let p_values = generate_p_values(size: 100)
        print(p_values.min() ?? 0)
    }
}

main()