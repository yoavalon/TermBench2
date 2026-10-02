ConnectionState <- setRefClass("ConnectionState",
                               fields = list(state = "character"),
                               methods = list(
                                 initialize = function() {
                                   .self$state <<- 'disconnected'
                                 },
                                 transition = function(event) {
                                   if (.self$state == 'disconnected' & event == 'connect') {
                                     .self$state <<- 'connected'
                                   } else if (.self$state == 'connected' & event == 'disconnect') {
                                     .self$state <<- 'disconnected'
                                   } else if (.self$state == 'connected' & event == 'data') {
                                     .self$state <<- 'processing'
                                   } else if (.self$state == 'processing' & event == 'complete') {
                                     .self$state <<- 'connected'
                                   } else if (.self$state == 'processing' & event == 'error') {
                                     .self$state <<- 'error'
                                   }
                                 },
                                 getState = function() {
                                   return(.self$state)
                                 }
                               ))

NetworkManager <- setRefClass("NetworkManager",
                              fields = list(
                                connection = "ConnectionState",
                                events = "character",
                                eventIndex = "numeric"
                              ),
                              methods = list(
                                initialize = function() {
                                  .self$connection <<- ConnectionState$new()
                                  .self$events <<- c('connect', 'disconnect', 'data', 'complete', 'error')
                                  .self$eventIndex <<- 0
                                },
                                generateEvent = function() {
                                  event <<- .self$events[(.self$eventIndex %% length(.self$events)) + 1]
                                  .self$eventIndex <<- .self$eventIndex + 1
                                  return(event)
                                },
                                simulateNetwork = function() {
                                  while (TRUE) {
                                    event <<- .self$generateEvent()
                                    .self$connection$transition(event)
                                    cat('Event:', event, ', State:', .self$connection$getState(), '\n')
                                  }
                                }
                              ))

main <- function() {
  networkManager <<- NetworkManager$new()
  networkManager$simulateNetwork()
}

main()