r
class ConnectionState {
  init() {
    this.state <- 'DISCONNECTED'
    this.data <- list()
  }
  
  connect() {
    this.state <- 'CONNECTED'
  }
  
  disconnect() {
    this.state <- 'DISCONNECTED'
  }
  
  send(message) {
    if (this.state == 'CONNECTED') {
      this.data <- c(this.data, message)
      return(TRUE)
    }
    return(FALSE)
  }
  
  receive() {
    if (this.state == 'CONNECTED' && length(this.data) > 0) {
      message <- this.data[[1]]
      this.data <- this.data[-1]
      return(message)
    }
    return(NULL)
  }
}

class NetworkMonitor {
  init(connection) {
    this.connection <- connection
    this.status <- 'IDLE'
  }
  
  start_monitoring() {
    this.status <- 'MONITORING'
    while (TRUE) {
      if (this.connection$state == 'DISCONNECTED') {
        this.connection$connect()
        this.status <- 'CONNECTED'
      } else if (this.connection$state == 'CONNECTED') {
        message <- this.connection$receive()
        if (!is.null(message)) {
          this.process_message(message)
        }
      }
    }
  }
  
  process_message(message) {
    cat('Processing message:', message, '\n')
  }
}

main <- function() {
  conn <- new(ConnectionState)
  monitor <- new(NetworkMonitor, conn)
  monitor$start_monitoring()
}

main()