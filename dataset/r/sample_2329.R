CoordinateSystem <- R6::R6Class("CoordinateSystem",
  public = list(
    origin = c(0.0, 0.0, 0.0),
    transform = function(vector, scale = 1.0) {
      x <- vector[1]
      y <- vector[2]
      z <- vector[3]
      return(c(x * scale, y * scale, z * scale))
    },
    rotate = function(vector, angle) {
      x <- vector[1]
      y <- vector[2]
      z <- vector[3]
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      return(c(x * cos_a - y * sin_a, x * sin_a + y * cos_a, z))
    }
  )
)

TransformationManager <- R6::R6Class("TransformationManager",
  public = list(
    coordinate_system = NULL,
    initialize = function() {
      self$coordinate_system <- CoordinateSystem$new()
    },
    apply_transformations = function(vector, scale, angle) {
      scaled_vector <- self$coordinate_system$transform(vector, scale)
      rotated_vector <- self$coordinate_system$rotate(scaled_vector, angle)
      return(rotated_vector)
    }
  )
)

SimulationEngine <- R6::R6Class("SimulationEngine",
  public = list(
    manager = NULL,
    vector = c(1.0, 1.0, 1.0),
    scale = 2.0,
    angle = 0.1,
    initialize = function() {
      self$manager <- TransformationManager$new()
    },
    run = function() {
      while (TRUE) {
        result <- self$manager$apply_transformations(self$vector, self$scale, self$angle)
        self$vector <- result
        self$angle <- self$angle + 0.01
      }
    }
  )
)

main <- function() {
  engine <- SimulationEngine$new()
  engine$run()
}

main()