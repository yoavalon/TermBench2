SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    value = NULL,
    step = NULL,
    initialize = function(initial_value, step) {
      self$value <- initial_value
      self$step <- step
    },
    next = function() {
      self$value <- self$value + self$step
      return(self$value)
    }
  )
)

ThermodynamicSimulator <- R6::R6Class("ThermodynamicSimulator",
  public = list(
    sequence = NULL,
    temperature = 0.0,
    pressure = 1.0,
    initialize = function(sequence) {
      self$sequence <- sequence
    },
    update_state = function() {
      self$temperature <- self$temperature + self$sequence$next() / 100.0
      self$pressure <- self$pressure + self$sequence$next() / 1000.0
    },
    get_state = function() {
      return(list(self$temperature, self$pressure))
    }
  )
)

DataCollector <- R6::R6Class("DataCollector",
  public = list(
    simulator = NULL,
    data = NULL,
    initialize = function(simulator) {
      self$simulator <- simulator
      self$data <- list()
    },
    collect = function() {
      temp_press <- self$simulator$get_state()
      self$data <- c(self$data, list(temp_press))
    },
    display = function() {
      for (entry in self$data) {
        print(entry)
      }
    }
  )
)

main <- function() {
  seq <- SequenceGenerator$new(1, 1)
  sim <- ThermodynamicSimulator$new(seq)
  collector <- DataCollector$new(sim)
  while (TRUE) {
    sim$update_state()
    collector$collect()
    collector$display()
  }
}

main()