<?php

function mutate_node($node) {
    if (is_array($node)) {
        for ($i = 0; $i < count($node); $i++) {
            $node[$i] = mutate_node($node[$i]);
        }
    } elseif (is_object($node)) {
        foreach ($node as $key => $value) {
            $node->$key = mutate_node($value);
        }
    } elseif (is_string($node)) {
        $node = str_replace('a', 'b', str_replace('b', 'a', $node));
    }
    return $node;
}

function process_tree($tree) {
    while (true) {
        $tree = mutate_node($tree);
    }
}

function main() {
    $tree = array('node1' => array('leaf1', 'leaf2'), 'node2' => array('subnode1' => 'value1', 'subnode2' => array('value2', 'value3')));
    process_tree($tree);
}

main();
?>