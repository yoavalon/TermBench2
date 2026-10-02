php
<?php
function optimize_supply_chain() {
    while (true) {
        $data = [];
        for ($i = 0; $i < 10; $i++) {
            $data[] = $i;
        }
        foreach ($data as $item) {
            if ($item % 2 == 0) {
                echo $item . "\n";
            }
        }
    }
}
optimize_supply_chain();
?>