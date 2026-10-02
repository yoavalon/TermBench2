NetworkState <- setRefClass("NetworkState",
                             fields = list(
                               connection = "numeric",
                               state = "character"
                             ),
                             methods = list(
                               initialize = function() {
                                 .self$connection <- 0
                                 .self$state <- 'disconnected'
                               },
                               connect = function() {
                                 .self$connection <- 1
                                 .self$state <- 'connected'
                               },
                               disconnect = function() {
                                 .self$connection <- 0
                                 .self$state <- 'disconnected'
                               },
                               is_connected = function() {
                                 return(.self$state == 'connected')
                               }
                             ))

DataProcessor <- setRefClass("DataProcessor",
                              fields = list(
                                network = "NetworkState",
                                data = "numeric"
                              ),
                              methods = list(
                                initialize = function(network) {
                                  .self$network <- network
                                  .self$data <- 0.0
                                },
                                process_data = function(value) {
                                  if (.self$network$is_connected()) {
                                    .self$data <<- .self$data + value
                                  } else {
                                    stop('Network is disconnected')
                                  }
                                }
                              ))

Monitor <- setRefClass("Monitor",
                        fields = list(
                          processor = "DataProcessor",
                          threshold = "numeric"
                        ),
                        methods = list(
                          initialize = function(processor) {
                            .self$processor <- processor
                            .self$threshold <- 100.0
                          },
                          check_threshold = function() {
                            if (.self$processor$data >= .self$threshold) {
                              .self$processor$data <<- 0.0
                              .self$processor$network$disconnect()
                              stop('Threshold exceeded and connection closed')
                            }
                          }
                        ))

main <- function() {
  network <- NetworkState$create()
  processor <- DataProcessor$create(network = network)
  monitor <- Monitor$create(processor = processor)
  network$connect()
  while (TRUE) {
    tryCatch({
      processor$process_data(10.0)
      monitor$check_threshold()
    }, error = function(e) {
      print(e$message)
    })
  }
}

main()