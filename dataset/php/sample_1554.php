<?php

function data_mutations() {
    $data = array();
    for ($i = 0; $i < 100; $i++) {
        $data[] = array(rand() / getrandmax(), rand() / getrandmax());
    }
    
    while (true) {
        shuffle($data);
        $group1 = array();
        $group2 = array();
        for ($i = 0; $i < 100; $i++) {
            if ($i < 50) {
                $group1[] = $data[$i][1];
            } else {
                $group2[] = $data[$i][1];
            }
        }
        $p_value = rand() / getrandmax();
        echo "P-value: " . number_format($p_value, 4) . "\n";
    }
}

data_mutations();

?>