SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    start = NULL,
    stop = NULL,
    step = NULL,
    current = NULL,
    initialize = function(start, stop, step) {
      self$start <- start
      self$stop <- stop
      self$step <- step
      self$current <- start
    },
    generate = function() {
      while (self$current < self$stop) {
        yield(self$current)
        self$current <- self$current + self$step
      }
    }
  )
)

ThermodynamicSimulator <- R6::R6Class("ThermodynamicSimulator",
  public = list(
    sequence = NULL,
    temperature = 300,
    initialize = function(sequence) {
      self$sequence <- sequence
    },
    simulate = function() {
      for (value in self$sequence$generate()) {
        self$temperature <- self$temperature + value * 0.1
        yield(self$temperature)
      }
    }
  )
)

DataCollector <- R6::R6Class("DataCollector",
  public = list(
    simulator = NULL,
    data = list(),
    initialize = function(simulator) {
      self$simulator <- simulator
    },
    collect = function() {
      for (temp in self$simulator$simulate()) {
        self$data[[length(self$data) + 1]] <- temp
      }
      return(self$data)
    }
  )
)

main <- function() {
  start <- 0
  stop <- 100
  step <- 5
  sequence <- SequenceGenerator$new(start, stop, step)
  simulator <- ThermodynamicSimulator$new(sequence)
  collector <- DataCollector$new(simulator)
  result <- collector$collect()
  print(result)
}

main()