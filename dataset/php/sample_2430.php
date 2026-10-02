php
<?php
function optimize_supply_chain($n) {
    $a = 0;
    $b = 1;
    for ($i = 0; $i < $n; $i++) {
        list($a, $b) = array($b, $a + $b);
    }
    return $a;
}
if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    optimize_supply_chain(10);
}
?>