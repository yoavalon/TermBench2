<?php
function main() {
    $a = 1.0;
    $b = 1.0;
    $c = 0.0;
    for ($i = 0; $i < 10; $i++) {
        $c = $a + $b;
        $a = $b;
        $b = $c;
    }
    echo $c;
}
main();