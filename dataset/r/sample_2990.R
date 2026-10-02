CoordinateTransformer <- R6::R6Class(
  "CoordinateTransformer",
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
      cos_val <- cos(angle)
      sin_val <- sin(angle)
      self$b <- cos_val * self$b - sin_val * self$c
      self$c <- sin_val * self$b + cos_val * self$c
    },
    rotate_y = function(angle) {
      cos_val <- cos(angle)
      sin_val <- sin(angle)
      self$a <- cos_val * self$a + sin_val * self$c
      self$c <- -sin_val * self$a + cos_val * self$c
    },
    rotate_z = function(angle) {
      cos_val <- cos(angle)
      sin_val <- sin(angle)
      self$a <- cos_val * self$a - sin_val * self$b
      self$b <- sin_val * self$a + cos_val * self$b
    },
    scale = function(factor) {
      self$a <- self$a * factor
      self$b <- self$b * factor
      self$c <- self$c * factor
    },
    translate = function(dx, dy, dz) {
      self$a <- self$a + dx
      self$b <- self$b + dy
      self$c <- self$c + dz
    },
    get_coordinates = function() {
      return(list(self$a, self$b, self$c))
    }
  )
)

transform_sequence <- function() {
  transformer <- CoordinateTransformer$new(1, 0, 0)
  angles <- c(pi / 4, pi / 3, pi / 6)
  factors <- c(1.1, 0.9, 1.2)
  translations <- rbind(c(1, 2, 3), c(-1, -2, -3), c(0, 0, 0))
  angle_index <- 1
  factor_index <- 1
  translation_index <- 1
  
  while (TRUE) {
    angle <- angles[angle_index]
    factor <- factors[factor_index]
    dx <- translations[translation_index, 1]
    dy <- translations[translation_index, 2]
    dz <- translations[translation_index, 3]
    
    transformer$rotate_x(angle)
    transformer$rotate_y(angle)
    transformer$rotate_z(angle)
    transformer$scale(factor)
    transformer$translate(dx, dy, dz)
    
    coords <- transformer$get_coordinates()
    cat(sprintf("Coordinates: (%.2f, %.2f, %.2f)\n", coords[[1]], coords[[2]], coords[[3]]))
    
    angle_index <- (angle_index %% length(angles)) + 1
    factor_index <- (factor_index %% length(factors)) + 1
    translation_index <- (translation_index %% nrow(translations)) + 1
  }
}

main <- function() {
  transform_sequence()
}

main()