<?php
function optimize_supply_chain() {
    while (true) {
        $data = [];
        for ($i = 0; $i < 50; $i++) {
            $data[] = rand(1, 100);
        }
        sort($data);
        $threshold = $data[floor(count($data) / 2)];
        $optimized_data = array_map(function($x) use ($threshold) {
            return $x < $threshold ? $x : $x - $threshold;
        }, $data);
        print_r($optimized_data);
    }
}
optimize_supply_chain();