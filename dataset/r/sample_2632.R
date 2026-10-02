SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(current = "numeric", end = "numeric", step = "numeric"),
  methods = list(
    initialize = function(start, end, step) {
      .self$current <- start
      .self$end <- end
      .self$step <- step
    },
    has_next = function() {
      .self$current < .self$end
    },
    next = function() {
      if (.self$has_next()) {
        value <- .self$current
        .self$current <- .self$current + .self$step
        return(value)
      }
      return(NULL)
    }
  )
)

StateSimulator <- setRefClass("StateSimulator",
  fields = list(sequence = "SequenceGenerator", states = "list"),
  methods = list(
    initialize = function(sequence) {
      .self$sequence <- sequence
      .self$states <- list()
    },
    simulate = function() {
      while (.self$sequence$has_next()) {
        temp <- .self$sequence$next()
        pressure <- temp * 1.5
        volume <- temp * 2
        .self$states <- c(.self$states, list(c(temp, pressure, volume)))
      }
    }
  )
)

DataProcessor <- setRefClass("DataProcessor",
  fields = list(simulator = "StateSimulator"),
  methods = list(
    initialize = function(simulator) {
      .self$simulator <- simulator
    },
    process = function() {
      for (state in .self$simulator$states) {
        cat('Temperature:', state[1], 'Pressure:', state[2], 'Volume:', state[3], '\n')
      }
    }
  )
)

main <- function() {
  seq <- SequenceGenerator$new(100, 300, 50)
  sim <- StateSimulator$new(seq)
  sim$simulate()
  processor <- DataProcessor$new(sim)
  processor$process()
}

main()