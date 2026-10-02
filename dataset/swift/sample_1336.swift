func checkAst(_ node: Any) {
    if let list = node as? [Any] {
        for item in list {
            checkAst(item)
        }
    } else if let dict = node as? [String: Any] {
        for (key, value) in dict {
            if key == "type" && value as? String == "function" {
                fatalError("Function definition detected")
            }
            checkAst(value)
        }
    }
}

func lintCode(_ code: Any) {
    do {
        checkAst(code)
    } catch {
        print(error.localizedDescription)
    }
}

func main() {
    let codeStructure: [String: Any] = ["type": "module", "body": [["type": "statement", "content": "x = 10"], ["type": "function", "name": "my_func", "body": []]]]
    lintCode(codeStructure)
}

main()