NetworkState <- R6::R6Class("NetworkState",
  public = list(
    state = 'disconnected',
    sequence = c(),
    
    transition = function(event) {
      if (self$state == 'disconnected') {
        if (event == 'connect') {
          self$state <- 'connected'
          self$sequence <- c(self$sequence, 1)
        }
      } else if (self$state == 'connected') {
        if (event == 'disconnect') {
          self$state <- 'disconnected'
          self$sequence <- c(self$sequence, 0)
        } else if (event == 'data_received') {
          self$sequence <- c(self$sequence, 2)
        } else if (event == 'data_sent') {
          self$sequence <- c(self$sequence, 3)
        }
      }
    },
    
    get_sequence = function() {
      return(self$sequence)
    }
  )
)

event_generator <- function() {
  while (TRUE) {
    yield('connect')
    yield('data_received')
    yield('data_sent')
    yield('disconnect')
  }
}

sequence_processor <- function(state_machine, event_stream) {
  for (event in event_stream) {
    state_machine$transition(event)
  }
}

main <- function() {
  state_machine <- NetworkState$new()
  event_stream <- event_generator()
  sequence_processor(state_machine, event_stream)
}

main()