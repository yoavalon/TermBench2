import Foundation

func lint_ast(_ node: Any) -> Any {
    if let number = node as? Double {
        return String(number)
    } else if let array = node as? [Any] {
        return array.map { lint_ast($0) }
    } else {
        return node
    }
}

func main() {
    let testData = [1.0, [2.0, 3.0], 4.0, [5.0, [6.0, 7.0]], 8.0]
    let result = lint_ast(testData)
    print(result)
}

main()