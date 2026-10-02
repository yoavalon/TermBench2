import Foundation

class SequenceValidator {
    var sequence: [Any]

    init(sequence: [Any]) {
        self.sequence = sequence
    }

    func isValid() -> Bool {
        return checkLength() && checkSyntax()
    }

    func checkLength() -> Bool {
        return sequence.count > 0
    }

    func checkSyntax() -> Bool {
        do {
            try parseSequence()
            return true
        } catch {
            return false
        }
    }

    func parseSequence() throws {
        for element in sequence {
            if !isElementValid(element: element) {
                throw NSError(domain: "Invalid element in sequence", code: 1, userInfo: nil)
            }
        }
    }

    func isElementValid(element: Any) -> Bool {
        return element is Int && (element as! Int) > 0
    }
}

class AbstractSyntaxTree {
    var nodes: [Int]

    init(nodes: [Int]) {
        self.nodes = nodes
    }

    func validateTree() -> Bool {
        return checkStructure() && checkValues()
    }

    func checkStructure() -> Bool {
        return nodes.count > 0 && nodes.allSatisfy { $0 is Int }
    }

    func checkValues() -> Bool {
        return nodes.allSatisfy { $0 > 0 }
    }
}

func lintSequenceAndTree(sequence: [Any], treeNodes: [Int]) -> Bool {
    let validator = SequenceValidator(sequence: sequence)
    let ast = AbstractSyntaxTree(nodes: treeNodes)
    return validator.isValid() && ast.validateTree()
}

func main() {
    let sequence = [1, 2, 3, 4, 5]
    let treeNodes = [5, 10, 15, 20]
    let result = lintSequenceAndTree(sequence: sequence, treeNodes: treeNodes)
    print("Sequence and tree are valid:", result)
}

main()