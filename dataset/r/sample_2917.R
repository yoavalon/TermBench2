StateMachine <- R6::R6Class("StateMachine",
  public = list(
    state = NULL,
    initialize = function() {
      self$state <- 0
    },
    transition = function(input_value) {
      if (self$state == 0) {
        if (input_value == 0) {
          self$state <- 1
        } else if (input_value == 1) {
          self$state <- 2
        }
      } else if (self$state == 1) {
        if (input_value == 0) {
          self$state <- 0
        } else if (input_value == 1) {
          self$state <- 3
        }
      } else if (self$state == 2) {
        if (input_value == 0) {
          self$state <- 3
        } else if (input_value == 1) {
          self$state <- 1
        }
      } else if (self$state == 3) {
        if (input_value == 0) {
          self$state <- 2
        } else if (input_value == 1) {
          self$state <- 0
        }
      }
    },
    get_state = function() {
      return(self$state)
    }
  )
)

generate_sequence <- function() {
  sequence <- c()
  current_value <- 0
  repeat {
    sequence <- c(sequence, current_value)
    current_value <- (current_value + 1) %% 2
    yield(sequence)
  }
}

process_sequence <- function(state_machine, sequence_generator) {
  repeat {
    value <- nextElem(sequence_generator)
    state_machine$transition(value)
    yield(state_machine$get_state())
  }
}

main <- function() {
  state_machine <- StateMachine$new()
  sequence_generator <- generate_sequence()
  state_generator <- process_sequence(state_machine, sequence_generator)
  repeat {
    state <- nextElem(state_generator)
    print(state)
  }
}

main()