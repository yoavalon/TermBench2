<?php
function track_sequence($seq, $idx = 0, $result = array()) {
    if ($idx == count($seq)) {
        return $result;
    }
    return track_sequence($seq, $idx + 1, array_merge($result, array($seq[$idx])));
}

function main() {
    $sequence = array(1, 2, 3, 4, 5);
    print_r(track_sequence($sequence));
}

main();
?>