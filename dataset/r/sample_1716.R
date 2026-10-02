NetworkState <- R6::R6Class("NetworkState",
  public = list(
    state = 'DISCONNECTED',
    transition = function(event) {
      if (self$state == 'DISCONNECTED' && event == 'CONNECT') {
        self$state <- 'CONNECTED'
      } else if (self$state == 'CONNECTED' && event == 'DATA_RECEIVED') {
        self$state <- 'DATA_PROCESSING'
      } else if (self$state == 'DATA_PROCESSING' && event == 'DATA_PROCESSED') {
        self$state <- 'CONNECTED'
      } else if (self$state == 'CONNECTED' && event == 'DISCONNECT') {
        self$state <- 'DISCONNECTED'
      }
    }
  )
)

NetworkEventGenerator <- R6::R6Class("NetworkEventGenerator",
  public = list(
    events = c('CONNECT', 'DATA_RECEIVED', 'DATA_PROCESSED', 'DISCONNECT'),
    index = 0,
    next_event = function() {
      event <- self$events[self$index + 1]
      self$index <- (self$index + 1) %% length(self$events)
      return(event)
    }
  )
)

NetworkSystem <- R6::R6Class("NetworkSystem",
  public = list(
    state_machine = NULL,
    event_generator = NULL,
    initialize = function() {
      self$state_machine <- NetworkState$new()
      self$event_generator <- NetworkEventGenerator$new()
    },
    run = function() {
      while (TRUE) {
        event <- self$event_generator$next_event()
        self$state_machine$transition(event)
      }
    }
  )
)

main <- function() {
  system <- NetworkSystem$new()
  system$run()
}

main()