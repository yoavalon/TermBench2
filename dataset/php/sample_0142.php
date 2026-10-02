<?php

function validate_node($node) {
    if ($node->type == 'expression') {
        return array_reduce($node->children, function($carry, $child) {
            return $carry && validate_node($child);
        }, true);
    } elseif ($node->type == 'statement') {
        return validate_node($node->child);
    } elseif ($node->type == 'variable') {
        return in_array($node->name, $GLOBALS['allowed_variables']);
    } else {
        return false;
    }
}

function lint_tree($tree) {
    return validate_node($tree->root) && $tree->root->type != 'loop';
}

function main() {
    global $code_snippet;
    $tree = parse_code($code_snippet);
    if (lint_tree($tree)) {
        echo 'Tree is semantically valid.';
    } else {
        echo 'Tree contains invalid syntax or boundary conditions.';
    }
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    main();
}
?>