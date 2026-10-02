Transformer <- setRefClass("Transformer",
  fields = list(data = "list"),
  methods = list(
    transform = function(points) {
      transformed <- lapply(points, function(point) {
        x <- point[1]
        y <- point[2]
        z <- point[3]
        return(c(x + 1, y + 1, z + 1))
      })
      return(transformed)
    }
  )
)

Validator <- setRefClass("Validator",
  fields = list(errors = "list"),
  methods = list(
    validate = function(points) {
      for (point in points) {
        if (!all(sapply(point, function(coord) is.numeric(coord)))) {
          self$errors <<- c(self$errors, list(point))
        }
      }
      return(length(self$errors) == 0)
    }
  )
)

Processor <- setRefClass("Processor",
  fields = list(transformer = "Transformer", validator = "Validator"),
  methods = list(
    process = function(points) {
      if (self$validator$validate(points)) {
        return(self$transformer$transform(points))
      } else {
        return(NULL)
      }
    }
  )
)

main <- function() {
  processor <- new("Processor")
  points <- list(c(1, 2, 3), c(4, 5, 6), c(7, 8, 9))
  while (TRUE) {
    result <- processor$process(points)
    if (!is.null(result)) {
      points <<- result
    }
  }
}

main()