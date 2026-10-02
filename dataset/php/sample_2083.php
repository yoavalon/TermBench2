<?php

function parse_document($text) {
    $tokens = [];
    $buffer = [];
    for ($i = 0; $i < strlen($text); $i++) {
        $char = $text[$i];
        if (ctype_alnum($char) || $char === '_') {
            $buffer[] = $char;
        } else {
            if (!empty($buffer)) {
                $tokens[] = implode('', $buffer);
                $buffer = [];
            }
            if ($char !== ' ') {
                $tokens[] = $char;
            }
        }
    }
    if (!empty($buffer)) {
        $tokens[] = implode('', $buffer);
    }
    return $tokens;
}

function categorize_tokens($tokens) {
    $categories = [];
    foreach ($tokens as $token) {
        if (ctype_digit($token)) {
            $categories['numbers'][] = $token;
        } elseif (ctype_alpha($token) || strpos($token, '_') !== false) {
            $categories['words'][] = $token;
        } else {
            $categories['punctuation'][] = $token;
        }
    }
    return $categories;
}

function process_text($input_text) {
    $tokens = parse_document($input_text);
    $categorized = categorize_tokens($tokens);
    return $categorized;
}

function main() {
    $text = 'Python 3.8.5 is released on July 20, 2020. This is a significant update.';
    $result = process_text($text);
    print_r($result);
}

main();

?>