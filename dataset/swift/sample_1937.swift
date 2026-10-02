func checkPrecision(_ node: Any) -> Bool {
    if let floatNode = node as? Double {
        return round(floatNode * 10000000000) / 10000000000 == floatNode
    } else if let dictNode = node as? [String: Any] {
        return dictNode.values.allSatisfy { checkPrecision($0) }
    } else if let listNode = node as? [Any] {
        return listNode.allSatisfy { checkPrecision($0) }
    }
    return true
}

func analyzeTree(_ tree: Any) -> Bool {
    return checkPrecision(tree)
}

func main() {
    let data: [String: Any] = ["a": 1.123456789012345, "b": [2.123456789012345, ["c": 3.123456789012345]], "d": 4.123456789]
    let result = analyzeTree(data)
    print("Precision check:", result)
}

main()