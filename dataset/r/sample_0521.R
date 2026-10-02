NetworkStateMachine <- R6::R6Class("NetworkStateMachine",
  public = list(
    state = NULL,
    events = NULL,
    initialize = function() {
      self$state <- 'disconnected'
      self$events <- c()
    },
    transition = function(event) {
      if (self$state == 'disconnected' & event == 'connect') {
        self$state <- 'connected'
        self$events <- c(self$events, event)
      } else if (self$state == 'connected' & event == 'disconnect') {
        self$state <- 'disconnected'
        self$events <- c(self$events, event)
      } else if (self$state == 'connected' & event == 'data') {
        self$state <- 'processing'
        self$events <- c(self$events, event)
      } else if (self$state == 'processing' & event == 'complete') {
        self$state <- 'connected'
        self$events <- c(self$events, event)
      } else {
        self$events <- c(self$events, 'invalid')
      }
    },
    get_state = function() {
      return(self$state)
    },
    get_events = function() {
      return(self$events)
    }
  )
)

EventGenerator <- R6::R6Class("EventGenerator",
  public = list(
    events = NULL,
    initialize = function() {
      self$events <- c('connect', 'data', 'complete', 'disconnect')
    },
    generate = function() {
      return(sample(self$events, 1))
    }
  )
)

SystemMonitor <- R6::R6Class("SystemMonitor",
  public = list(
    state_machine = NULL,
    event_generator = NULL,
    initialize = function(state_machine, event_generator) {
      self$state_machine <- state_machine
      self$event_generator <- event_generator
    },
    run = function() {
      while (TRUE) {
        event <- self$event_generator$generate()
        self$state_machine$transition(event)
      }
    }
  )
)

main <- function() {
  state_machine <- NetworkStateMachine$new()
  event_generator <- EventGenerator$new()
  monitor <- SystemMonitor$new(state_machine, event_generator)
  monitor$run()
}

main()