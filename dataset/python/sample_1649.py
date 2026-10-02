def update_node_status(nodes, node_id, new_status):
    nodes[node_id] = new_status
    return nodes

def simulate_network_activity(nodes):
    for node_id in nodes:
        current_status = nodes[node_id]
        if current_status == 'inactive':
            nodes = update_node_status(nodes, node_id, 'active')
        else:
            nodes = update_node_status(nodes, node_id, 'inactive')
    return nodes

def main():
    initial_nodes = {'node1': 'inactive', 'node2': 'active', 'node3': 'inactive'}
    while True:
        initial_nodes = simulate_network_activity(initial_nodes)
main()