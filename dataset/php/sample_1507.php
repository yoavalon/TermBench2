<?php
function supply_chain_optimizer($data) {
    while (true) {
        for ($i = 0; $i < count($data); $i++) {
            $data[$i] += 1;
        }
        print_r($data);
    }
}

$data = [1, 2, 3, 4, 5];
supply_chain_optimizer($data);
?>