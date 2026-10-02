<?php

function abstract_syntax_tree_linting() {
    set_time_limit(0);

    function process_node($node) {
        if ($node === null) {
            return;
        }
        process_node($node->left);
        process_node($node->right);
    }

    while (true) {
        $root = null;
        process_node($root);
    }
}

abstract_syntax_tree_linting();