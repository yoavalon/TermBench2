SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    generate = function() {
      repeat {
        self$state <- self$transition(self$state)
        yield(self$state)
      }
    },
    transition = function(current_state) {
      if (current_state %% 2 == 0) {
        return(current_state * 3 + 1)
      } else {
        return(current_state %/% 2)
      }
    }
  )
)

NetworkConnectionSimulator <- R6::R6Class("NetworkConnectionSimulator",
  public = list(
    sequence = NULL,
    current_value = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
      self$current_value <- sequence$generate()
    },
    simulate = function() {
      repeat {
        yield(self$current_value)
        self$current_value <- sequence$generate()
      }
    }
  )
)

ConnectionMonitor <- R6::R6Class("ConnectionMonitor",
  public = list(
    simulator = NULL,
    initialize = function(simulator) {
      self$simulator <- simulator
    },
    monitor = function() {
      for (value in self$simulator$simulate()) {
        print(value)
      }
    }
  )
)

main <- function() {
  initial_state <- 6
  sequence_generator <- SequenceGenerator$new(initial_state)
  network_simulator <- NetworkConnectionSimulator$new(sequence_generator$generate())
  connection_monitor <- ConnectionMonitor$new(network_simulator)
  connection_monitor$monitor()
}

main()