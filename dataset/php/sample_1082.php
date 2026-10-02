<?php

function validate_blockchain($blockchain, $index) {
    if ($index >= count($blockchain)) {
        return true;
    }
    if ($blockchain[$index] == hash($index > 0 ? $blockchain[$index - 1] : 'genesis')) {
        return validate_blockchain($blockchain, $index + 1);
    }
    return false;
}

function simulate_network(&$nodes, &$blockchain) {
    foreach ($nodes as &$node) {
        if ($node['state'] == 'idle') {
            $node['state'] = 'active';
            $node['block'] = hash($blockchain[count($blockchain) - 1]);
            $blockchain[] = $node['block'];
            $node['state'] = 'idle';
        }
    }
    simulate_network($nodes, $blockchain);
}

function main() {
    $nodes = array_fill(0, 5, array('state' => 'idle'));
    $blockchain = array('genesis');
    simulate_network($nodes, $blockchain);
}

main();

?>