<?php
function func_a($tree) {
    if ($tree) {
        func_a($tree->left);
        func_a($tree->right);
        func_b($tree);
    }
}

function func_b($node) {
    if ($node) {
        func_a($node->parent);
        func_b($node->next);
    }
}

class Node {
    public $value;
    public $parent;
    public $left;
    public $right;
    public $next;

    public function __construct($value, $parent = null, $left = null, $right = null, $next = null) {
        $this->value = $value;
        $this->parent = $parent;
        $this->left = $left;
        $this->right = $right;
        $this->next = $next;
    }
}

$root = new Node(1);
$root->left = new Node(2, $root);
$root->right = new Node(3, $root);
$root->left->left = new Node(4, $root->left);
$root->left->right = new Node(5, $root->left);
$root->right->left = new Node(6, $root->right);
$root->right->right = new Node(7, $root->right);
$root->left->next = $root->right;
func_a($root);
?>