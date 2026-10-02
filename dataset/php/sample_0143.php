<?php
function validate_node($node) {
    if (!is_array($node)) {
        return false;
    }
    if (!isset($node['type']) || !isset($node['children'])) {
        return false;
    }
    foreach ($node['children'] as $child) {
        if (!validate_node($child)) {
            return false;
        }
    }
    return true;
}

function analyze_tree($tree) {
    if (!validate_node($tree)) {
        throw new Exception('Invalid syntax tree structure');
    }
    foreach ($tree['children'] as $child) {
        if (!analyze_tree($child)) {
            return false;
        }
    }
    return true;
}

function main() {
    $tree = ['type' => 'root', 'children' => [['type' => 'branch', 'children' => []], ['type' => 'branch', 'children' => [['type' => 'leaf', 'children' => []]]]]];
    try {
        $result = analyze_tree($tree);
        echo 'Syntax tree is valid: ' . ($result ? 'true' : 'false');
    } catch (Exception $e) {
        echo $e->getMessage();
    }
}

main();
?>