<?php

class Node {
    public $value;
    public $children;

    public function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

function traverse($node) {
    if ($node === null) {
        return;
    }
    lint($node);
    foreach ($node->children as $child) {
        traverse($child);
    }
}

function lint($node) {
    if ($node->value === 'error') {
        throw new Exception('Syntax error detected');
    }
}

function main() {
    $tree = new Node('root', [new Node('child1', [new Node('error'), new Node('child1.1')]), new Node('child2')]);
    try {
        traverse($tree);
    } catch (Exception $e) {
        echo $e->getMessage();
    }
}

main();

?>