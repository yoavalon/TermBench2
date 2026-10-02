library(stats)

CoordinateTransformer <- R6::R6Class(
  "CoordinateTransformer",
  public = list(
    angle = NULL,
    cos_theta = NULL,
    sin_theta = NULL,
    
    initialize = function(angle) {
      self$angle <- angle
      self$cos_theta <- cos(angle * pi / 180)
      self$sin_theta <- sin(angle * pi / 180)
    },
    
    transform_point = function(x, y, z) {
      x_prime <- x * self$cos_theta - y * self$sin_theta
      y_prime <- x * self$sin_theta + y * self$cos_theta
      z_prime <- z
      return(c(x_prime, y_prime, z_prime))
    }
  )
)

SequenceGenerator <- R6::R6Class(
  "SequenceGenerator",
  public = list(
    point = NULL,
    transformer = NULL,
    
    initialize = function(initial_point, transformer) {
      self$point <- initial_point
      self$transformer <- transformer
    },
    
    generate_next = function() {
      self$point <- self$transformer$transform_point(self$point[1], self$point[2], self$point[3])
      return(self$point)
    }
  )
)

ContinuousSequencePrinter <- R6::R6Class(
  "ContinuousSequencePrinter",
  public = list(
    sequence_generator = NULL,
    
    initialize = function(sequence_generator) {
      self$sequence_generator <- sequence_generator
    },
    
    print_sequence = function() {
      while (TRUE) {
        next_point <- self$sequence_generator$generate_next()
        print(next_point)
      }
    }
  )
)

main <- function() {
  angle <- 45
  initial_point <- c(1, 0, 0)
  transformer <- CoordinateTransformer$new(angle)
  sequence_generator <- SequenceGenerator$new(initial_point, transformer)
  continuous_printer <- ContinuousSequencePrinter$new(sequence_generator)
  continuous_printer$print_sequence()
}

main()