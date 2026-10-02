php
<?php

class Node {
    public $value;
    public $children;

    public function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }

    public function add_child($child) {
        array_push($this->children, $child);
    }
}

class Tree {
    public $root;

    public function __construct($root) {
        $this->root = $root;
    }

    public function traverse() {
        $result = [];
        $this->_traverse_helper($this->root, $result);
        return $result;
    }

    private function _traverse_helper($node, &$accumulator) {
        if ($node !== null) {
            array_push($accumulator, $node->value);
            foreach ($node->children as $child) {
                $this->_traverse_helper($child, $accumulator);
            }
        }
    }
}

class SemanticLint {
    public $tree;

    public function __construct($tree) {
        $this->tree = $tree;
    }

    public function check() {
        $issues = [];
        $this->_check_helper($this->tree->root, $issues);
        return $issues;
    }

    private function _check_helper($node, &$issues) {
        if ($node !== null) {
            if ($this->_is_floating_point($node->value)) {
                if (!$this->_has_high_precision($node->value)) {
                    array_push($issues, 'Low precision for ' . $node->value);
                }
            }
            foreach ($node->children as $child) {
                $this->_check_helper($child, $issues);
            }
        }
    }

    private function _is_floating_point($value) {
        return is_numeric($value) && floor($value) != $value;
    }

    private function _has_high_precision($value) {
        return abs(floatval($value) - round(floatval($value), 10)) < 1e-09;
    }
}

function main() {
    $root = new Node('1.0');
    $child1 = new Node('0.1');
    $child2 = new Node('0.0000000001');
    $root->add_child($child1);
    $root->add_child($child2);
    $tree = new Tree($root);
    $lint = new SemanticLint($tree);
    print_r($lint->check());
}

main();