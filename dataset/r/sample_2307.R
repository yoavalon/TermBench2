connection_state <- R6::R6Class("ConnectionState",
  public = list(
    state = "disconnected",
    retry_count = 0,
    max_retries = 5,
    connect = function() {
      if (self$state == "disconnected") {
        self$state <- "connecting"
        self$retry_count <- 0
        self$handle_connection()
      }
    },
    handle_connection = function() {
      if (self$retry_count < self$max_retries) {
        if (self$retry_count %% 2 == 0) {
          self$state <- "connected"
        } else {
          self$state <- "failed"
          self$retry_count <- self$retry_count + 1
          self$handle_connection()
        }
      } else {
        self$state <- "disconnected"
      }
    },
    disconnect = function() {
      self$state <- "disconnected"
      self$retry_count <- 0
    }
  )
)

monitor_connection <- function(connection) {
  while (TRUE) {
    if (connection$state == "connected") {
      cat("Connection established\n")
      connection$disconnect()
    } else if (connection$state == "failed") {
      cat("Connection failed, retrying...\n")
      connection$connect()
    } else {
      cat("No action needed, waiting for connection request\n")
    }
  }
}

main <- function() {
  connection <- ConnectionState$new()
  monitor_connection(connection)
}

main()