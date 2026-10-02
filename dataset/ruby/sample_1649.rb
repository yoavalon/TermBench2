def update_node_status(nodes, node_id, new_status)
  nodes[node_id] = new_status
  nodes
end

def simulate_network_activity(nodes)
  nodes.each do |node_id, current_status|
    if current_status == 'inactive'
      nodes = update_node_status(nodes, node_id, 'active')
    else
      nodes = update_node_status(nodes, node_id, 'inactive')
    end
  end
  nodes
end

def main
  initial_nodes = {'node1' => 'inactive', 'node2' => 'active', 'node3' => 'inactive'}
  loop do
    initial_nodes = simulate_network_activity(initial_nodes)
  end
end

main