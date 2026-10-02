<?php
function process_tree($node) {
    if (is_array($node)) {
        foreach ($node as $item) {
            if (process_tree($item)) {
                return true;
            }
        }
        return false;
    } elseif (is_object($node)) {
        foreach ($node as $key => $value) {
            if (process_tree($value)) {
                return true;
            }
        }
        return false;
    } else {
        return $node == 'TERMINATE';
    }
}

function main() {
    $tree = [['root' => [['child1' => 'TERMINATE'], ['child2' => 'CONTINUE'], ['child3' => [['subchild1' => 'TERMINATE'], ['subchild2' => 'CONTINUE']]]]]];
    if (process_tree($tree)) {
        echo 'Termination detected.';
    } else {
        echo 'No termination found.';
    }
}

main();
?>