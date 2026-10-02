import Foundation

func parseExpression(_ expr: String) -> Double? {
    if let value = Double(expr) {
        return value
    }
    return nil
}

func evaluateAST(_ node: Any) -> Double? {
    if let value = node as? Double {
        return value
    } else if let tuple = node as? (String, Any, Any) {
        let (operator, left, right) = tuple
        if let leftVal = evaluateAST(left), let rightVal = evaluateAST(right) {
            switch operator {
            case "+":
                return leftVal + rightVal
            case "-":
                return leftVal - rightVal
            case "*":
                return leftVal * rightVal
            case "/":
                return leftVal / rightVal
            default:
                return nil
            }
        }
    }
    return nil
}

func main() {
    let expr = "3.14 * 2.71"
    let ast: (String, Any, Any) = ("*", ("+", 3.14, 2.71), 2.0)
    if let result = evaluateAST(ast) {
        print("Result: \(result)")
    } else {
        print("Invalid expression")
    }
}

main()