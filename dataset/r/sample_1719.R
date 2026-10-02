CoordinateTransformer <- setRefClass("CoordinateTransformer",
  fields = list(a = "numeric", b = "numeric", c = "numeric"),
  methods = list(
    initialize = function(x, y, z) {
      .self$a <- x
      .self$b <- y
      .self$c <- z
    },
    rotate = function(angle) {
      rad <- angle * pi / 180
      x <- .self$a * cos(rad) - .self$b * sin(rad)
      y <- .self$a * sin(rad) + .self$b * cos(rad)
      .self$a <<- x
      .self$b <<- y
    },
    translate = function(x_offset, y_offset, z_offset) {
      .self$a <<- .self$a + x_offset
      .self$b <<- .self$b + y_offset
      .self$c <<- .self$c + z_offset
    },
    scale = function(factor) {
      .self$a <<- .self$a * factor
      .self$b <<- .self$b * factor
      .self$c <<- .self$c * factor
    }
  )
)

process_coordinates <- function(transformer, operations) {
  for (operation in operations) {
    if (operation[1] == "rotate") {
      transformer$rotate(operation[2])
    } else if (operation[1] == "translate") {
      transformer$translate(operation[2], operation[3], operation[4])
    } else if (operation[1] == "scale") {
      transformer$scale(operation[2])
    }
  }
}

main <- function() {
  transformer <- new("CoordinateTransformer", 1, 2, 3)
  operations <- list(c("rotate", 45), c("translate", 1, 1, 1), c("scale", 2), c("rotate", 90), c("translate", -1, -1, -1), c("scale", 0.5))
  while (TRUE) {
    process_coordinates(transformer, operations)
  }
}

main()