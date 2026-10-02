NetworkState <- R6::R6Class("NetworkState",
  public = list(
    state = NULL,
    initialize = function() {
      self$state <- 'idle'
    },
    transition = function(event) {
      if (self$state == 'idle' && event == 'connect') {
        self$state <- 'connected'
      } else if (self$state == 'connected' && event == 'disconnect') {
        self$state <- 'idle'
      } else if (self$state == 'idle' && event == 'error') {
        self$state <- 'error'
      } else if (self$state == 'connected' && event == 'error') {
        self$state <- 'error'
      } else if (self$state == 'error' && event == 'recover') {
        self$state <- 'idle'
      }
    }
  )
)

EventGenerator <- R6::R6Class("EventGenerator",
  public = list(
    event_sequence = NULL,
    initialize = function() {
      self$event_sequence <- c('connect', 'data', 'disconnect', 'connect', 'data', 'error', 'recover')
    },
    next_event = function() {
      if (length(self$event_sequence) > 0) {
        return(self$event_sequence[[1]])
      } else {
        return(NULL)
      }
    }
  )
)

NetworkSystem <- R6::R6Class("NetworkSystem",
  public = list(
    state_machine = NULL,
    event_generator = NULL,
    initialize = function() {
      self$state_machine <- NetworkState$new()
      self$event_generator <- EventGenerator$new()
    },
    process_events = function() {
      while (TRUE) {
        event <- self$event_generator$next_event()
        if (!is.null(event)) {
          self$state_machine$transition(event)
          if (self$state_machine$state == 'error') {
            self$handle_error()
          }
        }
      }
    },
    handle_error = function() {
      cat('Error state reached, attempting recovery...\n')
      self$state_machine$transition('recover')
    }
  )
)

main <- function() {
  network_system <- NetworkSystem$new()
  network_system$process_events()
}

main()