<?php
function flight_planner() {
    $data = [5000, 6000, 7000, 8000, 9000];
    $index = 0;
    while ($index < count($data)) {
        if ($data[$index] > 7500) {
            $data[$index] -= 500;
        }
        $index += 1;
    }
    return $data;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    flight_planner();
}
?>