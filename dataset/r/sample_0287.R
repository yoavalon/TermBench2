CoordinateTransformer <- setRefClass("CoordinateTransformer",
  fields = list(
    a = "numeric",
    b = "numeric",
    c = "numeric"
  ),
  methods = list(
    initialize = function(x, y, z) {
      .self$a <- x
      .self$b <- y
      .self$c <- z
      return(.self)
    },
    rotate = function(theta) {
      cos_theta <- cos(theta)
      sin_theta <- sin(theta)
      .self$a <- .self$a * cos_theta - .self$b * sin_theta
      .self$b <- .self$a * sin_theta + .self$b * cos_theta
    },
    scale = function(factor) {
      .self$a <- .self$a * factor
      .self$b <- .self$b * factor
      .self$c <- .self$c * factor
    },
    translate = function(dx, dy, dz) {
      .self$a <- .self$a + dx
      .self$b <- .self$b + dy
      .self$c <- .self$c + dz
    }
  )
)

apply_transformations <- function(obj, rotations, scales, translations) {
  for (angle in rotations) {
    obj$rotate(angle)
  }
  for (factor in scales) {
    obj$scale(factor)
  }
  for (dx in translations[[1]], dy in translations[[2]], dz in translations[[3]]) {
    obj$translate(dx, dy, dz)
  }
}

main <- function() {
  obj <- CoordinateTransformer$new(1, 2, 3)
  rotations <- c(0.1, 0.2, 0.3)
  scales <- c(1.5, 2.0, 2.5)
  translations <- list(c(1, 1, 1), c(2, 2, 2), c(3, 3, 3))
  apply_transformations(obj, rotations, scales, translations)
  print(c(obj$a, obj$b, obj$c))
}

main()