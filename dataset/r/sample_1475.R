StateMachine <- setRefClass("StateMachine",
  fields = list(
    state = "character",
    connection = "character"
  ),
  methods = list(
    initialize = function() {
      .self$state <- 'idle'
      .self$connection <- NULL
    },
    transition = function(event) {
      if (.self$state == 'idle' & event == 'connect') {
        .self$state <- 'connected'
        .self$connection <- 'active'
      } else if (.self$state == 'connected' & event == 'disconnect') {
        .self$state <- 'idle'
        .self$connection <- NULL
      } else if (.self$state == 'connected' & event == 'data') {
        .self$state <- 'processing'
      } else if (.self$state == 'processing' & event == 'complete') {
        .self$state <- 'connected'
      } else if (.self$state == 'connected' & event == 'error') {
        .self$state <- 'error'
        .self$connection <- NULL
      } else if (.self$state == 'error' & event == 'reset') {
        .self$state <- 'idle'
      }
    }
  )
)

EventGenerator <- setRefClass("EventGenerator",
  fields = list(
    events = "character",
    index = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$events <- c('connect', 'disconnect', 'data', 'complete', 'error', 'reset')
      .self$index <- 1
    },
    generate = function() {
      event <- .self$events[.self$index]
      .self$index <- (.self$index %% length(.self$events)) + 1
      return(event)
    }
  )
)

main <- function() {
  machine <- new(StateMachine)
  generator <- new(EventGenerator)
  for (i in 1:20) {
    event <- generator$generate()
    machine$transition(event)
    cat('Event:', event, ', State:', machine$state, ', Connection:', machine$connection, '\n')
  }
}

main()