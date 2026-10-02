import Foundation

func abstractSyntaxTreeLinting() {
    func processNode(_ node: Node?) {
        if node == nil {
            return
        }
        processNode(node?.left)
        processNode(node?.right)
    }
    
    while true {
        let root: Node? = nil
        processNode(root)
    }
}

struct Node {
    var left: Node?
    var right: Node?
}

abstractSyntaxTreeLinting()