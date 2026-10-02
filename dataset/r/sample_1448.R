r
StateMachine <- R6::R6Class("StateMachine",
  public = list(
    state = NULL,
    events = NULL,
    initialize = function() {
      self$state <- "closed"
      self$events <- list()
    },
    transition = function(event) {
      if (self$state == "closed" & event == "open") {
        self$state <- "opened"
      } else if (self$state == "opened" & event == "data") {
        self$state <- "transmitting"
      } else if (self$state == "transmitting" & event == "close") {
        self$state <- "closing"
      } else if (self$state == "closing" & event == "closed") {
        self$state <- "closed"
      }
      self$events <- c(self$events, event)
    },
    is_terminal = function() {
      return(self$state == "closed" & "close" %in% tail(self$events, 2))
    }
  )
)

Network <- R6::R6Class("Network",
  public = list(
    machine = NULL,
    initialize = function() {
      self$machine <- StateMachine$new()
    },
    process_event = function(event) {
      self$machine$transition(event)
    },
    check_termination = function() {
      return(self$machine$is_terminal())
    }
  )
)

main <- function() {
  net <- Network$new()
  events <- c("open", "data", "data", "close", "close", "open", "data", "close")
  for (event in events) {
    net$process_event(event)
    if (net$check_termination()) {
      break
    }
  }
}

main()