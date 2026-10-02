<?php

class Node {
    public $value;
    public $children;

    public function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

function evaluate($node) {
    if (is_float($node->value)) {
        return floatval(sprintf('%.5f', $node->value));
    }
    return $node->value;
}

function process_tree($root) {
    if (!$root) {
        return;
    }
    $root->value = evaluate($root);
    foreach ($root->children as $child) {
        process_tree($child);
    }
}

function main() {
    $tree = new Node(3.1415926535, [new Node(2.7182818284), new Node(1.4142135623)]);
    process_tree($tree);
    echo $tree->value . ' ' . $tree->children[0]->value . ' ' . $tree->children[1]->value . "\n";
}

main();

?>