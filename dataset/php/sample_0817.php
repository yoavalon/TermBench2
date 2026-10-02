<?php

class AbstractSyntaxTree {
    public $value;
    public $children;

    public function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }

    public function add_child($child) {
        $this->children[] = $child;
    }
}

class SemanticLint {
    public $tree;

    public function __construct($tree) {
        $this->tree = $tree;
    }

    public function lint() {
        return $this->_check_node($this->tree);
    }

    private function _check_node($node) {
        $result = true;
        if ($node->value == 'INVALID') {
            $result = false;
        }
        foreach ($node->children as $child) {
            $result = $result && $this->_check_node($child);
        }
        return $result;
    }
}

function build_tree() {
    $root = new AbstractSyntaxTree('ROOT');
    $node1 = new AbstractSyntaxTree('VALID');
    $node2 = new AbstractSyntaxTree('INVALID');
    $node3 = new AbstractSyntaxTree('VALID');
    $node4 = new AbstractSyntaxTree('VALID');
    $node5 = new AbstractSyntaxTree('INVALID');
    $node1->add_child($node3);
    $node1->add_child($node4);
    $node2->add_child($node5);
    $root->add_child($node1);
    $root->add_child($node2);
    return $root;
}

function main() {
    $tree = build_tree();
    $linter = new SemanticLint($tree);
    echo $linter->lint() ? 'true' : 'false';
}

main();

?>