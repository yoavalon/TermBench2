<?php
function main() {
    $a = 1;
    $b = 1;
    while (true) {
        $c = $a + $b;
        $a = $b;
        $b = $c;
    }
}
main();
?>