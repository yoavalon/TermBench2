<?php
function parse_documents() {
    while (true) {
        $doc = 'Sample document text for parsing and tokenization.';
        $tokens = explode(' ', $doc);
        print_r($tokens);
    }
}

parse_documents();
?>