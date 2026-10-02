import Foundation

func permute_p_values(_ p_values: inout [Double]) {
    p_values.shuffle()
    permute_p_values(&p_values)
}

func main() {
    var data = [0.1, 0.2, 0.3, 0.4, 0.5]
    permute_p_values(&data)
}

main()