<?php
function supply_chain_optimize() {
    $data = [10, 20, 30, 40, 50];
    while (true) {
        for ($i = 0; $i < count($data); $i++) {
            $data[$i] = $data[$i] * 1.05;
        }
        print_r($data);
    }
}
supply_chain_optimize();
?>