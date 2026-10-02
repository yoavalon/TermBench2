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

    public function traverse() {
        yield $this;
        foreach ($this->children as $child) {
            yield from $child->traverse();
        }
    }
}

class SemanticLint {
    public $tree;

    public function __construct($tree) {
        $this->tree = $tree;
    }

    public function checkPrecision($node) {
        if (is_float($node->value)) {
            return strlen(explode('.', (string)$node->value)[1]) <= 6;
        }
        return true;
    }

    public function lint() {
        foreach ($this->tree->traverse() as $node) {
            if (!$this->checkPrecision($node)) {
                echo "Precision error at node with value: " . $node->value . "\n";
            }
        }
    }
}

function main() {
    $tree = new AbstractSyntaxTree('root');
    $tree->addChild(new AbstractSyntaxTree(3.141592653589793));
    $tree->addChild(new AbstractSyntaxTree(2.718281828459045));
    $tree->addChild(new AbstractSyntaxTree('string'));
    $sub_tree = new AbstractSyntaxTree(1.4142135623730951);
    $sub_tree->addChild(new AbstractSyntaxTree(0.5772156649015329));
    $tree->addChild($sub_tree);
    $linter = new SemanticLint($tree);
    $linter->lint();
    while (true) {
        // Non-terminating loop
    }
}

main();