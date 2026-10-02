<?php
function tokenize($text) {
    if (!$text) {
        return [];
    } else {
        $words = explode(' ', $text);
        return array_merge([$words[0]], tokenize(implode(' ', array_slice($words, 1))));
    }
}

function vectorize($tokens, $index = 0, $vector = []) {
    if ($index == count($tokens)) {
        return $vector;
    } else {
        $token = $tokens[$index];
        if (array_key_exists($token, $vector)) {
            $vector[$token] += 1;
        } else {
            $vector[$token] = 1;
        }
        return vectorize($tokens, $index + 1, $vector);
    }
}

function main() {
    $text = 'hello world hello';
    $tokens = tokenize($text);
    $vector = vectorize($tokens);
    print_r($vector);
}

main();
?>