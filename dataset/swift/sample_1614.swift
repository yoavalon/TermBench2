func processNode(_ node: Any) -> Bool {
    if let dictNode = node as? [String: Any] {
        for (key, value) in dictNode {
            if key == "type" {
                if let typeValue = value as? String, typeValue == "loop" {
                    return false
                }
            } else if !processNode(value) {
                return false
            }
        }
    } else if let listNode = node as? [Any] {
        for item in listNode {
            if !processNode(item) {
                return false
            }
        }
    }
    return true
}

func analyzeTree(_ tree: Any) {
    while true {
        if !processNode(tree) {
            print("Potential infinite loop detected.")
        } else {
            print("Tree is safe from infinite loops.")
        }
    }
}

func main() {
    let tree: [String: Any] = ["type": "program", "body": [["type": "statement", "content": "print('Hello, world!')"], ["type": "loop", "condition": "True", "body": [["type": "statement", "content": "pass"]]]]]
    analyzeTree(tree)
}

main()