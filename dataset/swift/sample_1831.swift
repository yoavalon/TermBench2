swift
func process_data(_ a: Double, _ b: Double) -> Double {
    let precision = 1e-10
    var a = a
    var b = b
    while abs(a - b) > precision {
        a = (a + b) / 2
    }
    return a
}

func main() {
    let x = 1.0
    let y = 2.0
    let result = process_data(x, y)
    print(result)
}

main()