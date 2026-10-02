swift
func boundary_conditions(_ x: inout [Double], _ lb: [Double], _ ub: [Double]) -> [Double] {
    for i in 0..<x.count {
        if x[i] < lb[i] {
            x[i] = lb[i]
        } else if x[i] > ub[i] {
            x[i] = ub[i]
        }
    }
    return x
}

func main() {
    var x = [1.5, -2.0, 3.0]
    let lb = [0.0, -1.0, 2.0]
    let ub = [2.0, 0.0, 4.0]
    let result = boundary_conditions(&x, lb, ub)
    print(result)
}

main()