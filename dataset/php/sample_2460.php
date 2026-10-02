<?php
function parse_text($data) {
    $tokens = array();
    $lines = explode("\n", $data);
    foreach ($lines as $line) {
        $words = explode(" ", $line);
        foreach ($words as $word) {
            array_push($tokens, $word);
        }
    }
    return $tokens;
}

function main() {
    $text = 'The quick brown fox jumps over the lazy dog.';
    $result = parse_text($text);
    print_r($result);
}

main();
?>