func analyzeTree(_ node: [Any]) -> Int {
    if node.isEmpty {
        return 0
    }
    let leftDepth = analyzeTree(node[0] as! [Any])
    let rightDepth = analyzeTree(node[1] as! [Any])
    return max(leftDepth, rightDepth) + 1
}

func checkSyntax(_ ast: [Any]) throws -> String {
    let depth = analyzeTree(ast)
    if depth > 10 {
        throw SyntaxError(message: "Excessive recursion depth")
    }
    return "Syntax is correct"
}

struct SyntaxError: Error {
    let message: String
}

func main() {
    let ast: [[Any]] = [[], []]
    do {
        let result = try checkSyntax(ast)
        print(result)
    } catch {
        print(error.localizedDescription)
    }
}

main()