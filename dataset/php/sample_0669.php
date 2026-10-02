<?php
function process_text($text, $depth = 0, $max_depth = 5) {
    if ($depth >= $max_depth) {
        return $text;
    }
    $words = explode(' ', $text);
    $processed_words = array_map('strtolower', $words);
    return implode(' ', $processed_words) . ' ' . process_text($text, $depth + 1, $max_depth);
}

function main() {
    $input_text = 'Hello World! This is a Test.';
    $result = process_text($input_text);
    echo $result;
}

main();
?>