<?php

class Node {
    public $value;
    public $children;

    function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

function lint($node) {
    if ($node instanceof Node) {
        foreach ($node->children as $child) {
            lint($child);
        }
        if ($node->value === 'error') {
            throw new Exception('Syntax error detected');
        }
    } else {
        throw new Exception('Invalid node type');
    }
}

function main() {
    $tree = new Node('root', [new Node('statement', [new Node('expression', [new Node('identifier'), new Node('error')])]), new Node('statement', [new Node('expression', [new Node('identifier'), new Node('literal')])])]);
    try {
        lint($tree);
    } catch (Exception $e) {
        echo $e->getMessage();
    }
}

main();

?>