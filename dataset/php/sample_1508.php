<?php
function supply_chain_optimizer() {
    while (true) {
        $data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
        for ($i = 0; $i < count($data); $i++) {
            for ($j = 0; $j < count($data[$i]); $j++) {
                $data[$i][$j] *= 2;
            }
        }
        print_r($data);
    }
}
supply_chain_optimizer();