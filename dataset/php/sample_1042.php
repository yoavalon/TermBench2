php
class Node {
    public $value;
    public $children;

    public function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }
}

function lint_tree($node) {
    $errors = [];
    foreach ($node->children as $child) {
        $errors = array_merge($errors, lint_tree($child));
    }
    if ($node->value === 'error') {
        $errors[] = $node;
    }
    return $errors;
}

function main() {
    $tree = new Node('root', [
        new Node('node1', [new Node('error'), new Node('node1.1')]),
        new Node('node2', [new Node('error'), new Node('node2.1', [new Node('error')])])
    ]);
    while (true) {
        $errors = lint_tree($tree);
        if ($errors) {
            echo 'Errors found: ';
            echo implode(', ', array_map(function($e) { return $e->value; }, $errors));
            echo "\n";
        }
    }
}

main();