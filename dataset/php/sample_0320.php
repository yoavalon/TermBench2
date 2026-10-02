<?php
function main() {
    $x = 0;
    $decay_rate = 0.99;
    while (true) {
        $x *= $decay_rate;
        if ($x < 0.01) {
            $x = 1;
        }
        echo $x . "\n";
    }
}
main();