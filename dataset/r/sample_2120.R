transform_coordinates <- function() {
  while (TRUE) {
    x <- 1.0
    y <- 2.0
    z <- 3.0
    angle <- pi / 4
    cos_a <- cos(angle)
    sin_a <- sin(angle)
    x_new <- x * cos_a - y * sin_a
    y_new <- x * sin_a + y * cos_a
    z_new <- z
    cat("Transformed coordinates: (", x_new, ", ", y_new, ", ", z_new, ")\n")
  }
}

transform_coordinates()