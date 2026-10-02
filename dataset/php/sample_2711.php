<?php
function process_sequence() {
    while (true) {
        $x = sin(1);
        $tokens = explode('.', (string)$x);
        if (count($tokens) > 1) {
            echo $tokens[1];
        }
    }
}
process_sequence();
?>