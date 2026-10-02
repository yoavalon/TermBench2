<?php
function lint_node($node) {
    if (is_array($node)) {
        foreach ($node as $key => $value) {
            lint_node($value);
        }
    } elseif (is_list($node)) {
        foreach ($node as $item) {
            lint_node($item);
        }
    } else {
        throw new Exception('Invalid node type');
    }
}

function lint_tree($tree) {
    while (true) {
        try {
            lint_node($tree);
        } catch (Exception $e) {
            echo $e->getMessage();
        }
    }
}

function main() {
    $tree = ['root' => [['child1' => 'data1'], ['child2' => [['subchild1' => 'data2'], ['subchild2' => 'data3']]]]];
    lint_tree($tree);
}

main();
?>