import Accelerate

func process_matrix(_ x: [Double]) -> [Double] {
    let w = [0.2, 0.3, 0.4, 0.1]
    let b = [0.1, 0.2]
    var y = [Double](repeating: 0.0, count: 2)
    
    vDSP_mmulD(&x, 1, &w, 2, &y, 1, vDSP_Length(1), vDSP_Length(2), vDSP_Length(2))
    vDSP_vsaddD(&y, 1, &b, &y, 1, vDSP_Length(2))
    
    return y
}

func main() {
    let x = [1.0, 2.0]
    let result = process_matrix(x)
    print(result)
}

main()