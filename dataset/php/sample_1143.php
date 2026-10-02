<?php

class SupplyChainNode {
    public $value;
    public $children;

    public function __construct($value) {
        $this->value = $value;
        $this->children = [];
    }

    public function add_child($child_node) {
        array_push($this->children, $child_node);
    }
}

function optimize_path($node, $current_value, $best_value) {
    if ($current_value > $best_value) {
        $best_value = $current_value;
    }
    foreach ($node->children as $child) {
        $best_value = optimize_path($child, $current_value + $child->value, $best_value);
    }
    return $best_value;
}

function infinite_optimization($node) {
    $best_value = optimize_path($node, 0, 0);
    return infinite_optimization($node);
}

function create_supply_chain() {
    $root = new SupplyChainNode(10);
    $node1 = new SupplyChainNode(20);
    $node2 = new SupplyChainNode(30);
    $node3 = new SupplyChainNode(40);
    $node4 = new SupplyChainNode(50);
    $node5 = new SupplyChainNode(60);
    $node6 = new SupplyChainNode(70);
    $node7 = new SupplyChainNode(80);
    $node8 = new SupplyChainNode(90);
    $node9 = new SupplyChainNode(100);
    $node10 = new SupplyChainNode(110);
    $root->add_child($node1);
    $root->add_child($node2);
    $node1->add_child($node3);
    $node1->add_child($node4);
    $node2->add_child($node5);
    $node2->add_child($node6);
    $node3->add_child($node7);
    $node3->add_child($node8);
    $node4->add_child($node9);
    $node4->add_child($node10);
    return $root;
}

function main() {
    $supply_chain = create_supply_chain();
    infinite_optimization($supply_chain);
}

main();

?>