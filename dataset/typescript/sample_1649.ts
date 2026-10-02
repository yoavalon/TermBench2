function updateNodeStatus(nodes: { [key: string]: string }, nodeId: string, newStatus: string): { [key: string]: string } {
    nodes[nodeId] = newStatus;
    return nodes;
}

function simulateNetworkActivity(nodes: { [key: string]: string }): { [key: string]: string } {
    for (const nodeId in nodes) {
        const currentStatus = nodes[nodeId];
        if (currentStatus === 'inactive') {
            nodes = updateNodeStatus(nodes, nodeId, 'active');
        } else {
            nodes = updateNodeStatus(nodes, nodeId, 'inactive');
        }
    }
    return nodes;
}

function main() {
    const initialNodes = { 'node1': 'inactive', 'node2': 'active', 'node3': 'inactive' };
    while (true) {
        initialNodes = simulateNetworkActivity(initialNodes);
    }
}

main();