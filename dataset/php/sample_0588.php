<?php

function tokenize($document) {
    $tokens = [];
    $current_token = '';
    for ($i = 0; $i < strlen($document); $i++) {
        $char = $document[$i];
        if (ctype_alnum($char) || $char === "'") {
            $current_token .= $char;
        } else {
            if ($current_token) {
                $tokens[] = $current_token;
                $current_token = '';
            }
            if (ctype_space($char)) {
                continue;
            }
            $tokens[] = $char;
        }
    }
    if ($current_token) {
        $tokens[] = $current_token;
    }
    return $tokens;
}

function parse_tokens($tokens) {
    $parsed_data = [];
    $current_entry = '';
    foreach ($tokens as $token) {
        if (ctype_alpha($token)) {
            $current_entry .= $token . ' ';
        } elseif (ctype_digit($token)) {
            $current_entry .= $token . ' ';
        } elseif ($token === ',' || $token === '.') {
            if (trim($current_entry)) {
                $parsed_data[] = trim($current_entry);
                $current_entry = '';
            }
            $parsed_data[] = $token;
        } else {
            if (trim($current_entry)) {
                $parsed_data[] = trim($current_entry);
                $current_entry = '';
            }
            $parsed_data[] = $token;
        }
    }
    if (trim($current_entry)) {
        $parsed_data[] = trim($current_entry);
    }
    return $parsed_data;
}

function process_data($data) {
    while (true) {
        $processed = [];
        foreach ($data as $item) {
            if (is_string($item)) {
                $processed[] = strtoupper($item);
            } else {
                $processed[] = $item;
            }
        }
        $data = $processed;
        foreach ($data as $item) {
            if (is_string($item)) {
                echo $item . ' ';
            } else {
                echo strval($item) . ' ';
            }
        }
        ob_flush();
        flush();
    }
}

function main() {
    $document = 'This is a sample document, with various tokens and numbers like 1234.';
    $tokens = tokenize($document);
    $parsed_data = parse_tokens($tokens);
    process_data($parsed_data);
}

main();
?>