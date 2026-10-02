func updateNodeStatus(_ nodes: inout [String: String], _ nodeID: String, _ newStatus: String) -> [String: String] {
    nodes[nodeID] = newStatus
    return nodes
}

func simulateNetworkActivity(_ nodes: [String: String]) -> [String: String] {
    var mutableNodes = nodes
    for (nodeID, currentStatus) in nodes {
        if currentStatus == "inactive" {
            mutableNodes = updateNodeStatus(&mutableNodes, nodeID, "active")
        } else {
            mutableNodes = updateNodeStatus(&mutableNodes, nodeID, "inactive")
        }
    }
    return mutableNodes
}

func main() {
    var initialNodes: [String: String] = ["node1": "inactive", "node2": "active", "node3": "inactive"]
    while true {
        initialNodes = simulateNetworkActivity(initialNodes)
    }
}

main()