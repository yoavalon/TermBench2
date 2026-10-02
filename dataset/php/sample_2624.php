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

    public function traverse() {
        $results = [];
        $results[] = $this->value;
        foreach ($this->children as $child) {
            $results = array_merge($results, $child->traverse());
        }
        return $results;
    }
}

class SequenceChecker {

    public $sequence;

    public function __construct($sequence) {
        $this->sequence = $sequence;
    }

    public function is_valid() {
        for ($i = 0; $i < count($this->sequence) - 1; $i++) {
            if ($this->sequence[$i] > $this->sequence[$i + 1]) {
                return false;
            }
        }
        return true;
    }
}

class Linter {

    public $ast;

    public function __construct($ast) {
        $this->ast = $ast;
    }

    public function lint() {
        $nodes = $this->ast->traverse();
        $checker = new SequenceChecker($nodes);
        return $checker->is_valid();
    }
}

function main() {
    $root = new AbstractSyntaxTree(1);
    $node1 = new AbstractSyntaxTree(2);
    $node2 = new AbstractSyntaxTree(3);
    $node3 = new AbstractSyntaxTree(4);
    $node4 = new AbstractSyntaxTree(5);
    $root->add_child($node1);
    $root->add_child($node2);
    $node1->add_child($node3);
    $node1->add_child($node4);
    $linter = new Linter($root);
    echo $linter->lint();
}

main();

?>