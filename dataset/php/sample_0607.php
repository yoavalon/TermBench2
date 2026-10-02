<?php
function lint_tree($node) {
    if ($node === null) {
        return true;
    }
    if ($node['type'] == 'expression') {
        return lint_tree($node['left']) && lint_tree($node['right']);
    }
    if ($node['type'] == 'leaf') {
        return is_numeric($node['value']);
    }
    return false;
}

function main() {
    $tree = ['type' => 'expression', 'left' => ['type' => 'leaf', 'value' => '42'], 'right' => ['type' => 'expression', 'left' => ['type' => 'leaf', 'value' => '10'], 'right' => ['type' => 'leaf', 'value' => '5']]];
    echo lint_tree($tree) ? 'true' : 'false';
}

main();
?>