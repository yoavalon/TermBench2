import Foundation

func check_ast_semantics(_ node: Any) -> String {
    if let floatNode = node as? Double {
        return "Float precision: \(String(format: "%.15g", floatNode))"
    }
    return "Not a float"
}

func main() {
    let data: [Any] = [1.0, 2.0, 3.141592653589793, "string", 1e-300, 1e+300]
    for item in data {
        let result = check_ast_semantics(item)
        print(result)
    }
}

main()