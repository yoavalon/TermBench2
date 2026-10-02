simulate_temperature_change <- function(initial_temp, rate, steps) {
    data <- numeric(steps)
    for (i in 1:steps) {
        data[i] <- initial_temp + (i - 1) * rate
    }
    return(data)
}

analyze_data <- function(data, threshold) {
    return(which(data > threshold))
}

main <- function() {
    initial_temp <- 300.0
    rate <- 0.1
    steps <- 1000
    threshold <- 350.0
    data <- simulate_temperature_change(initial_temp, rate, steps)
    indices <- analyze_data(data, threshold)
    print(indices)
}

main()