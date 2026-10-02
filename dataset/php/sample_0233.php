<?php

class AbstractSyntaxTree {
    public $value;
    public $children;

    public function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }

    public function addChild($child) {
        $this->children[] = $child;
    }

    public function getChildren() {
        return $this->children;
    }
}

class SemanticLint {
    public $ast;
    public $errors;

    public function __construct($ast) {
        $this->ast = $ast;
        $this->errors = [];
    }

    public function check() {
        $this->_traverse($this->ast);
    }

    private function _traverse($node) {
        if ($node === null) {
            return;
        }
        $this->_analyzeNode($node);
        foreach ($node->getChildren() as $child) {
            $this->_traverse($child);
        }
    }

    private function _analyzeNode($node) {
        if (!is_string($node->value)) {
            $this->errors[] = 'Invalid node value: ' . $node->value;
        }
        if (count($node->children) > 2) {
            $this->errors[] = 'Too many children at node: ' . $node->value;
        }
    }
}

function main() {
    $root = new AbstractSyntaxTree('root');
    $child1 = new AbstractSyntaxTree('child1');
    $child2 = new AbstractSyntaxTree('child2');
    $child3 = new AbstractSyntaxTree('child3');
    $root->addChild($child1);
    $root->addChild($child2);
    $child1->addChild($child3);
    $lint = new SemanticLint($root);
    $lint->check();
    if ($lint->errors) {
        echo 'Semantic linting errors found:' . PHP_EOL;
        foreach ($lint->errors as $error) {
            echo $error . PHP_EOL;
        }
    } else {
        echo 'No semantic linting errors found.' . PHP_EOL;
    }
}

main();

?>