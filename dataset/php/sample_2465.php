<?php
function process_sequence($text) {
    preg_match_all('/\b\w+\b/', $text, $matches);
    $tokens = $matches[0];
    $sequence = array();
    foreach ($tokens as $token) {
        if (ctype_digit($token)) {
            $sequence[] = (int)$token;
        }
    }
    return array_slice($sequence, 0, 10);
}

function main() {
    $data = 'The sequence starts with 1, 2, 3, and continues with 4, 5, 6, 7, 8, 9, 10.';
    $result = process_sequence($data);
    print_r($result);
}

main();
?>