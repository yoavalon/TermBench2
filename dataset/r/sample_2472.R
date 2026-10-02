library(digest)

generate_hash_sequence <- function(n) {
    data <- 'initial_data'
    hashes <- c()
    for (i in 1:n) {
        data <- sha256(data)
        hashes <- c(hashes, data)
    }
    return(hashes)
}

main <- function() {
    result <- generate_hash_sequence(10)
    for (item in result) {
        print(item)
    }
}

main()