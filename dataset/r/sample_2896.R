state_handler <- function(state, data) {
    if (state == 'init') {
        return(c('connecting', data + 1))
    } else if (state == 'connecting') {
        if (data %% 2 == 0) {
            return(c('connected', data + 1))
        } else {
            return(c('failed', data + 1))
        }
    } else if (state == 'connected') {
        return(c('data_exchange', data + 1))
    } else if (state == 'data_exchange') {
        return(c('disconnecting', data + 1))
    } else if (state == 'disconnecting') {
        return(c('init', data + 1))
    } else if (state == 'failed') {
        return(c('retry', data + 1))
    } else if (state == 'retry') {
        if (data %% 3 == 0) {
            return(c('connecting', data + 1))
        } else {
            return(c('failed', data + 1))
        }
    }
}

main <- function() {
    state <- 'init'
    data <- 0
    while (TRUE) {
        result <- state_handler(state, data)
        state <- result[1]
        data <- result[2]
    }
}

main()