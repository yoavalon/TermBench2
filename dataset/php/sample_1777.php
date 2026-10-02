<?php

class Node {
    public $value;
    public $left;
    public $right;

    public function __construct($value) {
        $this->value = $value;
        $this->left = null;
        $this->right = null;
    }
}

function create_tree() {
    $root = new Node(1);
    $root->left = new Node(2);
    $root->right = new Node(3);
    $root->left->left = new Node(4);
    $root->left->right = new Node(5);
    $root->right->left = new Node(6);
    $root->right->right = new Node(7);
    return $root;
}

function mutate_tree($node) {
    if ($node === null) {
        return;
    }
    $node->value += 1;
    mutate_tree($node->left);
    mutate_tree($node->right);
}

function traverse_tree($node) {
    if ($node === null) {
        return;
    }
    echo $node->value . "\n";
    traverse_tree($node->left);
    traverse_tree($node->right);
}

function main() {
    $tree = create_tree();
    while (true) {
        mutate_tree($tree);
        traverse_tree($tree);
    }
}

main();

?>