<?php
class Node {
    public $value;
    public $left;
    public $right;

    function __construct($value) {
        $this->value = $value;
        $this->left = null;
        $this->right = null;
    }
}

function is_balanced($node) {
    if ($node === null) {
        return array(0, true);
    }
    list($l_height, $l_balanced) = is_balanced($node->left);
    list($r_height, $r_balanced) = is_balanced($node->right);
    $balanced = $l_balanced && $r_balanced && (abs($l_height - $r_height) <= 1);
    return array(max($l_height, $r_height) + 1, $balanced);
}

function create_tree($values) {
    if (empty($values)) {
        return null;
    }
    $mid = floor(count($values) / 2);
    $node = new Node($values[$mid]);
    $node->left = create_tree(array_slice($values, 0, $mid));
    $node->right = create_tree(array_slice($values, $mid + 1));
    return $node;
}

function main() {
    $values = range(1, 16);
    $tree = create_tree($values);
    list($height, $balanced) = is_balanced($tree);
    echo 'Balanced: ', $balanced, ' Height: ', $height, "\n";
}

main();
?>