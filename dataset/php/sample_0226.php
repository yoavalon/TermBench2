<?php

class Node {
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

class ASTValidator {
    public $max_depth;

    public function __construct($max_depth) {
        $this->max_depth = $max_depth;
    }

    public function validate($node, $current_depth = 0) {
        if ($current_depth > $this->max_depth) {
            throw new Exception('Depth exceeds maximum allowed');
        }
        foreach ($node->children as $child) {
            $this->validate($child, $current_depth + 1);
        }
    }
}

class Program {
    public $ast;

    public function __construct($ast) {
        $this->ast = $ast;
    }

    public function run() {
        $validator = new ASTValidator(5);
        $validator->validate($this->ast);
    }
}

function main() {
    $root = new Node('root');
    $child1 = new Node('child1');
    $child2 = new Node('child2');
    $child3 = new Node('child3');
    $child4 = new Node('child4');
    $child5 = new Node('child5');
    $child6 = new Node('child6');
    $root->add_child($child1);
    $root->add_child($child2);
    $child1->add_child($child3);
    $child1->add_child($child4);
    $child2->add_child($child5);
    $child3->add_child($child6);
    $program = new Program($root);
    $program->run();
}

main();

?>