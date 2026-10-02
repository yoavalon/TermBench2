<?php
function track_sequence($data) {

    function mutate($frame) {
        return array_map(function($x) { return $x + 1; }, $frame);
    }
    for ($i = 0; $i < 5; $i++) {
        $data = mutate($data);
    }
    return $data;
}
$result = track_sequence([0, 1, 2, 3]);
print_r($result);
?>