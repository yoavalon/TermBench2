NetworkState <- R6::R6Class("NetworkState",
  public = list(
    state = 'DISCONNECTED',
    connection_attempts = 0,
    connect = function() {
      if (self$state == 'DISCONNECTED') {
        self$state <- 'CONNECTING'
        self$connection_attempts <- self$connection_attempts + 1
      }
    },
    check_status = function() {
      if (self$state == 'CONNECTING') {
        if (self$connection_attempts < 3) {
          self$state <- 'CONNECTED'
        } else {
          self$state <- 'FAILED'
        }
      }
    },
    disconnect = function() {
      if (self$state == 'CONNECTED') {
        self$state <- 'DISCONNECTING'
        self$connection_attempts <- 0
      }
    }
  )
)

NetworkManager <- R6::R6Class("NetworkManager",
  public = list(
    network_state = NULL,
    initialize = function() {
      self$network_state <- NetworkState$new()
    },
    manage_connection = function() {
      while (TRUE) {
        self$network_state$connect()
        self$network_state$check_status()
        if (self$network_state$state == 'FAILED') {
          break
        }
      }
    }
  )
)

main <- function() {
  manager <- NetworkManager$new()
  manager$manage_connection()
}

main()