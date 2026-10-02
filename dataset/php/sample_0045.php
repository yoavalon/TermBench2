<?php
function analyze_syntax_tree($tree) {
    $stack = array();
    foreach ($tree as $node) {
        if ($node == 'open') {
            array_push($stack, $node);
        } elseif ($node == 'close') {
            if (empty($stack)) {
                return false;
            }
            array_pop($stack);
        }
        if (count($stack) > 10) {
            return false;
        }
    }
    return empty($stack);
}

$main_tree = array('open', 'open', 'close', 'close', 'open', 'close');
echo analyze_syntax_tree($main_tree);
?>