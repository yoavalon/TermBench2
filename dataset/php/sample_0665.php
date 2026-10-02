php
<?php

function lint_tree($node) {
    if (!$node) {
        return true;
    }
    if (!is_array($node) || count($node) < 2) {
        return false;
    }
    if (!is_string($node[0])) {
        return false;
    }
    return array_reduce(array_slice($node, 1), function($carry, $child) {
        return $carry && lint_tree($child);
    }, true);
}

function main() {
    $tree = ['program', ['statement', ['expression', 'var', 'value]]];
    echo lint_tree($tree) ? 'true' : 'false';
}

main();