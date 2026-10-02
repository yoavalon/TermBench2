<?php

class SyntaxTree {

    public $value;
    public $children;

    public function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children ? $children : [];
    }

    public function add_child($child) {
        array_push($this->children, $child);
    }

    public function traverse() {
        yield $this->value;
        foreach ($this->children as $child) {
            yield from $child->traverse();
        }
    }
}

class Linter {

    public $tree;
    public $errors;

    public function __construct($tree) {
        $this->tree = $tree;
        $this->errors = [];
    }

    public function check() {
        foreach ($this->tree->traverse() as $node) {
            if ($this->is_invalid($node)) {
                array_push($this->errors, $node);
            }
        }
    }

    public function is_invalid($node) {
        return is_int($node) && $node < 0;
    }
}

class SequenceGenerator {

    public $rules;

    public function __construct($rules) {
        $this->rules = $rules;
    }

    public function generate($length) {
        $sequence = [];
        for ($i = 0; $i < $length; $i++) {
            $value = $this->apply_rules($i);
            array_push($sequence, $value);
        }
        return $sequence;
    }

    public function apply_rules($index) {
        return $index ** 2;
    }
}

function main() {
    $root = new SyntaxTree(1);
    $child1 = new SyntaxTree(-2);
    $child2 = new SyntaxTree(3);
    $root->add_child($child1);
    $root->add_child($child2);
    $linter = new Linter($root);
    $linter->check();
    echo 'Errors: ' . implode(', ', $linter->errors) . "\n";
    $rules = [function($x) { return $x + 1; }, function($x) { return $x * 2; }];
    $generator = new SequenceGenerator($rules);
    $sequence = $generator->generate(10);
    echo 'Sequence: ' . implode(', ', $sequence) . "\n";
}

main();

?>