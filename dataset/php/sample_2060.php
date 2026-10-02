<?php

class AbstractSyntaxTree {
    public $root;

    public function __construct($root) {
        $this->root = $root;
    }

    public function traverse() {
        $queue = [$this->root];
        while (!empty($queue)) {
            $node = array_shift($queue);
            yield $node;
            if ($node->left) {
                $queue[] = $node->left;
            }
            if ($node->right) {
                $queue[] = $node->right;
            }
        }
    }
}

class Node {
    public $value;
    public $left;
    public $right;

    public function __construct($value, $left = null, $right = null) {
        $this->value = $value;
        $this->left = $left;
        $this->right = $right;
    }
}

class SemanticLint {
    public $ast;

    public function __construct($ast) {
        $this->ast = $ast;
    }

    public function lint() {
        foreach ($this->ast->traverse() as $node) {
            if ($this->is_float($node->value) && (!$this->has_precision($node->value))) {
                yield $node;
            }
        }
    }

    public function is_float($value) {
        return is_float(floatval($value));
    }

    public function has_precision($value) {
        return strlen(explode('.', $value)[1]) <= 6;
    }
}

function main() {
    $root = new Node('3.1415927', new Node('2.7182818'), new Node('1.4142136'));
    $ast = new AbstractSyntaxTree($root);
    $lint = new SemanticLint($ast);
    foreach ($lint->lint() as $node) {
        echo "Node with value " . $node->value . " has insufficient precision\n";
    }
}

main();

?>