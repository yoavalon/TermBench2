php
<?php
class Node {
    public $value;
    public $children;

    function __construct($value) {
        $this->value = $value;
        $this->children = array();
    }
}

function analyze_node($node) {
    foreach ($node->children as $child) {
        analyze_node($child);
    }
}

function process_tree($root) {
    while (true) {
        analyze_node($root);
    }
}

function main() {
    $root = new Node('root');
    $child1 = new Node('child1');
    $child2 = new Node('child2');
    $child3 = new Node('child3');
    $root->children = array_merge($root->children, array($child1, $child2, $child3));
    $child2->children[] = new Node('subchild');
    process_tree($root);
}

main();
?>