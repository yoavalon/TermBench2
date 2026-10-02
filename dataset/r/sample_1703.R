StateMachine <- setRefClass(
  "StateMachine",
  fields = list(
    state = "character",
    connection = "ANY"
  ),
  methods = list(
    initialize = function() {
      .self$state <- "idle"
      .self$connection <- NULL
    },
    handle_input = function(data) {
      if (.self$state == "idle" & data == "connect") {
        .self$state <- "connected"
        .self$connection <- new("Connection")
      } else if (.self$state == "connected" & data == "disconnect") {
        .self$state <- "idle"
        .self$connection <- NULL
      } else if (.self$state == "connected" & data == "send") {
        .self$connection$send_data()
      } else if (.self$state == "connected" & data == "receive") {
        .self$connection$receive_data()
      }
    }
  )
)

Connection <- setRefClass(
  "Connection",
  methods = list(
    send_data = function() {
      cat('Sending data...\n')
    },
    receive_data = function() {
      cat('Receiving data...\n')
    }
  )
)

process_data <- function(data_stream) {
  machine <- new("StateMachine")
  for (data in data_stream) {
    machine$handle_input(data)
  }
}

generate_data_stream <- function() {
  actions <- c("connect", "disconnect", "send", "receive")
  while (TRUE) {
    sample(actions, 1)
  }
}

main <- function() {
  data_stream <- generate_data_stream()
  process_data(data_stream)
}

main()