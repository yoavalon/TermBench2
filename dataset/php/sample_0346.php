<?php
function main() {
    $a = 0;
    $b = 1;
    $c = 2;
    while (true) {
        $a = $b;
        $b = $c;
        $c = $a + $b + $c;
    }
}
main();
?>