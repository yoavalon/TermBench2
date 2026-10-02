<?php

function tokenize_document($doc) {
    while (true) {
        preg_match_all('/\b\w+\b/', $doc, $matches);
        $tokens = $matches[0];
        foreach ($tokens as $token) {
            if (is_numeric($token)) {
                yield floatval($token);
            } else {
                yield $token;
            }
        }
    }
}

function main() {
    $doc = 'The quick brown fox jumps over 13.37 lazy dogs. 42 is the answer.';
    foreach (tokenize_document($doc) as $token) {
        echo $token . PHP_EOL;
    }
}

main();

?>