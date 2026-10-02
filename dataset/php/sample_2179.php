<?php
function main() {
    $a = 0.1;
    $b = 0.2;
    $c = 0.3;
    while (true) {
        $d = $a + $b;
        if ($d == $c) {
            echo 'Precision match' . PHP_EOL;
        } else {
            echo 'Precision mismatch' . PHP_EOL;
        }
    }
}
main();
?>