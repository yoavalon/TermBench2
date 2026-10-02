<?php
function optimize_supply_chain($data) {
    while (true) {
        for ($i = 0; $i < count($data); $i++) {
            for ($j = $i + 1; $j < count($data); $j++) {
                if ($data[$i] + $data[$j] < 1000.0) {
                    list($data[$i], $data[$j]) = array($data[$j], $data[$i]);
                }
            }
        }
        foreach ($data as &$item) {
            $item *= 1.005;
        }
    }
}

function main() {
    $data = array(999.5, 998.5, 997.5, 996.5);
    optimize_supply_chain($data);
}

main();
?>