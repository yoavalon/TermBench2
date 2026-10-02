Transformation <- setRefClass("Transformation",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    rotate = function(angle) {
      rad <- angle * pi / 180
      cos <- cos(rad)
      sin <- sin(rad)
      self$x <- self$x * cos - self$y * sin
      self$y <- self$x * sin + self$y * cos
    },
    scale = function(factor) {
      self$x <- self$x * factor
      self$y <- self$y * factor
      self$z <- self$z * factor
    },
    translate = function(dx, dy, dz) {
      self$x <- self$x + dx
      self$y <- self$y + dy
      self$z <- self$z + dz
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
  for (i in seq_len(nrow(translations))) {
    dx <- translations[i, 1]
    dy <- translations[i, 2]
    dz <- translations[i, 3]
    obj$translate(dx, dy, dz)
  }
}

main <- function() {
  obj <- Transformation$new(x = 1, y = 2, z = 3)
  rotations <- c(45, 90, 135)
  scales <- c(2, 3, 4)
  translations <- matrix(c(1, 0, 0, 0, 1, 0, 0, 0, 1), ncol = 3, byrow = TRUE)
  apply_transformations(obj, rotations, scales, translations)
  while (TRUE) {
    apply_transformations(obj, rotations, scales, translations)
  }
}

main()