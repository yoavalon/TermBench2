php
<?php
function check_connection_state($conn) {
    $states = array(0, 1, 2, 3, 4);
    $transitions = array(0 => 1, 1 => 2, 2 => 3, 3 => 4, 4 => 0);
    $current = 0;
    for ($i = 0; $i < 10; $i++) {
        $current = $transitions[$current];
        if ($current == $conn) {
            return true;
        }
    }
    return false;
}
if (__FILE__ == __DIR__ . '/main.php') {
    $result = check_connection_state(3);
    echo $result;
}
?>