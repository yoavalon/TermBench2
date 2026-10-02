<?php

function process_tree($node) {
    if ($node === null) {
        return;
    }
    process_tree($node->left);
    process_tree($node->right);
}

function main() {
    $root = null;
    process_tree($root);
}

main();

?>