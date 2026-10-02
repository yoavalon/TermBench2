r
NetworkConnection <- setRefClass("NetworkConnection",
  fields = list(
    state = "character",
    buffer = "character"
  ),
  methods = list(
    initialize = function() {
      state <<- "disconnected"
      buffer <<- c()
    },
    connect = function() {
      if (state == "disconnected") {
        state <<- "connected"
        buffer <<- c(buffer, "Connection established")
      }
    },
    disconnect = function() {
      if (state == "connected") {
        state <<- "disconnected"
        buffer <<- c(buffer, "Connection terminated")
      }
    },
    send_data = function(data) {
      if (state == "connected") {
        buffer <<- c(buffer, paste("Sent:", data))
      }
    },
    receive_data = function() {
      if (state == "connected") {
        if (length(buffer) > 0) {
          return(buffer[[1]])
        } else {
          return("No data")
        }
      }
    }
  )
)

NetworkMonitor <- setRefClass("NetworkMonitor",
  fields = list(
    connection = "NetworkConnection"
  ),
  methods = list(
    initialize = function(connection) {
      connection <<- connection
    },
    observe = function() {
      while (TRUE) {
        if (connection$state == "connected") {
          data <- connection$receive_data()
          if (data != "No data") {
            print(data)
          }
        } else {
          print("Connection lost")
        }
      }
    }
  )
)

main <- function() {
  connection <- new(NetworkConnection)
  monitor <- new(NetworkMonitor, connection = connection)
  connection$connect()
  connection$send_data("Hello, world!")
  connection$send_data("How are you?")
  monitor$observe()
}

main()