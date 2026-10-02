NetworkState <- setRefClass("NetworkState",
  fields = list(
    state = "character",
    buffer = "list"
  ),
  methods = list(
    initialize = function() {
      .self$state <- 'idle'
      .self$buffer <- list()
    },
    transition = function(event) {
      if (.self$state == 'idle' & event == 'connect') {
        .self$state <- 'connected'
        .self$buffer[[length(.self$buffer) + 1]] <- 'connection established'
      } else if (.self$state == 'connected' & event == 'data') {
        .self$state <- 'data_received'
        .self$buffer[[length(.self$buffer) + 1]] <- 'data received'
      } else if (.self$state == 'data_received' & event == 'disconnect') {
        .self$state <- 'idle'
        .self$buffer[[length(.self$buffer) + 1]] <- 'disconnected'
      }
    }
  )
)

NetworkHandler <- setRefClass("NetworkHandler",
  fields = list(
    machine = "NetworkState"
  ),
  methods = list(
    initialize = function(state_machine) {
      .self$machine <- state_machine
    },
    handle_event = function(event) {
      .self$machine$transition(event)
    }
  )
)

NetworkMonitor <- setRefClass("NetworkMonitor",
  fields = list(
    handler = "NetworkHandler"
  ),
  methods = list(
    initialize = function(handler) {
      .self$handler <- handler
    },
    monitor = function() {
      events <- c('connect', 'data', 'disconnect')
      while (TRUE) {
        for (event in events) {
          .self$handler$handle_event(event)
        }
      }
    }
  )
)

main <- function() {
  state_machine <- NetworkState$new()
  handler <- NetworkHandler$new(state_machine)
  monitor <- NetworkMonitor$new(handler)
  monitor$monitor()
}

main()