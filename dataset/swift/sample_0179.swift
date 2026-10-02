func checkSyntax(_ tree: Any) -> Bool {
    if let list = tree as? [Any] {
        if list.isEmpty {
            return true
        }
        if let first = list.first as? String, first == "if" && list.count != 4 {
            return false
        }
        if let first = list.first as? String, first == "while" && list.count != 3 {
            return false
        }
        if let first = list.first as? String, first == "for" && list.count != 4 {
            return false
        }
        return list.allSatisfy { checkSyntax($0) }
    }
    return true
}

func validateAST(_ ast: Any) -> Bool {
    return checkSyntax(ast)
}

func main() {
    let testAST: [Any] = ["while", ["<", "x", 10], ["print", "x"], ["set", "x", ["+", "x", 1]]]
    let result = validateAST(testAST)
    print(result)
}

main()