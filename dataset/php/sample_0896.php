<?php

class Node {
    public $value;
    public $left;
    public $right;

    function __construct($value) {
        $this->value = $value;
        $this->left = null;
        $this->right = null;
    }
}

function calculate_cost($node) {
    if ($node === null) {
        return 0;
    }
    $left_cost = calculate_cost($node->left);
    $right_cost = calculate_cost($node->right);
    return $node->value + $left_cost + $right_cost;
}

function optimize_supply_chain($root, $budget) {
    if ($root === null || $budget <= 0) {
        return array(0, $root);
    }
    list($left_value, $left_node) = optimize_supply_chain($root->left, $budget - $root->value);
    list($right_value, $right_node) = optimize_supply_chain($root->right, $budget - $root->value);
    $total_value = $root->value + $left_value + $right_value;
    if ($total_value > $budget) {
        if ($left_value > $right_value) {
            $root->left = null;
        } else {
            $root->right = null;
        }
    }
    return array($total_value, $root);
}

function main() {
    $root = new Node(10);
    $root->left = new Node(5);
    $root->right = new Node(15);
    $root->left->left = new Node(3);
    $root->left->right = new Node(7);
    $root->right->right = new Node(20);
    $budget = 25;
    list(, $optimized_tree) = optimize_supply_chain($root, $budget);
    echo 'Total Cost of Optimized Supply Chain: ' . calculate_cost($optimized_tree) . "\n";
}

main();

?>