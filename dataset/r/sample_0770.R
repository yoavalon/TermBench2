Vector <- setRefClass(
  "Vector",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    scale = function(factor) {
      Vector$new(self$x * factor, self$y * factor, self$z * factor)
    },
    add = function(other) {
      Vector$new(self$x + other$x, self$y + other$y, self$z + other$z)
    }
  )
)

transform_recursive <- function(vec, scale, steps) {
  if (steps == 0) {
    vec
  } else {
    scaled_vec <- vec$scale(scale)
    transform_recursive(scaled_vec$add(vec), scale, steps - 1)
  }
}

main <- function() {
  v <- Vector$new(1, 2, 3)
  result <- transform_recursive(v, 2, 3)
  cat(sprintf('Final Vector: (%s, %s, %s)\n', result$x, result$y, result$z))
}

main()