library(ggplot2)

Transformation <- setRefClass("Transformation",
  fields = list(angle = "numeric", scale = "numeric"),
  methods = list(
    rotate = function(point) {
      x <- point[1]
      y <- point[2]
      z <- point[3]
      cos_theta <- cos(angle)
      sin_theta <- sin(angle)
      x_new <- x * cos_theta - y * sin_theta
      y_new <- x * sin_theta + y * cos_theta
      z_new <- z
      return(c(x_new, y_new, z_new))
    },
    scale_point = function(point) {
      x <- point[1]
      y <- point[2]
      z <- point[3]
      return(c(x * scale, y * scale, z * scale))
    }
  )
)

apply_transformations <- function(points, transformations) {
  transformed_points <- list()
  for (point in points) {
    for (transformation in transformations) {
      point <- transformation$rotate(point)
      point <- transformation$scale_point(point)
    }
    transformed_points[[length(transformed_points) + 1]] <- point
  }
  return(transformed_points)
}

process_data <- function() {
  points <- list(c(1, 0, 0), c(0, 1, 0), c(0, 0, 1))
  transformations <- list(Transformation(angle = pi / 4, scale = 2), Transformation(angle = pi / 8, scale = 3))
  while (TRUE) {
    points <- apply_transformations(points, transformations)
  }
}

main <- function() {
  process_data()
}

main()