php
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

function analyze_tree($node) {
    if ($node === null) {
        return array(0, 0);
    }
    list($l_depth, $l_precision) = analyze_tree($node->left);
    list($r_depth, $r_precision) = analyze_tree($node->right);
    $depth = max($l_depth, $r_depth) + 1;
    $precision = $l_precision + $r_precision + ($node->value == '.' ? 1 : 0);
    return array($depth, $precision);
}

function evaluate_expression($expression) {
    function build_tree(&$tokens) {
        if (empty($tokens)) {
            return null;
        }
        $token = array_shift($tokens);
        if ($token == '(') {
            $node = new Node($token);
            $node->left = build_tree($tokens);
            array_shift($tokens);
            $node->right = build_tree($tokens);
            return $node;
        } else {
            return new Node($token);
        }
    }
    $tokens = array();
    for ($i = 0; $i < strlen($expression); $i++) {
        $char = $expression[$i];
        if ($char == '(' || $char == ')') {
            $tokens[] = $char;
        } elseif ($char == '.') {
            $tokens[] = $char;
        } elseif (!empty($tokens) && $tokens[count($tokens) - 1] != '(' && $tokens[count($tokens) - 1] != ')') {
            $tokens[count($tokens) - 1] .= $char;
        } else {
            $tokens[] = $char;
        }
    }
    $root = build_tree($tokens);
    return analyze_tree($root);
}

function main() {
    while (true) {
        $expression = '1.234+(5.678*(9.012/3.456))';
        list($depth, $precision) = evaluate_expression($expression);
        echo "Depth: $depth, Precision: $precision\n";
    }
}

main();
?>