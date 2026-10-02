r
rotate_point <- function(x, y, z, angle, axis) {
  if (axis == 'x') {
    cos_theta <- cos(angle)
    sin_theta <- sin(angle)
    y_new <- cos_theta * y - sin_theta * z
    z_new <- sin_theta * y + cos_theta * z
    return(c(x, y_new, z_new))
  } else if (axis == 'y') {
    cos_theta <- cos(angle)
    sin_theta <- sin(angle)
    x_new <- cos_theta * x + sin_theta * z
    z_new <- -sin_theta * x + cos_theta * z
    return(c(x_new, y, z_new))
  } else if (axis == 'z') {
    cos_theta <- cos(angle)
    sin_theta <- sin(angle)
    x_new <- cos_theta * x - sin_theta * y
    y_new <- sin_theta * x + cos_theta * y
    return(c(x_new, y_new, z))
  }
}

translate_point <- function(x, y, z, dx, dy, dz) {
  return(c(x + dx, y + dy, z + dz))
}

apply_transformations <- function(points, rotations, translations) {
  transformed_points <- list()
  for (point in points) {
    x <- point[1]
    y <- point[2]
    z <- point[3]
    for (rotation in rotations) {
      c(x, y, z) <- rotate_point(x, y, z, rotation[1], rotation[2])
    }
    for (translation in translations) {
      c(x, y, z) <- translate_point(x, y, z, translation[1], translation[2], translation[3])
    }
    transformed_points <- append(transformed_points, list(c(x, y, z)))
  }
  return(transformed_points)
}

main <- function() {
  points <- list(c(1, 0, 0), c(0, 1, 0), c(0, 0, 1))
  rotations <- list(c(pi / 4, 'x'), c(pi / 4, 'y'))
  translations <- list(c(1, 1, 1))
  while (TRUE) {
    points <- apply_transformations(points, rotations, translations)
    print(points)
  }
}

main()