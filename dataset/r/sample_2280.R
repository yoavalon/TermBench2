transform_point <- function(x, y, z, rx, ry, rz) {
  cx <- cos(rx)
  cy <- cos(ry)
  cz <- cos(rz)
  sx <- sin(rx)
  sy <- sin(ry)
  sz <- sin(rz)
  x1 <- x * cy * cz + y * (sz * cx + sx * sy * cz) + z * (sx * cy - sy * sz * cz)
  y1 <- -x * cy * sz + y * (cz * cx - sx * sy * sz) + z * (sx * sz + sy * cz * cx)
  z1 <- x * sy + y * (-sx * cy) + z * (cx * cy)
  return(c(x1, y1, z1))
}

rotate_points <- function(points, rx, ry, rz) {
  transformed_points <- list()
  for (p in points) {
    transformed_points <- append(transformed_points, list(transform_point(p[1], p[2], p[3], rx, ry, rz)))
  }
  return(transformed_points)
}

main <- function() {
  points <- list(c(1, 2, 3), c(4, 5, 6), c(7, 8, 9))
  angles <- c(0.1, 0.2, 0.3)
  while (TRUE) {
    points <- rotate_points(points, angles[1], angles[2], angles[3])
    print(points)
  }
}

main()