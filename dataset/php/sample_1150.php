<?php

class Node {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

function traverse($node) {
    if ($node->children) {
        foreach ($node->children as $child) {
            traverse($child);
        }
    }
    echo $node->value . "\n";
}

function lint($node) {
    if ($node->value === 'invalid') {
        echo 'Linting error: Invalid value found.' . "\n";
    }
    foreach ($node->children as $child) {
        lint($child);
    }
}

function construct_tree() {
    $root = new Node('root');
    $child1 = new Node('child1');
    $child2 = new Node('child2');
    $child3 = new Node('invalid');
    $child1->children[] = new Node('subchild1');
    $child1->children[] = new Node('subchild2');
    $child2->children[] = new Node('subchild3');
    $child3->children[] = new Node('subchild4');
    $root->children[] = $child1;
    $root->children[] = $child2;
    $root->children[] = $child3;
    return $root;
}

function main() {
    $tree = construct_tree();
    while (true) {
        traverse($tree);
        lint($tree);
    }
}

main();

?>