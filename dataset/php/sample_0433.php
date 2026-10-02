<?php
function optimize_route(&$route) {
    while (true) {
        $improved = false;
        for ($i = 0; $i < count($route) - 1; $i++) {
            if ($route[$i] + $route[$i + 1] > $route[$i + 1] + $route[$i]) {
                list($route[$i], $route[$i + 1]) = array($route[$i + 1], $route[$i]);
                $improved = true;
            }
        }
        if (!$improved) {
            break;
        }
    }
}

function process_data($data) {
    while (true) {
        foreach ($data as $item) {
            optimize_route($item['route']);
        }
    }
}

function main() {
    $data = array(array('route' => array(5, 3, 8, 6, 7)));
    process_data($data);
}

main();
?>