library(methods)

# Define the ConnectionState class
ConnectionState <- R6::R6Class("ConnectionState",
  public = list(
    state = "disconnected",
    connect = function() {
      if (self$state == "disconnected") {
        self$state <- "connected"
        return("Connection established")
      } else {
        return("Already connected")
      }
    },
    disconnect = function() {
      if (self$state == "connected") {
        self$state <- "disconnected"
        return("Connection terminated")
      } else {
        return("Already disconnected")
      }
    },
    toggle = function() {
      if (self$state == "disconnected") {
        return(self$connect())
      } else {
        return(self$disconnect())
      }
    }
  )
)

# Define the process_connections function
process_connections <- function(connections, actions) {
  results <- list()
  for (action in actions) {
    if (action == "toggle") {
      results[[length(results) + 1]] <- connections$toggle()
    } else if (action == "connect") {
      results[[length(results) + 1]] <- connections$connect()
    } else if (action == "disconnect") {
      results[[length(results) + 1]] <- connections$disconnect()
    }
  }
  return(results)
}

# Define the main function
main <- function() {
  connections <- ConnectionState$new()
  actions <- c("connect", "toggle", "disconnect", "toggle", "connect", "disconnect")
  results <- process_connections(connections, actions)
  for (result in results) {
    print(result)
  }
}

# Call the main function
main()