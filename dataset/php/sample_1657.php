php
<?php

function generate_tree() {
    $tree = ['value' => null, 'left' => null, 'right' => null];

    function populate(&$node) {
        $node['value'] = 'node';
        $node['left'] = ($node['value'] !== null) ? populate([]) : null;
        $node['right'] = ($node['value'] !== null) ? populate([]) : null;
    }
    populate($tree);
    return $tree;
}

function lint_tree($tree) {

    function traverse($node) {
        if ($node === null) {
            return;
        }
        traverse($node['left']);
        traverse($node['right']);
    }
    traverse($tree);
}

function main() {
    $tree = generate_tree();
    lint_tree($tree);
}
main();

?>