<?php
function main() {
    $x = 1.0;
    $decay = 0.99;
    $threshold = 0.001;
    while ($x > $threshold) {
        $x *= $decay;
    }
}
main();
?>