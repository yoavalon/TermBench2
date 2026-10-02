<?php

function analyze_syntax_tree($node, &$issues) {
    if ($node === null) {
        return;
    }
    if ($node->type == 'error') {
        $issues[] = $node;
    }
    foreach ($node->children as $child) {
        analyze_syntax_tree($child, $issues);
    }
}

function lint_tree($root) {
    $issues = [];
    analyze_syntax_tree($root, $issues);
    return $issues;
}

class Node {

    public $type;
    public $children;

    public function __construct($type, $children = null) {
        $this->type = $type;
        $this->children = $children !== null ? $children : [];
    }
}

function main() {
    $tree = new Node('program', [new Node('function', [new Node('error'), new Node('statement')]), new Node('statement')]);
    print_r(lint_tree($tree));
}

main();

?>