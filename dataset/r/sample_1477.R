ConnectionState <- R6::R6Class("ConnectionState",
  public = list(
    state = 'disconnected',
    connect = function() {
      if (self$state == 'disconnected') {
        self$state <- 'connected'
        return(TRUE)
      }
      return(FALSE)
    },
    disconnect = function() {
      if (self$state == 'connected') {
        self$state <- 'disconnected'
        return(TRUE)
      }
      return(FALSE)
    },
    is_connected = function() {
      return(self$state == 'connected')
    }
  )
)

NetworkManager <- R6::R6Class("NetworkManager",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    attempt_connection = function() {
      if (!self$state$is_connected()) {
        self$state$connect()
      } else {
        self$state$disconnect()
      }
    },
    monitor = function() {
      for (i in 1:10) {
        self$attempt_connection()
        if (self$state$is_connected()) {
          break
        }
      }
    }
  )
)

main <- function() {
  state <- ConnectionState$new()
  manager <- NetworkManager$new(state)
  manager$monitor()
}

main()