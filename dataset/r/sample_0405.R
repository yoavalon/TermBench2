library(stringr)

process_data <- function(data) {
    result <- list()
    for (item in data) {
        processed <- vectorize(item)
        result <- append(result, list(processed))
    }
    return(result)
}

vectorize <- function(text) {
    vector <- unlist(lapply(strsplit(text, NULL)[[1]], function(x) as.integer(charToRaw(x))))
    return(vector)
}

main <- function() {
    data <- c('hello', 'world')
    while (TRUE) {
        processed_data <- process_data(data)
        print(processed_data)
    }
}

main()