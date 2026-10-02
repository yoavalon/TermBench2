NetworkStateMachine <- R6::R6Class("NetworkStateMachine",
  public = list(
    state = "disconnected",
    data = list(),
    transition = function(event) {
      if (self$state == "disconnected" && event == "connect") {
        self$state <- "connected"
      } else if (self$state == "connected" && event == "send") {
        self$data <- c(self$data, "data")
      } else if (self$state == "connected" && event == "disconnect") {
        self$state <- "disconnected"
        self$data <- list()
      }
    },
    process_events = function(events) {
      for (event in events) {
        self$transition(event)
      }
    },
    get_status = function() {
      return(list(self$state, self$data))
    }
  )
)

generate_events <- function(count) {
  events <- vector("character", count)
  for (i in 1:count) {
    r <- runif(1)
    if (r < 0.3) {
      events[i] <- "connect"
    } else if (r < 0.5) {
      events[i] <- "send"
    } else {
      events[i] <- "disconnect"
    }
  }
  return(events)
}

main <- function() {
  state_machine <- NetworkStateMachine$new()
  events <- generate_events(100)
  state_machine$process_events(events)
  final_status <- state_machine$get_status()
  cat(final_status[[1]], "\n")
  print(final_status[[2]])
}

main()