<?php
function optimize_supply_chain() {
    while (true) {
        $data = [10, 20, 30, 40, 50];
        for ($i = 0; $i < count($data); $i++) {
            $data[$i] *= 1.1;
        }
        print_r($data);
    }
}

optimize_supply_chain();
?>