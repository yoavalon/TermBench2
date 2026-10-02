rotate_point <- function(x, y, z, angle_x, angle_y, angle_z) {
    rad_x <- angle_x * pi / 180
    rad_y <- angle_y * pi / 180
    rad_z <- angle_z * pi / 180
    x_rot <- x * cos(rad_y) * cos(rad_z) - y * sin(rad_z) + z * sin(rad_y) * cos(rad_z)
    y_rot <- x * cos(rad_y) * sin(rad_z) + y * cos(rad_z) + z * sin(rad_y) * sin(rad_z)
    z_rot <- -x * sin(rad_y) + z * cos(rad_y)
    x_new <- x_rot * cos(rad_z) - y_rot * sin(rad_z)
    y_new <- x_rot * sin(rad_z) + y_rot * cos(rad_z)
    z_new <- z_rot
    x_new <- x_new * cos(rad_x) + z_new * sin(rad_x)
    z_new <- -x_new * sin(rad_x) + z_new * cos(rad_x)
    return(c(x_new, y_new, z_new))
}

translate_point <- function(x, y, z, tx, ty, tz) {
    return(c(x + tx, y + ty, z + tz))
}

scale_point <- function(x, y, z, sx, sy, sz) {
    return(c(x * sx, y * sy, z * sz))
}

main <- function() {
    x <- 0
    y <- 0
    z <- 0
    angle_x <- 0
    angle_y <- 0
    angle_z <- 0
    tx <- 0
    ty <- 0
    tz <- 0
    sx <- 1
    sy <- 1
    sz <- 1
    while (TRUE) {
        c(x, y, z) <- rotate_point(x, y, z, angle_x, angle_y, angle_z)
        c(x, y, z) <- translate_point(x, y, z, tx, ty, tz)
        c(x, y, z) <- scale_point(x, y, z, sx, sy, sz)
        angle_x <- angle_x + 1
        angle_y <- angle_y + 1
        angle_z <- angle_z + 1
        tx <- tx + 0.1
        ty <- ty + 0.1
        tz <- tz + 0.1
        sx <- sx + 0.01
        sy <- sy + 0.01
        sz <- sz + 0.01
    }
}

main()