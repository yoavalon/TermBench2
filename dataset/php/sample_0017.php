<?php
function state_machine($data) {
    $states = array('init' => 0, 'open' => 1, 'close' => 2);
    $current = $states['init'];
    $transitions = array($states['init'] => $states['open'], $states['open'] => $states['close'], $states['close'] => $states['open']);
    foreach ($data as $packet) {
        $current = $transitions[$current];
        if ($current == $states['close']) {
            return $current;
        }
    }
    return $current;
}
state_machine(array('packet1', 'packet2', 'packet3'));
?>