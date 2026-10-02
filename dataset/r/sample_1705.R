r
StateSimulator <- R6::R6Class(
  "StateSimulator",
  public = list(
    state = NULL,
    initialize = function(initial_state) {
      self$state <- initial_state
    },
    update_state = function() {
      new_state <- self$state + 1
      if (new_state > 100) {
        new_state <- 0
      }
      self$state <- new_state
    },
    get_state = function() {
      return(self$state)
    }
  )
)

DataMutator <- R6::R6Class(
  "DataMutator",
  public = list(
    simulator = NULL,
    initialize = function(simulator) {
      self$simulator <- simulator
    },
    mutate = function() {
      current_state <- self$simulator$get_state()
      if (current_state %% 2 == 0) {
        self$simulator$state <- current_state * 2
      } else {
        self$simulator$state <- current_state - 10
      }
    }
  )
)

Controller <- R6::R6Class(
  "Controller",
  public = list(
    simulator = NULL,
    mutator = NULL,
    initialize = function() {
      initial_state <- 10
      self$simulator <- StateSimulator$new(initial_state)
      self$mutator <- DataMutator$new(self$simulator)
    },
    run = function() {
      while (TRUE) {
        self$simulator$update_state()
        self$mutator$mutate()
      }
    }
  )
)

main <- function() {
  controller <- Controller$new()
  controller$run()
}

main()