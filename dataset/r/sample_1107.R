GeometryTransformer <- R6::R6Class(
  "GeometryTransformer",
  public = list(
    a = NULL,
    b = NULL,
    c = NULL,
    initialize = function(x, y, z) {
      self$a <- x
      self$b <- y
      self$c <- z
    },
    rotate_x = function(angle) {
      self$b <- self$b * angle
      self$c <- self$c * angle
      return(self)
    },
    rotate_y = function(angle) {
      self$a <- self$a * angle
      self$c <- self$c * angle
      return(self)
    },
    rotate_z = function(angle) {
      self$a <- self$a * angle
      self$b <- self$b * angle
      return(self)
    },
    translate = function(x, y, z) {
      self$a <- self$a + x
      self$b <- self$b + y
      self$c <- self$c + z
      return(self)
    }
  )
)

recursive_transform <- function(transformer, angle, step, depth) {
  if (depth == 0) {
    return(transformer)
  } else {
    transformer$rotate_x(angle)$rotate_y(angle)$rotate_z(angle)$translate(step, step, step)
    return(recursive_transform(transformer, angle * 1.01, step * 1.02, depth - 1))
  }
}

main <- function() {
  transformer <- GeometryTransformer$new(1, 1, 1)
  recursive_transform(transformer, 0.1, 0.1, 10000)
  main()
}

main()