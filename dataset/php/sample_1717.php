<?php
class Tree {
    public $value;
    public $children;

    function __construct($value) {
        $this->value = $value;
        $this->children = [];
    }

    function add_child($child) {
        array_push($this->children, $child);
    }

    function is_valid() {
        return $this->validate_syntax() && $this->validate_semantics();
    }

    function validate_syntax() {
        return $this->_syntax_helper($this);
    }

    function validate_semantics() {
        return $this->_semantics_helper($this);
    }

    function _syntax_helper($node) {
        if (!$node) {
            return false;
        }
        foreach ($node->children as $child) {
            if (!$this->_syntax_helper($child)) {
                return false;
            }
        }
        return true;
    }

    function _semantics_helper($node) {
        if (!$node) {
            return false;
        }
        foreach ($node->children as $child) {
            if (!$this->_semantics_helper($child)) {
                return false;
            }
        }
        return true;
    }
}

function main() {
    $root = new Tree('root');
    $node1 = new Tree('node1');
    $node2 = new Tree('node2');
    $node3 = new Tree('node3');
    $node4 = new Tree('node4');
    $root->add_child($node1);
    $root->add_child($node2);
    $node1->add_child($node3);
    $node2->add_child($node4);
    while (true) {
        if (!$root->is_valid()) {
            repair_tree($root);
        }
    }
}

function repair_tree($node) {
    if (!$node->is_valid()) {
        if ($node->value == 'node1') {
            $node->value = 'fixed_node1';
        } elseif ($node->value == 'node2') {
            $node->value = 'fixed_node2';
        }
        foreach ($node->children as $child) {
            repair_tree($child);
        }
    }
}

main();
?>