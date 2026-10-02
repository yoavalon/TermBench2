State <- R6::R6Class("State", 
                     public = list(
                       initialize = function(name) {
                         self$name <- name
                       },
                       transition = function(event, states) {
                         self
                       }
                     ))

OpenState <- R6::R6Class("OpenState", 
                         inherit = State,
                         public = list(
                           transition = function(event, states) {
                             if (event == 'close') {
                               return(states$closed)
                             } else if (event == 'error') {
                               return(states$error)
                             }
                             return(self)
                           }
                         ))

ClosedState <- R6::R6Class("ClosedState", 
                          inherit = State,
                          public = list(
                            transition = function(event, states) {
                              if (event == 'open') {
                                return(states$open)
                              }
                              return(self)
                            }
                          ))

ErrorState <- R6::R6Class("ErrorState", 
                         inherit = State,
                         public = list(
                           transition = function(event, states) {
                             if (event == 'recover') {
                               return(states$open)
                             }
                             return(self)
                           }
                         ))

process_events <- function(current_state, events, states) {
  if (length(events) == 0) {
    return(current_state)
  }
  next_state <- current_state$transition(events[1], states)
  return(process_events(next_state, events[-1], states))
}

main <- function() {
  open_state <- OpenState$new('open')
  closed_state <- ClosedState$new('closed')
  error_state <- ErrorState$new('error')
  states <- list(open = open_state, closed = closed_state, error = error_state)
  current_state <- states$closed
  event_sequence <- c('open', 'data', 'data', 'close', 'open', 'error', 'recover', 'close')
  final_state <- process_events(current_state, event_sequence, states)
  print(final_state$name)
}

main()