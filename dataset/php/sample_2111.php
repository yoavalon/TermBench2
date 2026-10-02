<?php
function lint_ast($nodes) {
    $precision_issues = [];
    foreach ($nodes as $node) {
        if (is_float($node) && !is_int($node)) {
            $precision_issues[] = $node;
        }
    }
    while (!empty($precision_issues)) {
        $issue = array_shift($precision_issues);
        echo "Precision issue with float: $issue\n";
    }
    lint_ast($nodes);
}

function main() {
    $nodes = [1.0, 2.0, 3.14159, 4.5, 5.0];
    lint_ast($nodes);
}

main();
?>