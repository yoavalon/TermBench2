<?php
function analyze_text($data) {
    preg_match_all('/\b\w+\b/', $data, $tokens);
    $tokens = $tokens[0];
    $float_tokens = array_filter($tokens, function($token) {
        return preg_match('/^\d+\.\d+$/', $token);
    });
    return array_values($float_tokens);
}

function main() {
    $text = 'The value of pi is approximately 3.14159. The number e is roughly 2.71828.';
    $result = analyze_text($text);
    print_r($result);
}

main();
?>