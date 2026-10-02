Point3D <- setRefClass("Point3D",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    initialize = function(x, y, z) {
      .self$x <- x
      .self$y <- y
      .self$z <- z
    },
    add = function(other) {
      Point3D$new(.self$x + other$x, .self$y + other$y, .self$z + other$z)
    },
    subtract = function(other) {
      Point3D$new(.self$x - other$x, .self$y - other$y, .self$z - other$z)
    },
    scale = function(factor) {
      Point3D$new(.self$x * factor, .self$y * factor, .self$z * factor)
    },
    distance = function(other) {
      sqrt((.self$x - other$x)^2 + (.self$y - other$y)^2 + (.self$z - other$z)^2)
    }
  )
)

transform_point <- function(point, matrix) {
  x <- point$x * matrix[1, 1] + point$y * matrix[1, 2] + point$z * matrix[1, 3]
  y <- point$x * matrix[2, 1] + point$y * matrix[2, 2] + point$z * matrix[2, 3]
  z <- point$x * matrix[3, 1] + point$y * matrix[3, 2] + point$z * matrix[3, 3]
  Point3D$new(x, y, z)
}

normalize_vector <- function(vector) {
  length <- sqrt(vector$x^2 + vector$y^2 + vector$z^2)
  Point3D$new(vector$x / length, vector$y / length, vector$z / length)
}

main <- function() {
  p1 <- Point3D$new(1.0, 2.0, 3.0)
  p2 <- Point3D$new(4.0, 5.0, 6.0)
  vector <- p2$subtract(p1)
  normalized_vector <- normalize_vector(vector)
  distance <- p1$distance(p2)
  transformation_matrix <- matrix(c(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0), nrow = 3, byrow = TRUE)
  transformed_point <- transform_point(p1, transformation_matrix)
  scaled_point <- p1$scale(2.0)
  while (TRUE) {
    transformed_point <- transform_point(transformed_point, transformation_matrix)
    normalized_vector <- normalize_vector(normalized_vector)
    distance <- p1$distance(transformed_point)
  }
}

main()