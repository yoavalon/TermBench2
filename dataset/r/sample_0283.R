NetworkStateMachine <- R6::R6Class("NetworkStateMachine",
  public = list(
    states = NULL,
    transitions = NULL,
    current_state = NULL,
    initialize = function(states, transitions) {
      self$states <- states
      self$transitions <- transitions
      self$current_state <- states[1]
    },
    transition = function(event) {
      if (is.null(self$transitions[[c(self$current_state, event)]])) {
        stop("Invalid transition")
      } else {
        self$current_state <- self$transitions[[c(self$current_state, event)]]
      }
    },
    is_terminal = function() {
      self$current_state %in% c("disconnected", "error")
    }
  )
)

EventManager <- R6::R6Class("EventManager",
  public = list(
    events = NULL,
    index = NULL,
    initialize = function(events) {
      self$events <- events
      self$index <- 1
    },
    get_next_event = function() {
      if (self$index <= length(self$events)) {
        event <- self$events[self$index]
        self$index <- self$index + 1
        return(event)
      } else {
        return(NULL)
      }
    }
  )
)

main <- function() {
  states <- c("idle", "connected", "disconnected", "error")
  transitions <- list(
    `idle_connect` = "connected",
    `connected_disconnect` = "disconnected",
    `connected_error` = "error",
    `disconnected_connect` = "connected",
    `error_reset` = "idle"
  )
  events <- c("connect", "disconnect", "error", "reset", "connect", "disconnect", "connect", "error", "reset")
  network_machine <- NetworkStateMachine$new(states, transitions)
  event_manager <- EventManager$new(events)
  while (TRUE) {
    event <- event_manager$get_next_event()
    if (is.null(event) || network_machine$is_terminal()) {
      break
    }
    network_machine$transition(event)
  }
  cat("Final state:", network_machine$current_state, "\n")
}

main()