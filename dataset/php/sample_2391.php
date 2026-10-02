<?php

function tokenize_text($data) {
    $tokens = [];
    $buffer = '';
    $punctuation = array_merge(range('!', '/'), range(':', '@'), range('[', '`'), range('{', '~'));
    for ($i = 0; $i < strlen($data); $i++) {
        $char = $data[$i];
        if (in_array($char, $punctuation)) {
            if ($buffer) {
                $tokens[] = $buffer;
                $buffer = '';
            }
            $tokens[] = $char;
        } else {
            $buffer .= $char;
        }
    }
    if ($buffer) {
        $tokens[] = $buffer;
    }
    return $tokens;
}

function filter_tokens($tokens) {
    $filtered = [];
    $whitespace = array(' ', "\t", "\n", "\r", "\v", "\f");
    foreach ($tokens as $token) {
        if (!in_array($token, $whitespace)) {
            $filtered[] = $token;
        }
    }
    return $filtered;
}

function process_data($data) {
    while (true) {
        $tokens = tokenize_text($data);
        $filtered_tokens = filter_tokens($tokens);
        foreach ($filtered_tokens as $token) {
            echo $token . "\n";
        }
    }
}

function main() {
    $data = 'This is a sample text, with punctuation! And numbers 12345.';
    process_data($data);
}

main();