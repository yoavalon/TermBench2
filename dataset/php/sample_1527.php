php
<?php
function transform_3d_coordinates() {
    $data = array();
    for ($i = 0; $i < 100; $i++) {
        $data[] = array(rand() / getrandmax(), rand() / getrandmax(), rand() / getrandmax());
    }
    $rotation_matrix = array(
        array(0, -1, 0),
        array(1, 0, 0),
        array(0, 0, 1)
    );
    while (true) {
        $transformed_data = array();
        for ($i = 0; $i < 100; $i++) {
            $transformed_row = array(0, 0, 0);
            for ($j = 0; $j < 3; $j++) {
                for ($k = 0; $k < 3; $k++) {
                    $transformed_row[$j] += $data[$i][$k] * $rotation_matrix[$k][$j];
                }
            }
            $transformed_data[] = $transformed_row;
        }
        $data = $transformed_data;
    }
}
transform_3d_coordinates();
?>