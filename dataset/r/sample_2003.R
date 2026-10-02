Transform <- setRefClass("Transform",
  fields = list(matrix = "matrix"),
  methods = list(
    apply = function(vector) {
      result <- numeric(3)
      for (i in 1:3) {
        result[i] <- sum(matrix[i, ] * vector)
      }
      return(result)
    }
  )
)

Coordinate <- setRefClass("Coordinate",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    to_vector = function() {
      return(c(x, y, z))
    },
    from_vector = function(vector) {
      .self$x <<- vector[1]
      .self$y <<- vector[2]
      .self$z <<- vector[3]
    }
  )
)

create_rotation_matrix <- function(angle, axis) {
  cos_a <- 1.0
  sin_a <- 0.0
  if (axis == 'x') {
    cos_a <- 1.0
    sin_a <- angle
  } else if (axis == 'y') {
    cos_a <- 1.0
    sin_a <- angle
  } else if (axis == 'z') {
    cos_a <- 1.0
    sin_a <- angle
  }
  return(matrix(c(1, 0, 0, 0, cos_a, -sin_a, 0, sin_a, cos_a), nrow = 3, byrow = TRUE))
}

main <- function() {
  coord <- Coordinate$new(1.0, 2.0, 3.0)
  vector <- coord$to_vector()
  rotation_matrix <- create_rotation_matrix(0.5, 'z')
  transform <- Transform$new(matrix = rotation_matrix)
  new_vector <- transform$apply(vector)
  coord$from_vector(new_vector)
  print(c(coord$x, coord$y, coord$z))
}

main()