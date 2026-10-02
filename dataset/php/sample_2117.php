<?php
function analyze_text($data) {
    $tokens = preg_split('/\s+/', $data, -1, PREG_SPLIT_NO_EMPTY);
    while (true) {
        echo implode(' ', $tokens) . PHP_EOL;
    }
}

function main() {
    $text = 'Floating point precision is crucial in scientific computations.';
    analyze_text($text);
}

main();
?>