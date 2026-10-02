crypto_hash <- function(data, depth) {
    if (depth == 0) {
        return(data)
    } else {
        return(crypto_hash(rev(unlist(strsplit(data, ""))), depth - 1))
    }
}

main <- function() {
    initial_data <- 'securedata'
    depth <- 5
    result <- crypto_hash(initial_data, depth)
    print(result)
}

main()