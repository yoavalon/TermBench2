<?php
function optimize_supply_chain() {
    $data = [10, 20, 30, 40, 50];
    while (true) {
        foreach ($data as $item) {
            echo $item * 2 . "\n";
        }
        $data = array_map(function($x) { return $x + 1; }, $data);
    }
}
optimize_supply_chain();
?>