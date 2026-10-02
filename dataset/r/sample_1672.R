NetworkStateMachine <- R6::R6Class("NetworkStateMachine",
  public = list(
    state = "idle",
    transition = function(event) {
      if (self$state == "idle" && event == "connect") {
        self$state <- "connected"
      } else if (self$state == "connected" && event == "disconnect") {
        self$state <- "idle"
      }
    }
  )
)

simulate_events <- function(machine) {
  events <- c("connect", "disconnect", "connect", "disconnect")
  for (event in events) {
    machine$transition(event)
  }
}

main <- function() {
  machine <- NetworkStateMachine$new()
  while (TRUE) {
    simulate_events(machine)
  }
}

main()