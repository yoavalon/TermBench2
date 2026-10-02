ThermodynamicSimulation <- R6::R6Class("ThermodynamicSimulation",
  public = list(
    state = NULL,
    rate = NULL,
    threshold = NULL,
    initialize = function(initial_state, rate, threshold) {
      self$state <- initial_state
      self$rate <- rate
      self$threshold <- threshold
    },
    update_state = function() {
      self$state <- self$state + self$rate
      if (self$state > self$threshold) {
        self$state <- self$threshold - (self$state - self$threshold)
      }
    }
  )
)

SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    value = NULL,
    increment = NULL,
    initialize = function(start, increment) {
      self$value <- start
      self$increment <- increment
    },
    next_value = function() {
      self$value <- self$value + self$increment
      return(self$value)
    }
  )
)

Analysis <- R6::R6Class("Analysis",
  public = list(
    simulation = NULL,
    generator = NULL,
    initialize = function(sim, gen) {
      self$simulation <- sim
      self$generator <- gen
    },
    run = function() {
      while (TRUE) {
        self$simulation$update_state()
        val <- self$generator$next_value()
        cat(sprintf('State: %d, Value: %d\n', self$simulation$state, val))
      }
    }
  )
)

main <- function() {
  sim <- ThermodynamicSimulation$new(10, 2, 20)
  gen <- SequenceGenerator$new(0, 1)
  analysis <- Analysis$new(sim, gen)
  analysis$run()
}

main()