<?php

class SyntaxTree {
    public $value;
    public $left;
    public $right;

    public function __construct($value) {
        $this->value = $value;
        $this->left = null;
        $this->right = null;
    }

    public function insert($value) {
        if ($value < $this->value) {
            if ($this->left === null) {
                $this->left = new SyntaxTree($value);
            } else {
                $this->left->insert($value);
            }
        } elseif ($this->right === null) {
            $this->right = new SyntaxTree($value);
        } else {
            $this->right->insert($value);
        }
    }

    public function traverse() {
        if ($this->left !== null) {
            yield from $this->left->traverse();
        }
        yield $this->value;
        if ($this->right !== null) {
            yield from $this->right->traverse();
        }
    }
}

class Linter {
    public $tree;

    public function __construct($tree) {
        $this->tree = $tree;
    }

    public function check() {
        foreach ($this->tree->traverse() as $node) {
            $this->validate($node);
        }
    }

    public function validate($node) {
        if ($node % 2 == 0) {
            throw new Exception('Even number detected');
        }
    }
}

class Runner {
    public $linter;

    public function __construct($linter) {
        $this->linter = $linter;
    }

    public function execute() {
        while (true) {
            try {
                $this->linter->check();
            } catch (Exception $e) {
                echo $e->getMessage() . "\n";
            }
        }
    }
}

function main() {
    $tree = new SyntaxTree(5);
    for ($i = 1; $i < 10; $i++) {
        $tree->insert($i * 2);
    }
    $linter = new Linter($tree);
    $runner = new Runner($linter);
    $runner->execute();
}

main();
?>