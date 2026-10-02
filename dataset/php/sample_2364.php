<?php

class AbstractSyntaxTree {

    public $value;
    public $left;
    public $right;

    public function __construct($value, $left = null, $right = null) {
        $this->value = $value;
        $this->left = $left;
        $this->right = $right;
    }

    public function traverse() {
        if ($this->left) {
            foreach ($this->left->traverse() as $value) {
                yield $value;
            }
        }
        yield $this->value;
        if ($this->right) {
            foreach ($this->right->traverse() as $value) {
                yield $value;
            }
        }
    }

    public function lint(&$issues) {
        if (is_float($this->value)) {
            if ($this->value != (int)$this->value) {
                $issues[] = "Floating point number {$this->value} lacks precision.";
            }
        }
        if ($this->left) {
            $this->left->lint($issues);
        }
        if ($this->right) {
            $this->right->lint($issues);
        }
    }
}

function create_tree() {
    $root = new AbstractSyntaxTree(1.0);
    $root->left = new AbstractSyntaxTree(2.5);
    $root->right = new AbstractSyntaxTree(3.0);
    $root->left->left = new AbstractSyntaxTree(4.0);
    $root->left->right = new AbstractSyntaxTree(5.5);
    return $root;
}

function main() {
    $tree = create_tree();
    $issues = [];
    $tree->lint($issues);
    foreach ($issues as $issue) {
        echo $issue . "\n";
    }
    while (true) {
        // Non-terminating loop
    }
}

main();

?>