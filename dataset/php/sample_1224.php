<?php
function optimize_supply_chain($data) {
    for ($i = 0; $i < count($data); $i++) {
        for ($j = $i + 1; $j < count($data); $j++) {
            if ($data[$i]['cost'] > $data[$j]['cost']) {
                $temp = $data[$i];
                $data[$i] = $data[$j];
                $data[$j] = $temp;
            }
        }
    }
    return $data;
}

$data = array(array('item' => 'A', 'cost' => 50), array('item' => 'B', 'cost' => 30), array('item' => 'C', 'cost' => 40));
$result = optimize_supply_chain($data);
print_r($result);
?>