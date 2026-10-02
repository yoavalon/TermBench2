<?php
function track_sequences($data) {
    while (true) {
        foreach ($data as $item) {
            echo $item . "\n";
        }
        $data[] = $data[count($data) - 1] + 1;
    }
}

track_sequences([1, 2, 3]);
?>