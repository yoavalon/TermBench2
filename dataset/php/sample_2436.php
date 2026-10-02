<?php
function main() {
    $n = 10;
    $a = 0;
    $b = 1;
    $sequence = array($a, $b);
    for ($i = 2; $i < $n; $i++) {
        $temp = $b;
        $b = $a + $b;
        $a = $temp;
        $sequence[] = $b;
    }
    print_r($sequence);
}
main();
?>