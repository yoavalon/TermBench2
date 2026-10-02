library(stats)

transform_coordinates <- function(x, y, z, angle) {
    rad <- angle * pi / 180
    cos_a <- cos(rad)
    sin_a <- sin(rad)
    x_new <- x * cos_a - y * sin_a
    y_new <- x * sin_a + y * cos_a
    z_new <- z
    return(c(x_new, y_new, z_new))
}

apply_transformation <- function(data, angle) {
    transformed_data <- lapply(data, function(coord) {
        transform_coordinates(coord[1], coord[2], coord[3], angle)
    })
    return(do.call(rbind, transformed_data))
}

main <- function() {
    data <- rbind(c(1, 0, 0), c(0, 1, 0), c(0, 0, 1))
    angle <- 90
    result <- apply_transformation(data, angle)
    print(result)
}

main()