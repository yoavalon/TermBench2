Transformation <- R6::R6Class("Transformation",
  public = list(
    a = NULL,
    b = NULL,
    c = NULL,
    initialize = function(a, b, c) {
      self$a <- a
      self$b <- b
      self$c <- c
    },
    apply = function(x, y, z) {
      x_new <- self$a * x + self$b * y + self$c * z
      y_new <- self$b * x - self$a * y + self$c * z
      z_new <- self$c * x + self$c * y - self$a * z
      return(c(x_new, y_new, z_new))
    }
  )
)

Mutator <- R6::R6Class("Mutator",
  public = list(
    transformations = NULL,
    initialize = function(transformations) {
      self$transformations <- transformations
    },
    mutate = function(point) {
      x <- point[1]
      y <- point[2]
      z <- point[3]
      for (transformation in self$transformations) {
        result <- transformation$apply(x, y, z)
        x <- result[1]
        y <- result[2]
        z <- result[3]
      }
      return(c(x, y, z))
    }
  )
)

Terminator <- R6::R6Class("Terminator",
  public = list(
    mutator = NULL,
    threshold = NULL,
    initialize = function(mutator, threshold) {
      self$mutator <- mutator
      self$threshold <- threshold
    },
    terminate = function(point) {
      for (i in 1:10) {
        result <- self$mutator$mutate(point)
        x <- result[1]
        y <- result[2]
        z <- result[3]
        if (abs(x) < self$threshold && abs(y) < self$threshold && abs(z) < self$threshold) {
          return(TRUE)
        }
      }
      return(FALSE)
    }
  )
)

main <- function() {
  t1 <- Transformation$new(1, 0, 0)
  t2 <- Transformation$new(0, 1, 0)
  t3 <- Transformation$new(0, 0, 1)
  transformations <- list(t1, t2, t3)
  mutator <- Mutator$new(transformations)
  terminator <- Terminator$new(mutator, 0.01)
  point <- c(1.0, 1.0, 1.0)
  result <- terminator$terminate(point)
  print(result)
}

main()