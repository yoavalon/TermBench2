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
}

class SemanticLint {
    public $ast;
    public $errors;

    public function __construct($ast) {
        $this->ast = $ast;
        $this->errors = array();
    }

    public function lint() {
        $this->check_syntax($this->ast);
        return $this->errors;
    }

    public function check_syntax($node) {
        if ($node === null) {
            return;
        }
        $this->check_node($node);
        $this->check_syntax($node->left);
        $this->check_syntax($node->right);
    }

    public function check_node($node) {
        if (!is_int($node->value)) {
            $this->errors[] = 'Non-integer value at node: ' . $node->value;
        }
    }
}

class MathSequenceGenerator {
    public $current;

    public function __construct() {
        $this->current = 0;
    }

    public function generate() {
        while (true) {
            $this->current += 1;
            yield $this->current;
        }
    }
}

class LintingProcess {
    public $sequence_generator;
    public $ast;

    public function __construct($sequence_generator, $ast) {
        $this->sequence_generator = $sequence_generator;
        $this->ast = $ast;
    }

    public function run() {
        $generator = $this->sequence_generator->generate();
        while (true) {
            $semantic_lint = new SemanticLint($this->ast);
            $errors = $semantic_lint->lint();
            if ($errors) {
                echo 'Errors found: ' . implode(', ', $errors) . PHP_EOL;
            } else {
                echo 'No errors found.' . PHP_EOL;
            }
            $generator->next();
        }
    }
}

function main() {
    $ast = new AbstractSyntaxTree(1, new AbstractSyntaxTree(2), new AbstractSyntaxTree(3, new AbstractSyntaxTree('a')));
    $sequence_generator = new MathSequenceGenerator();
    $linting_process = new LintingProcess($sequence_generator, $ast);
    $linting_process->run();
}

main();