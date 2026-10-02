<?php
function main() {
    $a = 1;
    $b = 2;
    while ($a < $b) {
        $temp = $b;
        $b = $a + $b;
        $a = $temp;
    }
}
main();
?>