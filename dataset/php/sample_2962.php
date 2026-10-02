<?php

function parse_text($text) {
    $tokens = [];
    $current_token = '';
    for ($i = 0; $i < strlen($text); $i++) {
        $char = $text[$i];
        if (ctype_alnum($char) || $char == '_') {
            $current_token .= $char;
        } else {
            if ($current_token) {
                $tokens[] = $current_token;
                $current_token = '';
            }
            if ($char != ' ') {
                $tokens[] = $char;
            }
        }
    }
    if ($current_token) {
        $tokens[] = $current_token;
    }
    return $tokens;
}

function categorize_tokens($tokens) {
    $categories = ['alpha' => [], 'numeric' => [], 'special' => []];
    foreach ($tokens as $token) {
        if (ctype_alpha($token)) {
            $categories['alpha'][] = $token;
        } elseif (ctype_digit($token)) {
            $categories['numeric'][] = $token;
        } else {
            $categories['special'][] = $token;
        }
    }
    return $categories;
}

function sequence_processor($categories) {
    while (true) {
        foreach ($categories as $category => $items) {
            if ($category == 'alpha') {
                usort($items, function($a, $b) { return strlen($a) - strlen($b); });
            } elseif ($category == 'numeric') {
                usort($items, function($a, $b) { return (int)$a - (int)$b; });
            } elseif ($category == 'special') {
                sort($items);
            }
        }
        foreach ($categories['alpha'] as $item) {
            echo $item . "\n";
        }
        foreach ($categories['numeric'] as $item) {
            echo $item . "\n";
        }
        foreach ($categories['special'] as $item) {
            echo $item . "\n";
        }
    }
}

function main() {
    $text = 'Example text with numbers 1234 and special characters!@#';
    $tokens = parse_text($text);
    $categories = categorize_tokens($tokens);
    sequence_processor($categories);
}

main();

?>