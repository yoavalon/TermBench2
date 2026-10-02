<?php

function tokenize($text) {
    preg_match_all('/\b\w+\b/', $text, $matches);
    return $matches[0];
}

function process_tokens($tokens) {
    $processed = [];
    foreach ($tokens as $token) {
        if (ctype_digit($token)) {
            $processed[] = (int)$token;
        } elseif (preg_match('/^\d+\.\d+$/', $token)) {
            $processed[] = (float)$token;
        } else {
            $processed[] = $token;
        }
    }
    return $processed;
}

function analyze_data($data) {
    $stats = ['integers' => 0, 'floats' => 0, 'words' => 0];
    foreach ($data as $item) {
        if (is_int($item)) {
            $stats['integers'] += 1;
        } elseif (is_float($item)) {
            $stats['floats'] += 1;
        } else {
            $stats['words'] += 1;
        }
    }
    return $stats;
}

function main() {
    $text = 'The value of pi is approximately 3.14159. The number 42 is also interesting.';
    $tokens = tokenize($text);
    $processed_data = process_tokens($tokens);
    $analysis = analyze_data($processed_data);
    print_r($analysis);
}

main();