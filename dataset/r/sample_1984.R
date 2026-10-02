r
transform_coordinates <- function(x, y, z, angle) {
    rad <- angle * pi / 180
    cos_a <- cos(rad)
    sin_a <- sin(rad)
    new_x <- x * cos_a - y * sin_a
    new_y <- x * sin_a + y * cos_a
    new_z <- z
    return(c(new_x, new_y, new_z))
}

calculate_distance <- function(x1, y1, z1, x2, y2, z2) {
    return(sqrt((x2 - x1) ^ 2 + (y2 - y1) ^ 2 + (z2 - z1) ^ 2))
}

main <- function() {
    x <- 1.0
    y <- 2.0
    z <- 3.0
    angle <- 30
    coordinates <- transform_coordinates(x, y, z, angle)
    x_t <- coordinates[1]
    y_t <- coordinates[2]
    z_t <- coordinates[3]
    d <- calculate_distance(x, y, z, x_t, y_t, z_t)
    cat('Transformed Coordinates: (', x_t, ', ', y_t, ', ', z_t, ')\n')
    cat('Distance: ', d, '\n')
}

main()