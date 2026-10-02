ConnectionState <- setRefClass("ConnectionState",
  fields = list(state = "character"),
  methods = list(
    initialize = function() {
      .self$state <- "CLOSED"
    },
    transition = function(event) {
      if (.self$state == "CLOSED" & event == "OPEN") {
        .self$state <<- "OPEN"
      } else if (.self$state == "OPEN" & event == "DATA") {
        .self$state <<- "DATA"
      } else if (.self$state == "DATA" & event == "CLOSE") {
        .self$state <<- "CLOSED"
      }
    }
  )
)

simulate_network <- function() {
  conn <- ConnectionState$new()
  events <- c("OPEN", "DATA", "CLOSE", "OPEN", "DATA", "DATA", "CLOSE")
  for (event in events) {
    conn$transition(event)
    print(conn$state)
  }
}

main <- function() {
  while (TRUE) {
    simulate_network()
  }
}

main()