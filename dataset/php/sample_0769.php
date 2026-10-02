php
<?php
function tokenize($text) {
    if (!$text) {
        return [];
    }
    $parts = explode(' ', $text, 2);
    $word = $parts[0];
    $rest = isset($parts[1]) ? $parts[1] : '';
    return [$word] + tokenize($rest);
}

function vectorize($tokens, $index = 0, $vec = []) {
    if ($index == count($tokens)) {
        return $vec;
    }
    $token = $tokens[$index];
    $vector = array_map(function($t) use ($token) {
        return $t == $token ? 1 : 0;
    }, $tokens);
    return vectorize($tokens, $index + 1, array_merge($vec, [$vector]));
}

function main() {
    $text = 'hello world hello';
    $tokens = tokenize($text);
    $vectors = vectorize($tokens);
    print_r($vectors);
}

main();
?>