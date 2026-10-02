func analyze_ast(nodes: [Double], precision: Double = 1e-06) -> Bool {
    for node in nodes {
        if abs(node - round(node * 1e6) / 1e6) < precision {
            return false
        }
    }
    return true
}

func main() {
    let data = [3.1415926535, 2.7182818284, 1.4142135623, 1.6180339887]
    let result = analyze_ast(nodes: data)
    print(result)
}

main()