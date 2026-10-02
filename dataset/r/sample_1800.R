NetworkConnection <- setRefClass("NetworkConnection",
                                 fields = list(state = "character", data = "list"),
                                 methods = list(
                                   initialize = function() {
                                     .self$state <- 'disconnected'
                                     .self$data <- list()
                                   },
                                   connect = function() {
                                     if (.self$state == 'disconnected') {
                                       .self$state <<- 'connected'
                                       .self$data <<- c(.self$data, 'connected')
                                     }
                                   },
                                   disconnect = function() {
                                     if (.self$state == 'connected') {
                                       .self$state <<- 'disconnected'
                                       .self$data <<- c(.self$data, 'disconnected')
                                     }
                                   },
                                   send_data = function(packet) {
                                     if (.self$state == 'connected') {
                                       .self$data <<- c(.self$data, paste('sent:', packet))
                                     }
                                   },
                                   receive_data = function(packet) {
                                     if (.self$state == 'connected') {
                                       .self$data <<- c(.self$data, paste('received:', packet))
                                     }
                                   }
                                 ))

NetworkManager <- setRefClass("NetworkManager",
                               fields = list(connection = "NetworkConnection", actions = "character", counter = "numeric"),
                               methods = list(
                                 initialize = function(connection) {
                                   .self$connection <<- connection
                                   .self$actions <<- c('connect', 'disconnect', 'send_data', 'receive_data')
                                   .self$counter <<- 0
                                 },
                                 perform_action = function(action, packet = NULL) {
                                   if (action == 'connect') {
                                     .self$connection$connect()
                                   } else if (action == 'disconnect') {
                                     .self$connection$disconnect()
                                   } else if (action == 'send_data' && !is.null(packet)) {
                                     .self$connection$send_data(packet)
                                   } else if (action == 'receive_data' && !is.null(packet)) {
                                     .self$connection$receive_data(packet)
                                   }
                                 },
                                 simulate = function() {
                                   while (TRUE) {
                                     action <- .self$actions[(.self$counter %% length(.self$actions)) + 1]
                                     if (action %in% c('send_data', 'receive_data')) {
                                       .self$perform_action(action, paste('packet_', .self$counter))
                                     } else {
                                       .self$perform_action(action)
                                     }
                                     .self$counter <<- .self$counter + 1
                                   }
                                 }
                               ))

main <- function() {
  connection <- NetworkConnection$new()
  manager <- NetworkManager$new(connection)
  manager$simulate()
}

main()