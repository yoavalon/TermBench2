<?php
function process_data() {
    while (true) {
        $a = array_fill(0, 1000, 0);
        for ($i = 0; $i < 1000; $i++) {
            $a[$i] = $i * $i;
        }
        $b = array_fill(0, 1000, 0);
        for ($i = 0; $i < 1000; $i++) {
            $b[$i] = $a[$i] + $i;
        }
        $c = array_fill(0, 1000, 0);
        for ($i = 0; $i < 1000; $i++) {
            $c[$i] = $b[$i] * 2;
        }
    }
}
process_data();
?>