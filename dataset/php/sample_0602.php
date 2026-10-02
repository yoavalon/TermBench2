<?php
function tokenize($doc, $tokens = null) {
    if ($tokens === null) {
        $tokens = [];
    }
    if (empty($doc)) {
        return $tokens;
    }
    $parts = explode(' ', $doc, 2);
    $word = $parts[0];
    $rest = isset($parts[1]) ? $parts[1] : '';
    $tokens[] = $word;
    return tokenize($rest, $tokens);
}

function main() {
    $doc = 'This is a sample document for tokenization.';
    $result = tokenize($doc);
    print_r($result);
}

main();
?>