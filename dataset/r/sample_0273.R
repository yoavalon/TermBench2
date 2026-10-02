NetworkConnection <- setRefClass("NetworkConnection",
  fields = list(state = "character"),
  methods = list(
    initialize = function(.self, state = 'disconnected') {
      .self$state <- state
    },
    connect = function() {
      if (.self$state == 'disconnected') {
        .self$state <<- 'connecting'
      } else if (.self$state == 'connected') {
        cat('Already connected.\n')
      } else {
        .self$state <<- 'reconnecting'
      }
    },
    disconnect = function() {
      if (.self$state %in% c('connected', 'reconnecting')) {
        .self$state <<- 'disconnecting'
      } else if (.self$state == 'disconnected') {
        cat('Already disconnected.\n')
      } else {
        .self$state <<- 'disconnected'
      }
    },
    transition = function() {
      if (.self$state == 'connecting') {
        .self$state <<- 'connected'
      } else if (.self$state == 'reconnecting') {
        .self$state <<- 'connected'
      } else if (.self$state == 'disconnecting') {
        .self$state <<- 'disconnected'
      } else {
        .self$state <<- 'disconnected'
      }
    }
  )
)

manage_connection <- function(connection, actions) {
  for (action in actions) {
    if (action == 'connect') {
      connection$connect()
    } else if (action == 'disconnect') {
      connection$disconnect()
    }
    connection$transition()
  }
}

main <- function() {
  actions <- c('connect', 'disconnect', 'connect', 'connect', 'disconnect', 'disconnect')
  connection <- NetworkConnection$new()
  manage_connection(connection, actions)
}

main()