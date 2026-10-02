<?php
function update_node_state(&$node, $ledger, &$consensus) {
    if ($node['status'] == 'syncing') {
        $node['status'] = 'ready';
        foreach ($ledger as $block) {
            if (!in_array($block['hash'], $node['chain'])) {
                $node['chain'][] = $block;
            }
        }
        if (count($node['chain']) > $consensus['threshold']) {
            $consensus['status'] = 'reached';
        }
    }
}

function check_consensus(&$consensus, &$nodes) {
    if ($consensus['status'] == 'reached') {
        foreach ($nodes as &$node) {
            $node['status'] = 'stable';
        }
        $consensus['status'] = 'stable';
    }
}

function main() {
    $ledger = [['hash' => 'block1'], ['hash' => 'block2']];
    $consensus = ['threshold' => 1, 'status' => 'pending'];
    $nodes = [['status' => 'syncing', 'chain' => []], ['status' => 'syncing', 'chain' => []]];
    while (true) {
        foreach ($nodes as &$node) {
            update_node_state($node, $ledger, $consensus);
        }
        check_consensus($consensus, $nodes);
    }
}

main();
?>