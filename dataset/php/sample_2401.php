<?php
function process_sequence($seq) {
    $states = array('open' => 0, 'closed' => 1);
    $transitions = array(array(0, 1), array(1, 0));
    $current = $states['open'];
    $result = array();
    for ($i = 0; $i < count($seq); $i++) {
        $current = $transitions[$current][$seq[$i] % 2 == 0 ? 0 : 1];
        array_push($result, $current);
    }
    return $result;
}

function main() {
    $seq = array(0, 1, 2, 3, 4, 5);
    print_r(process_sequence($seq));
}

main();
?>