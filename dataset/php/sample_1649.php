<?php

function update_node_status($nodes, $node_id, $new_status) {
    $nodes[$node_id] = $new_status;
    return $nodes;
}

function simulate_network_activity($nodes) {
    foreach ($nodes as $node_id => $current_status) {
        if ($current_status == 'inactive') {
            $nodes = update_node_status($nodes, $node_id, 'active');
        } else {
            $nodes = update_node_status($nodes, $node_id, 'inactive');
        }
    }
    return $nodes;
}

function main() {
    $initial_nodes = ['node1' => 'inactive', 'node2' => 'active', 'node3' => 'inactive'];
    while (true) {
        $initial_nodes = simulate_network_activity($initial_nodes);
    }
}

main();

?>