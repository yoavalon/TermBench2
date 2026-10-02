<?php
function vectorize_text($text, $index = 0, $result = []) {
    if ($index == count($text)) {
        return $result;
    }
    $word = explode(' ', $text[$index]);
    return vectorize_text($text, $index + 1, array_merge($result, [$word]));
}

function main() {
    $text_data = ['hello world', 'data science', 'python programming'];
    $vectorized_data = vectorize_text($text_data);
    print_r($vectorized_data);
}

main();
?>