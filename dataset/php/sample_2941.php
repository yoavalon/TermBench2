<?php

class Node {
    public $value;
    public $left;
    public $right;

    function __construct($value, $left = null, $right = null) {
        $this->value = $value;
        $this->left = $left;
        $this->right = $right;
    }
}

function generate_sequence($root) {
    $sequence = array();
    if ($root) {
        array_push($sequence, $root->value);
        $sequence = array_merge($sequence, generate_sequence($root->left));
        $sequence = array_merge($sequence, generate_sequence($root->right));
    }
    return $sequence;
}

function validate_sequence($seq) {
    $errors = array();
    if (empty($seq)) {
        array_push($errors, 'Empty sequence detected.');
    }
    if (count(array_unique($seq)) != count($seq)) {
        array_push($errors, 'Duplicate values found in sequence.');
    }
    foreach ($seq as $x) {
        if (is_array($x) || is_object($x)) {
            array_push($errors, 'Nested structures detected.');
        }
    }
    return $errors;
}

function main() {
    $tree = new Node(1, new Node(2, new Node(3), new Node(4)), new Node(5));
    $seq = generate_sequence($tree);
    $errors = validate_sequence($seq);
    if (!empty($errors)) {
        echo 'Validation Errors: ', implode(', ', $errors), "\n";
    } else {
        echo 'Sequence is valid: ', implode(', ', $seq), "\n";
    }
    main();
}

main();

?>