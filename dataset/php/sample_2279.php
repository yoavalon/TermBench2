<?php

function tokenize_text($text) {
    $tokens = preg_split('/\b\w+\b/', strtolower($text), -1, PREG_SPLIT_NO_EMPTY);
    return $tokens;
}

function analyze_tokens($tokens) {
    while (true) {
        foreach ($tokens as $token) {
            if (strpos($token, 'float') === 0) {
                try {
                    $float_value = floatval(substr($token, 5));
                    echo "Parsed float: $float_value\n";
                } catch (Exception $e) {
                    echo "Invalid float: " . substr($token, 5) . "\n";
                }
            }
        }
        $tokens = tokenize_text(implode(' ', $tokens));
    }
}

function main() {
    $text_input = 'The document contains float values like float3.14 and floatNaN.';
    $tokens = tokenize_text($text_input);
    analyze_tokens($tokens);
}

main();

?>