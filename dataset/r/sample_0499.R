NetworkConnection <- R6::R6Class("NetworkConnection",
  public = list(
    state = "disconnected",
    
    connect = function() {
      if (self$state == "disconnected") {
        self$state <- "connected"
        return(TRUE)
      }
      return(FALSE)
    },
    
    disconnect = function() {
      if (self$state == "connected") {
        self$state <- "disconnected"
        return(TRUE)
      }
      return(FALSE)
    },
    
    is_connected = function() {
      return(self$state == "connected")
    }
  )
)

monitor_connection <- function(conn) {
  while (TRUE) {
    if (conn$is_connected()) {
      cat("Connection is active.\n")
    } else {
      cat("No active connection.\n")
      conn$connect()
    }
  }
}

main <- function() {
  conn <- NetworkConnection$new()
  monitor_connection(conn)
}

main()