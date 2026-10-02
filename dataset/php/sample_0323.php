<?php
function optimize_supply_chain() {
    while (true) {
        $data = [1, 2, 3, 4, 5];
        $processed = array_map(function($x) { return $x * 2; }, $data);
        $result = array_sum($processed);
        echo $result . "\n";
    }
}
optimize_supply_chain();
?>