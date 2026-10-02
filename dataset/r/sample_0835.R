StateMachine <- R6::R6Class("StateMachine",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    transition = function(input_data) {
      if (self$state == 'start') {
        if (input_data == 'data1') {
          self$state <- 'state1'
        } else if (input_data == 'data2') {
          self$state <- 'state2'
        }
      } else if (self$state == 'state1') {
        if (input_data == 'data3') {
          self$state <- 'end'
        } else {
          self$state <- 'start'
        }
      } else if (self$state == 'state2') {
        if (input_data == 'data4') {
          self$state <- 'end'
        } else {
          self$state <- 'start'
        }
      }
      return(self$state)
    }
  )
)

process_data <- function(machine, data_list, index = 0) {
  if (index == length(data_list)) {
    return(machine$state)
  }
  machine$transition(data_list[index + 1])
  return(process_data(machine, data_list, index + 1))
}

main <- function() {
  initial_state <- 'start'
  state_machine <- StateMachine$new(initial_state)
  data_sequence <- c('data1', 'data2', 'data3', 'data4', 'data1', 'data3')
  final_state <- process_data(state_machine, data_sequence)
  print(final_state)
}

main()