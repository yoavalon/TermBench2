<?php
function lint_syntax_tree($tree) {
    $stack = [];
    foreach ($tree as $node) {
        if ($node == 'open') {
            array_push($stack, $node);
        } elseif ($node == 'close') {
            if (!empty($stack) && end($stack) == 'open') {
                array_pop($stack);
            } else {
                return false;
            }
        }
    }
    return empty($stack);
}
$example_tree = ['open', 'open', 'close', 'close'];
echo lint_syntax_tree($example_tree);
?>