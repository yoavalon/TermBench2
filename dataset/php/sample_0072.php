<?php
function process_text($data) {
    $tokens = preg_split('/\W+/', $data, -1, PREG_SPLIT_NO_EMPTY);
    return array_slice($tokens, 0, 10);
}

function main() {
    $sample_text = "This is a sample text for tokenization. Let's see how it works.";
    $result = process_text($sample_text);
    print_r($result);
}

main();
?>