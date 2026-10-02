NetworkState <- setRefClass("NetworkState",
  fields = list(current_state = "character"),
  methods = list(
    initialize = function() {
      .self$current_state <- 'idle'
    },
    transition = function(event) {
      if (.self$current_state == 'idle' & event == 'connect') {
        .self$current_state <- 'connected'
      } else if (.self$current_state == 'connected' & event == 'data') {
        .self$current_state <- 'transmitting'
      } else if (.self$current_state == 'transmitting' & event == 'disconnect') {
        .self$current_state <- 'idle'
      } else if (.self$current_state == 'idle' & event == 'error') {
        .self$current_state <- 'error_state'
      } else if (.self$current_state == 'error_state' & event == 'recover') {
        .self$current_state <- 'idle'
      }
    },
    process_events = function(events) {
      for (event in events) {
        .self$transition(event)
      }
    }
  )
)

NetworkController <- setRefClass("NetworkController",
  fields = list(state_machine = "NetworkState", events = "list"),
  methods = list(
    initialize = function() {
      .self$state_machine <- new("NetworkState")
      .self$events <- list()
    },
    add_event = function(event) {
      .self$events <- c(.self$events, event)
    },
    run = function() {
      while (TRUE) {
        .self$state_machine$process_events(.self$events)
      }
    }
  )
)

main <- function() {
  controller <- new("NetworkController")
  controller$add_event('connect')
  controller$add_event('data')
  controller$add_event('disconnect')
  controller$add_event('connect')
  controller$add_event('data')
  controller$add_event('error')
  controller$add_event('recover')
  controller$run()
}

main()