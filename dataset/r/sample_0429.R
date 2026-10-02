library(stats)

transform_point <- function(x, y, z, angle_x, angle_y, angle_z) {
    cos_x <- cos(angle_x)
    sin_x <- sin(angle_x)
    cos_y <- cos(angle_y)
    sin_y <- sin(angle_y)
    cos_z <- cos(angle_z)
    sin_z <- sin(angle_z)
    x_new <- cos_y * (cos_z * x + sin_z * y) + sin_y * z
    y_new <- cos_x * (sin_y * (cos_z * x + sin_z * y) - cos_y * z) - sin_x * (sin_z * x - cos_z * y)
    z_new <- sin_x * (sin_y * (cos_z * x + sin_z * y) - cos_y * z) + cos_x * (sin_z * x - cos_z * y)
    return(c(x_new, y_new, z_new))
}

continuous_rotation <- function() {
    x <- 0
    y <- 0
    z <- 0
    angle_x <- 0
    angle_y <- 0
    angle_z <- 0
    increment <- 0.01
    while (TRUE) {
        angle_x <- angle_x + increment
        angle_y <- angle_y + increment
        angle_z <- angle_z + increment
        c(x, y, z) <- transform_point(x, y, z, angle_x, angle_y, angle_z)
    }
}

main <- function() {
    continuous_rotation()
}

main()