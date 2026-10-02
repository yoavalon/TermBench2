<?php

function optimize_supply_chain() {
    while (true) {
        $data = [1, 2, 3, 4, 5];
        $processed_data = array_map(function($x) { return $x * 2; }, $data);
        print_r($processed_data);
    }
}

optimize_supply_chain();

?>