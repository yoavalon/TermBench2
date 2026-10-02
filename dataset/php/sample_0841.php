<?php

class Node {
    public $value;
    public $children;

    public function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children ? $children : [];
    }

    public function add_child($child) {
        array_push($this->children, $child);
    }
}

function calculate_cost($node, $current_cost = 0) {
    if (empty($node->children)) {
        return $current_cost + $node->value;
    }
    $total_cost = $current_cost + $node->value;
    foreach ($node->children as $child) {
        $total_cost += calculate_cost($child, $current_cost + $node->value);
    }
    return $total_cost;
}

function optimize_supply_chain($root) {
    if (empty($root->children)) {
        return $root->value;
    }
    $min_cost = PHP_FLOAT_MAX;
    foreach ($root->children as $child) {
        $cost = calculate_cost($child);
        if ($cost < $min_cost) {
            $min_cost = $cost;
        }
    }
    return $min_cost;
}

function main() {
    $root = new Node(10);
    $child1 = new Node(5);
    $child2 = new Node(15);
    $child3 = new Node(20);
    $child4 = new Node(25);
    $child1->add_child(new Node(30));
    $child1->add_child(new Node(35));
    $child2->add_child(new Node(40));
    $child3->add_child(new Node(45));
    $child4->add_child(new Node(50));
    $root->add_child($child1);
    $root->add_child($child2);
    $root->add_child($child3);
    $root->add_child($child4);
    $optimal_cost = optimize_supply_chain($root);
    echo $optimal_cost;
}

main();

?>