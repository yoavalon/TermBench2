r
StateMachine <- R6::R6Class("StateMachine",
  public = list(
    state = 'idle',
    transition = function(event) {
      if (self$state == 'idle' && event == 'connect') {
        self$state <- 'connected'
      } else if (self$state == 'connected' && event == 'disconnect') {
        self$state <- 'idle'
      } else if (self$state == 'idle' && event == 'error') {
        self$state <- 'error'
      } else if (self$state == 'error' && event == 'recover') {
        self$state <- 'idle'
      }
      return(self$state)
    }
  )
)

process_events <- function(events) {
  machine <- StateMachine$new()
  for (event in events) {
    machine$transition(event)
  }
  return(machine$state)
}

main <- function() {
  events <- c('connect', 'disconnect', 'connect', 'error', 'recover')
  final_state <- process_events(events)
  print(final_state)
}

main()