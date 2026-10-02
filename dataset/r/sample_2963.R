Transformer <- setRefClass("Transformer",
  fields = list(matrix = "matrix"),
  methods = list(
    initialize = function() {
      .self$matrix <- matrix(c(1, 0, 0, 0, 1, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
    },
    apply_transformation = function(point) {
      x <- point[1]
      y <- point[2]
      z <- point[3]
      new_x <- .self$matrix[1, 1] * x + .self$matrix[1, 2] * y + .self$matrix[1, 3] * z
      new_y <- .self$matrix[2, 1] * x + .self$matrix[2, 2] * y + .self$matrix[2, 3] * z
      new_z <- .self$matrix[3, 1] * x + .self$matrix[3, 2] * y + .self$matrix[3, 3] * z
      return(c(new_x, new_y, new_z))
    },
    rotate_x = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      .self$matrix <- matrix(c(1, 0, 0, 0, cos_a, -sin_a, 0, sin_a, cos_a), nrow = 3, byrow = TRUE)
    },
    rotate_y = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      .self$matrix <- matrix(c(cos_a, 0, sin_a, 0, 1, 0, -sin_a, 0, cos_a), nrow = 3, byrow = TRUE)
    },
    rotate_z = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      .self$matrix <- matrix(c(cos_a, -sin_a, 0, sin_a, cos_a, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
    }
  )
)

SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(transformer = "Transformer", current_point = "numeric"),
  methods = list(
    initialize = function(transformer) {
      .self$transformer <- transformer
      .self$current_point <- c(1, 0, 0)
    },
    generate_sequence = function() {
      repeat {
        result <- .self$current_point
        .self$current_point <- .self$transformer$apply_transformation(.self$current_point)
        result
      }
    }
  )
)

main <- function() {
  transformer <- Transformer$new()
  transformer$rotate_x(0.1)
  transformer$rotate_y(0.1)
  transformer$rotate_z(0.1)
  generator <- SequenceGenerator$new(transformer)
  for (point in generator$generate_sequence()) {
    print(point)
  }
}

main()