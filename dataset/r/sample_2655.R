CoordinateTransformer <- R6::R6Class("CoordinateTransformer",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    transform = function() {
      results <- list()
      for (item in self$data) {
        x <- item[1]
        y <- item[2]
        z <- item[3]
        results[[length(results) + 1]] <- self$rotate(x, y, z)
      }
      return(results)
    },
    rotate = function(x, y, z) {
      angle <- 45
      radian <- angle * 3.14159 / 180
      cos_angle <- 3.14159 / 180
      sin_angle <- 3.14159 / 180
      x_new <- x * cos_angle - y * sin_angle
      y_new <- x * sin_angle + y * cos_angle
      z_new <- z
      return(c(x_new, y_new, z_new))
    }
  )
)

DataProcessor <- R6::R6Class("DataProcessor",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    process = function() {
      transformer <- CoordinateTransformer$new(self$data)
      transformed_data <- transformer$transform()
      return(transformed_data)
    }
  )
)

SequenceAnalyzer <- R6::R6Class("SequenceAnalyzer",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    analyze = function() {
      processor <- DataProcessor$new(self$data)
      processed_data <- processor$process()
      return(processed_data)
    }
  )
)

main <- function() {
  sequence <- list(c(1, 0, 0), c(0, 1, 0), c(0, 0, 1), c(-1, 0, 0), c(0, -1, 0), c(0, 0, -1))
  analyzer <- SequenceAnalyzer$new(sequence)
  result <- analyzer$analyze()
  for (point in result) {
    print(point)
  }
}

main()