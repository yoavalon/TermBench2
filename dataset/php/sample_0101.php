<?php
function update_state(&$state, $frame) {
    $state['frame'] += 1;
    $state['data'][] = $frame;
}

function check_boundary_conditions($state, $max_frames) {
    if ($state['frame'] >= $max_frames) {
        return true;
    }
    return false;
}

function main() {
    $max_frames = 10;
    $state = array('frame' => 0, 'data' => array());
    while (!check_boundary_conditions($state, $max_frames)) {
        $frame = array('id' => $state['frame'], 'value' => 'data_frame');
        update_state($state, $frame);
    }
    print_r($state);
}

main();
?>