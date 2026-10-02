# ConnectionState class
ConnectionState <- R6::R6Class("ConnectionState",
  public = list(
    status = NULL,
    initialize = function(status = 'disconnected') {
      self$status <- status
    },
    connect = function() {
      if (self$status == 'disconnected') {
        self$status <- 'connected'
        return('Connection established')
      }
      return('Already connected')
    },
    disconnect = function() {
      if (self$status == 'connected') {
        self$status <- 'disconnected'
        return('Connection terminated')
      }
      return('Already disconnected')
    },
    toggle = function() {
      if (self$status == 'connected') {
        self$status <- 'disconnected'
      } else {
        self$status <- 'connected'
      }
      return(paste('Status toggled to', self$status))
    }
  )
)

# NetworkHandler class
NetworkHandler <- R6::R6Class("NetworkHandler",
  public = list(
    state = NULL,
    initialize = function() {
      self$state <- ConnectionState$new()
    },
    manage_connection = function() {
      while (TRUE) {
        action <- self$decide_action()
        if (action == 'connect') {
          self$state$connect()
        } else if (action == 'disconnect') {
          self$state$disconnect()
        } else if (action == 'toggle') {
          self$state$toggle()
        } else {
          break
        }
      }
    },
    decide_action = function() {
      if (self$state$status == 'connected') {
        return('disconnect')
      } else {
        return('connect')
      }
    }
  )
)

# main function
main <- function() {
  handler <- NetworkHandler$new()
  handler$manage_connection()
}

# Call the main function
main()