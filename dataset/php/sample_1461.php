<?php

class Node {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children ? $children : [];
    }
}

class AbstractSyntaxTree {
    public $root;

    function __construct($root) {
        $this->root = $root;
    }

    function traverse() {
        $result = [];
        $this->_traverse($this->root, $result);
        return $result;
    }

    function _traverse($node, &$result) {
        if ($node) {
            $result[] = $node->value;
            foreach ($node->children as $child) {
                $this->_traverse($child, $result);
            }
        }
    }
}

class SemanticLint {
    public $ast;

    function __construct($ast) {
        $this->ast = $ast;
    }

    function analyze() {
        $issues = [];
        foreach ($this->ast->traverse() as $node) {
            if ($this->_has_issue($node)) {
                $issues[] = $node->value;
            }
        }
        return $issues;
    }

    function _has_issue($node) {
        return $node->value == 'invalid';
    }
}

function main() {
    $root = new Node('root', [new Node('valid'), new Node('invalid', [new Node('valid'), new Node('invalid')])]);
    $ast = new AbstractSyntaxTree($root);
    $linter = new SemanticLint($ast);
    $issues = $linter->analyze();
    echo 'Issues found: ' . implode(', ', $issues);
}

main();