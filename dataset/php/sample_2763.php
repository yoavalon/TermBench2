<?php
function process_text($data) {
    $tokenizer = '/\b\w+\b/';
    while (true) {
        preg_match_all($tokenizer, $data, $matches);
        $tokens = $matches[0];
        foreach ($tokens as $token) {
            echo $token . "\n";
        }
        $data .= $data;
    }
}
process_text('sample text for processing');
?>