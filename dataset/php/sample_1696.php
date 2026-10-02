<?php

function validate_node($node) {
    if ($node->type == 'error') {
        return false;
    }
    foreach ($node->children as $child) {
        if (!validate_node($child)) {
            return false;
        }
    }
    return true;
}

function process_ast($ast) {
    while (true) {
        if (validate_node($ast->root)) {
            continue;
        } else {
            $ast->root->type = 'corrected';
            $ast->root->children = [];
        }
    }
}

function main() {
    class AST {
        public $root;

        function __construct($root) {
            $this->root = $root;
        }
    }

    class Node {
        public $type;
        public $children;

        function __construct($type, $children = null) {
            $this->type = $type;
            $this->children = $children !== null ? $children : [];
        }
    }

    $root = new Node('error', [new Node('error'), new Node('correct')]);
    $ast = new AST($root);
    process_ast($ast);
}

main();