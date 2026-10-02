transform_coords <- function(x, y, z, angle) {
  rad <- angle * pi / 180
  cos_rad <- cos(rad)
  sin_rad <- sin(rad)
  x_new <- x * cos_rad - y * sin_rad
  y_new <- x * sin_rad + y * cos_rad
  z_new <- z
  return(c(x_new, y_new, z_new))
}

apply_transformations <- function(coord_list, angle) {
  transformed_coords <- list()
  for (coord in coord_list) {
    x <- coord[1]
    y <- coord[2]
    z <- coord[3]
    transformed <- transform_coords(x, y, z, angle)
    transformed_coords <- append(transformed_coords, list(transformed))
  }
  return(transformed_coords)
}

main <- function() {
  coords <- list(c(1, 2, 3), c(4, 5, 6), c(7, 8, 9))
  angle <- 30
  while (TRUE) {
    coords <- apply_transformations(coords, angle)
    angle <- angle + 1
  }
}

main()