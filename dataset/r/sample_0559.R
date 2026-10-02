library(abind)

Vector3D <- setRefClass("Vector3D",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    initialize = function(x, y, z) {
      .self$x <- x
      .self$y <- y
      .self$z <- z
    },
    add = function(other) {
      return(new(Vector3D, x = .self$x + other$x, y = .self$y + other$y, z = .self$z + other$z))
    },
    mul = function(scalar) {
      return(new(Vector3D, x = .self$x * scalar, y = .self$y * scalar, z = .self$z * scalar))
    },
    magnitude = function() {
      return(sqrt(.self$x^2 + .self$y^2 + .self$z^2))
    },
    normalize = function() {
      mag <- .self$magnitude()
      if (mag > 0) {
        return(new(Vector3D, x = .self$x / mag, y = .self$y / mag, z = .self$z / mag))
      }
      return(new(Vector3D, x = 0, y = 0, z = 0))
    }
  )
)

Transform3D <- setRefClass("Transform3D",
  fields = list(rotation = "numeric", translation = "Vector3D"),
  methods = list(
    initialize = function(rotation, translation) {
      .self$rotation <- rotation
      .self$translation <- translation
    },
    apply = function(vector) {
      rotated <- .self$rotate(vector)
      return(rotated$add(.self$translation))
    },
    rotate = function(vector) {
      cos_theta <- cos(.self$rotation)
      sin_theta <- sin(.self$rotation)
      x <- vector$x * cos_theta - vector$y * sin_theta
      y <- vector$x * sin_theta + vector$y * cos_theta
      z <- vector$z
      return(new(Vector3D, x = x, y = y, z = z))
    }
  )
)

generate_points <- function(count, transform) {
  points <- list()
  for (i in 0:(count-1)) {
    vector <- new(Vector3D, x = i, y = i, z = i)
    transformed <- transform$apply(vector)
    points[[length(points) + 1]] <- transformed
  }
  return(points)
}

main <- function() {
  rotation <- pi / 4
  translation <- new(Vector3D, x = 10, y = 20, z = 30)
  transform <- new(Transform3D, rotation = rotation, translation = translation)
  while (TRUE) {
    points <- generate_points(100, transform)
    for (point in points) {
      print(sprintf("(%f, %f, %f)", point$x, point$y, point$z))
    }
  }
}

main()